#include <cstdlib>
#include <iostream>

#include "mygl/shader.h"
#include "mygl/mesh.h"
#include "mygl/geometry.h"
#include "mygl/camera.h"
#include "TransformsAndColors.h" // moved definition of various objects to new Header File
#include <flag.h>

enum CameraMode {
    STATIC,
    THIRD_PERSON
};

/* struct holding all necessary state variables for scene */
struct
{
    /* camera */
    Camera camera1;  // Main camera
    Camera camera2;  // Third-person camera
    Camera* activeCamera;  // Pointer to currently active camera
    CameraMode cameraMode = STATIC; // Added CameraMode for switching between centered camera and Plane-perspective camera (3rd person)
    float zoomSpeedMultiplier;

    /* cube mesh and transformations */
    Mesh cubeMesh;
    Matrix4D cubeScalingMatrix;
    Matrix4D cubeTranslationMatrix;
    Matrix4D cubeTransformationMatrix;
    float cubeSpinRadPerSecond;

    /* Flag */
    FlagSim flagSim;
    Flag flag;
    Matrix4D flagModelMatrix;

    /* shader */
    ShaderProgram shaderColor;

    // Adding meshes and transformation matrices for the protrusions
    Mesh protrusionXMesh;
    Mesh protrusionNOTXMesh;
    Mesh protrusionYMesh;
    Mesh protrusionNOTYMesh;
    Mesh protrusionZMesh;
    Mesh protrusionNOTZMesh;

    Matrix4D protrusionXMatrix;
    Matrix4D protrusionNOTXMatrix;
    Matrix4D protrusionYMatrix;
    Matrix4D protrusionNOTYMatrix;
    Matrix4D protrusionZMatrix;
    Matrix4D protrusionNOTZMatrix;

    // Meshes for plane parts
    Mesh bodyMesh;
    Mesh cockpitMesh;
    Mesh wingMesh;
    Mesh tailWingMesh;
    Mesh rudderMesh;
    Mesh propellerMesh;
    Mesh poleMesh;

    // Transformation matrices for plane parts
    Matrix4D bodyMatrix;
    Matrix4D cockpitMatrix;
    Matrix4D wingMatrix;
    Matrix4D tailWingMatrix;
    Matrix4D rudderMatrix;
    Matrix4D propellerMatrix;
    Matrix4D poleMatrix;

    Matrix4D planeTransformationMatrix = Matrix4D::identity();
    Vector3D planePosition;

    // Plane Steering angles
    float pitchAngle;
    float rollAngle;
    float yawAngle;

    float propellerRotationAngle = 0.0f;

    // Variables for the plane orbit
    float planeOrbitAngle = 0.0f;        // Current orbit angle
    float planeOrbitSpeed = 0.2f;        // Orbital speed (radians per second)
    float planeOrbitRadius = 14.0f;      // Orbital radius

    Vector3D orbitCenter = Vector3D(0.0f, 0.0f, 0.0f);
} sScene;

/* struct holding all state variables for input */
struct
{
    bool mouseLeftButtonPressed = false;
    Vector2D mousePressStart;
    bool keyPressed[8] = {false, false, false, false, false, false, false, false};
} sInput;

// Added function to extract Coordinates from the transformation matrix (row-major matrix form)
Vector3D extractPosition(const Matrix4D& matrix) {
    return Vector3D(matrix[3][0], matrix[3][1], matrix[3][2]);
}

/* GLFW callback function for keyboard events */
void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    /* close window on escape */
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }

    /* make screenshot and save in work directory */
    if (key == GLFW_KEY_P && action == GLFW_PRESS)
    {
        screenshotToPNG("screenshot.png");
    }

    /// Input for Steering
    if (key == GLFW_KEY_W) // acceleration
    {
        sInput.keyPressed[0] = (action == GLFW_PRESS || action == GLFW_REPEAT);
    }
    if (key == GLFW_KEY_S) // deceleration
    {
        sInput.keyPressed[1] = (action == GLFW_PRESS || action == GLFW_REPEAT);
    }
    if (key == GLFW_KEY_A) // left turn: combination of yaw (rotation aroung y-axis) and roll (rotation around x-axis)
    {
        sInput.keyPressed[2] = (action == GLFW_PRESS || action == GLFW_REPEAT);
    }
    if (key == GLFW_KEY_D) // right turn: combination of yaw (rotation aroung y-axis) and roll (rotation around x-axis)
    {
        sInput.keyPressed[3] = (action == GLFW_PRESS || action == GLFW_REPEAT);
    }
    if (key == GLFW_KEY_LEFT_CONTROL) {
        sInput.keyPressed[6] = (action == GLFW_PRESS || action == GLFW_REPEAT);
    }
    if (key == GLFW_KEY_SPACE) {
        sInput.keyPressed[7] = (action == GLFW_PRESS || action == GLFW_REPEAT);
    }

    // Input for Camera-Mode:
    if (key == GLFW_KEY_1) {
        sInput.keyPressed[4] = (action == GLFW_PRESS || action == GLFW_REPEAT);
        sScene.cameraMode = STATIC;
        sScene.activeCamera = &sScene.camera1;
    }
    if (key == GLFW_KEY_2) {
        sInput.keyPressed[5] = (action == GLFW_PRESS);
        if (action == GLFW_PRESS) {
            sScene.cameraMode = THIRD_PERSON;
            sScene.activeCamera = &sScene.camera2;
        }
    }

}

/* GLFW callback function for mouse position events */
void mousePosCallback(GLFWwindow *window, double x, double y)
{
    /* called on cursor position change */
    if (sInput.mouseLeftButtonPressed)
    {
        Vector2D diff = sInput.mousePressStart - Vector2D(static_cast<float>(x), static_cast<float>(y));
        cameraUpdateOrbit(*sScene.activeCamera, diff, 0.0f);
        sInput.mousePressStart = Vector2D(static_cast<float>(x), static_cast<float>(y));
    }
}

/* GLFW callback function for mouse button events */
void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT)
    {
        sInput.mouseLeftButtonPressed = (action == GLFW_PRESS || action == GLFW_REPEAT);

        double x, y;
        glfwGetCursorPos(window, &x, &y);
        sInput.mousePressStart = Vector2D(static_cast<float>(x), static_cast<float>(y));
    }
}

/* GLFW callback function for mouse scroll events */
void mouseScrollCallback(GLFWwindow *window, double xoffset, double yoffset)
{
    cameraUpdateOrbit(*sScene.activeCamera, {0, 0}, -sScene.zoomSpeedMultiplier * static_cast<float>(yoffset));
}

/* GLFW callback function for window resize event */
void windowResizeCallback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
    (*sScene.activeCamera).width = static_cast<float>(width);
    (*sScene.activeCamera).height = static_cast<float>(height);
}

/* function to set up and initialize the whole scene */
void sceneInit(float width, float height)
{
    /* initialize camera */
    sScene.camera1 = cameraCreate(width, height, BASE_FOV, 0.01f, 500.0f, {10.0f, 10.0f, 30.0f}, {0.0f, 0.0f, 0.0f});
    Vector3D planeStartPosition = extractPosition(sScene.planeTransformationMatrix);
    Vector3D cameraOffset = {planeStartPosition.x, planeStartPosition.y + 10.0f, planeStartPosition.z - 5.0f};
    // Adding offset to the InitPos based on planeStartPosition to achieve 3rd-person view
    sScene.camera2 = cameraCreate(width, height, BASE_FOV,0.01f, 500.0f, planeStartPosition + cameraOffset, planeStartPosition);
    sScene.activeCamera = &sScene.camera1;
    sScene.zoomSpeedMultiplier = 0.05f;

    /* setup objects in scene and create opengl buffers for meshes */
    sScene.cubeMesh = meshCreate(cube::vertexPos, cube::indices, scaledCube::color, GL_STATIC_DRAW, GL_STATIC_DRAW);
    sScene.flag = flagCreate(flagPlane::color);

    // Create meshes for protrusions
    sScene.protrusionXMesh = meshCreate(cube::vertexPos, cube::indices, protrusionX::color, GL_STATIC_DRAW, GL_STATIC_DRAW);
    sScene.protrusionNOTXMesh = meshCreate(cube::vertexPos, cube::indices, protrusionNOTX::color, GL_STATIC_DRAW, GL_STATIC_DRAW);
    sScene.protrusionYMesh = meshCreate(cube::vertexPos, cube::indices, protrusionY::color, GL_STATIC_DRAW, GL_STATIC_DRAW);
    sScene.protrusionNOTYMesh = meshCreate(cube::vertexPos, cube::indices, protrusionNOTY::color, GL_STATIC_DRAW, GL_STATIC_DRAW);
    sScene.protrusionZMesh = meshCreate(cube::vertexPos, cube::indices, protrusionZ::color, GL_STATIC_DRAW, GL_STATIC_DRAW);
    sScene.protrusionNOTZMesh = meshCreate(cube::vertexPos, cube::indices, protrusionNOTZ::color, GL_STATIC_DRAW, GL_STATIC_DRAW);

    // Set up transformation matrices for protrusions
    sScene.protrusionXMatrix = protrusionX::trans * protrusionX::scale;
    sScene.protrusionNOTXMatrix = protrusionNOTX::trans * protrusionNOTX::scale;
    sScene.protrusionYMatrix = protrusionY::trans * protrusionY::scale;
    sScene.protrusionNOTYMatrix = protrusionNOTY::trans * protrusionNOTY::scale;
    sScene.protrusionZMatrix = protrusionZ::trans * protrusionZ::scale;
    sScene.protrusionNOTZMatrix = protrusionNOTZ::trans * protrusionNOTZ::scale;

     // Create meshes for plane parts
    sScene.bodyMesh = meshCreate(cube::vertexPos, cube::indices, planeBody::color, GL_STATIC_DRAW, GL_STATIC_DRAW);
    sScene.cockpitMesh = meshCreate(cube::vertexPos, cube::indices, planeCockpit::color, GL_STATIC_DRAW, GL_STATIC_DRAW);
    sScene.wingMesh = meshCreate(cube::vertexPos, cube::indices, planeWing::color, GL_STATIC_DRAW, GL_STATIC_DRAW);
    sScene.tailWingMesh = meshCreate(cube::vertexPos, cube::indices, planeTailWing::color, GL_STATIC_DRAW, GL_STATIC_DRAW);
    sScene.rudderMesh = meshCreate(cube::vertexPos, cube::indices, planeRudder::color, GL_STATIC_DRAW, GL_STATIC_DRAW);
    sScene.propellerMesh = meshCreate(cube::vertexPos, cube::indices, planePropeller::color, GL_STATIC_DRAW, GL_STATIC_DRAW);
    sScene.poleMesh = meshCreate(cube::vertexPos, cube::indices, planePole::color, GL_STATIC_DRAW, GL_STATIC_DRAW);

    // Set up transformation matrices
    sScene.bodyMatrix = planeBody::trans * planeBody::scale;
    sScene.cockpitMatrix = planeCockpit::trans * planeCockpit::scale;
    sScene.wingMatrix = planeWing::trans * planeWing::scale;
    sScene.tailWingMatrix = planeTailWing::trans * planeTailWing::scale;
    sScene.rudderMatrix = planeRudder::trans * planeRudder::rot * planeRudder::scale;
    sScene.propellerMatrix = planePropeller::trans * planePropeller::scale;
    sScene.poleMatrix = planePole::trans * planePole::rot * planePole::scale;

    /* setup transformation matrices for objects */
    sScene.flagModelMatrix = Matrix4D::translation(Vector3D(0.0f, 0.0f, 0.0f)) * Matrix4D::rotationY(static_cast<float>(M_PI) / 4) /** flagPlane::flagScale*/; // Rotate flag 45 degrees

    sScene.cubeScalingMatrix = scaledCube::scale;
    sScene.cubeTranslationMatrix = scaledCube::trans;

    sScene.cubeTransformationMatrix = Matrix4D::identity();

    sScene.cubeSpinRadPerSecond = static_cast<float>(M_PI) / 2.0f;

    /* load shader from file */
    sScene.shaderColor = shaderLoad("shader/default.vert", "shader/default.frag");
}

Matrix4D lookAt(const Vector3D& eye, const Vector3D& target, const Vector3D& up) {
    Vector3D z = normalize(eye - target); // Forward vector
    Vector3D x = normalize(cross(up, z)); // Right vector
    Vector3D y = normalize(cross(z, x)); // Up vector

    // Create a view matrix
    Matrix4D view = Matrix4D(
        x.x, x.y, x.z, -dot(x, eye),
        y.x, y.y, y.z, -dot(y, eye),
        z.x, z.y, z.z, -dot(z, eye),
        0, 0, 0, 1
    );

    return view;
}

void steeringHelperFunction(float dt, float rollSpeed, float pitchSpeed, float yawSpeed)
{
    // Acceleration
    if (sInput.keyPressed[0]) { // w - Increase speed
        sScene.planeOrbitSpeed += 0.01f;
        // sInput.keyPressed[0] = false; // acceleration works less smooth and a bit delayed if keyPressed-field is set to false again
    }
    if (sInput.keyPressed[1]) { // s - Decrease speed
        sScene.planeOrbitSpeed = std::max(0.1f, sScene.planeOrbitSpeed - 0.02f); // keep a minimum orbital speed!
        // sInput.keyPressed[1] = false;
    }

    // Steering: Taking the difference of the keyPressed boolean entries, leading to 0 or 1, implements an effective change in motion
    float rollChange = (sInput.keyPressed[3] - sInput.keyPressed[2]) * rollSpeed * dt; // Left/Right roll 'a' 'd'; combining roll & yaw movements
    float yawChange = (sInput.keyPressed[3] - sInput.keyPressed[2]) * yawSpeed * dt;

    float pitchChange = (sInput.keyPressed[7] - sInput.keyPressed[6]) * pitchSpeed * dt; // Up/Down pitch 'CONTROL_LEFT' or 'SPACE'

    sScene.pitchAngle += pitchChange;
    sScene.rollAngle += rollChange;
    sScene.yawAngle += yawChange;
}

void updatePlanePosition(float dt)
{
    /* Yaw = Rotation around the y-axis
    *  Pitch = Rotation around x-Axis
    *  Roll = Rotation around z-axis */
    Matrix4D rotationMatrix = Matrix4D::rotationX(sScene.pitchAngle) * Matrix4D::rotationY(sScene.yawAngle) * Matrix4D::rotationZ(sScene.rollAngle);

    // Forward direction in local space (initial forward along z-axis?) -> Critical Point of plane motion
    Vector3D forwardDirection = rotationMatrix * sScene.planeOrbitAngle;

    // Updates plane position based on forward direction and speed
    sScene.planePosition += forwardDirection * sScene.planeOrbitSpeed * dt;

    // Update the plane's orbital angle and position
    sScene.planeOrbitAngle += sScene.planeOrbitSpeed * dt;
    if (sScene.planeOrbitAngle > 2.0f * M_PI) { // Ensure the angle stays within 0 to 2π
        sScene.planeOrbitAngle -= 2.0f * M_PI;
    }
    sScene.planePosition.x = sScene.orbitCenter.x + sScene.planeOrbitRadius * cos(sScene.planeOrbitAngle);
    sScene.planePosition.y = sScene.orbitCenter.y + sScene.planeOrbitRadius * sin(sScene.planeOrbitAngle);
    sScene.planePosition.z = sScene.orbitCenter.z + sScene.planeOrbitRadius * sin(sScene.planeOrbitAngle);
}

void updatePropeller(float dt, float propellerSpeed)
{
    sScene.propellerRotationAngle += propellerSpeed * dt;
    sScene.propellerMatrix = planePropeller::trans * Matrix4D::rotationX(to_radians(sScene.propellerRotationAngle))  * planePropeller::scale;
}

/* function to move and update objects in scene (e.g., rotate cube according to user input) */
void sceneUpdate(float dt)
{
    sScene.planePosition = extractPosition(sScene.planeTransformationMatrix);

    // Update Camera
    if (sScene.cameraMode == THIRD_PERSON) {
        // Vector3D cameraOffset = {0.0f, 3.0f, -10.0f}; // transition the camera -> Integration of the offset for 3rd-person-view not working
        // Adjust the camera to look in the direction the plane is moving
        Vector3D directionOfMotion = normalize(sScene.planePosition - sScene.activeCamera->position); // Normalizing to preserve the direction of the vector
        cameraFollow(*sScene.activeCamera, sScene.planePosition + directionOfMotion * M_PI_2); //
    }

    const float rollSpeed = 0.5f; // degrees per second
    const float pitchSpeed = 0.5f;
    const float yawSpeed = 0.5f;
    const float propellerSpeed = 360.0f; // degrees per second

    steeringHelperFunction(dt, rollSpeed, pitchSpeed, yawSpeed);

    // Update plane position based on movement
    updatePlanePosition(dt);

    // Update plane propeller
    updatePropeller(dt, propellerSpeed);

    // Combine transformations for the plane
    Matrix4D rollMatrix = Matrix4D::rotationX(sScene.rollAngle);
    Matrix4D pitchMatrix = Matrix4D::rotationY(sScene.pitchAngle);
    // Matrix4D yawMatrix = Matrix4D::rotationY(sScene.yawAngle); // Yaw distorts the natural orbit movement look
    // Apply transformations
    sScene.planeTransformationMatrix = Matrix4D::translation(sScene.planePosition) * rollMatrix * pitchMatrix;

    // rotation of the plane to the planet side
    sScene.planeTransformationMatrix = sScene.planeTransformationMatrix * Matrix4D::rotationX(static_cast<float>(M_PI) / -2.0f);


    /* The following section whose begin is demarked by '// ___ ... ___ //' can be commented out for activating the steering functions above!
    *  While steering the plane, the orbit is not anymore just limited to the xz-plane but also depends on y-axis.
    *  When steering the plane does not align to the direction of motion. The plane's nose is rather fixed. This issue with using the direction vector for alignment remains unsolved unfortunately!
    *  Therefor we provided you with the options to check the steering isolated from the main program.
    *  In the main program, i.e. the program without commenting-out the following section, only the acceleration works properly, but the pitch, yaw and roll are not animated! */
    // ____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________ //
    // Comment-out Section Begin
    // Calculate the new position of the aircraft using polar coordinates;
    float x = sScene.orbitCenter.x + sScene.planeOrbitRadius * cos(sScene.planeOrbitAngle);
    // float y = sScene.planeOrbitRadius * sin(sScene.planeOrbitAngle); // -> leads to an upwards spiral movement
    float z = sScene.orbitCenter.z + sScene.planeOrbitRadius * sin(sScene.planeOrbitAngle);

    // Updating the aircraft transformation matrix
    sScene.planeTransformationMatrix = Matrix4D::translation(Vector3D(x, 0.0f, z));

    // turn the plane in the direction of movement
    float angleOfMotion = sScene.planeOrbitAngle + M_PI_2;
    sScene.planeTransformationMatrix = sScene.planeTransformationMatrix * Matrix4D::rotationY(-angleOfMotion); // Added rotation on the y-axis to let the plane's belly face the planet
    // And: rotate the plane to have its belly face towards the center of the orbit by adjusting the pitch (around the X-axis)
    sScene.planeTransformationMatrix = sScene.planeTransformationMatrix * Matrix4D::rotationX(-M_PI_2); // for reference: positive M_PI_2 would let the belly of the plane face the outer world!
    // Comment-out section End
    // ____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________ //
    flagAnimate(sScene.flag, sScene.flagSim, dt);
}

/* function to draw all objects in the scene */
void sceneDraw()
{
    /* clear framebuffer color */
    glClearColor(135.0f / 255, 206.0f / 255, 235.0f / 255, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /*------------ render scene -------------*/
    /* use shader and set the uniforms (names match the ones in the shader) */
    {
        glUseProgram(sScene.shaderColor.id);

        shaderUniform(sScene.shaderColor, "uProj", cameraProjection(*sScene.activeCamera)); // Pass the active camera currently pointed to
        shaderUniform(sScene.shaderColor, "uView", cameraView(*sScene.activeCamera));

        /* draw flag */
        shaderUniform(sScene.shaderColor, "uModel", sScene.planeTransformationMatrix * sScene.poleMatrix * sScene.flagModelMatrix);
        glBindVertexArray(sScene.flag.mesh.vao);
        glDrawElements(GL_TRIANGLES, sScene.flag.mesh.size_ibo, GL_UNSIGNED_INT, nullptr);

        /* draw cube, requires to calculate the final model matrix from all transformations */
        shaderUniform(sScene.shaderColor, "uModel", sScene.cubeTranslationMatrix * sScene.cubeTransformationMatrix * sScene.cubeScalingMatrix);
        glBindVertexArray(sScene.cubeMesh.vao);
        glDrawElements(GL_TRIANGLES, sScene.cubeMesh.size_ibo, GL_UNSIGNED_INT, nullptr);

        // Draw protrusion along X-axis
        shaderUniform(sScene.shaderColor, "uModel", sScene.cubeTranslationMatrix * sScene.cubeTransformationMatrix * sScene.protrusionXMatrix);
        glBindVertexArray(sScene.protrusionXMesh.vao);
        glDrawElements(GL_TRIANGLES, sScene.protrusionXMesh.size_ibo, GL_UNSIGNED_INT, nullptr);

        shaderUniform(sScene.shaderColor, "uModel", sScene.cubeTranslationMatrix * sScene.cubeTransformationMatrix * sScene.protrusionNOTXMatrix);
        glBindVertexArray(sScene.protrusionNOTXMesh.vao);
        glDrawElements(GL_TRIANGLES, sScene.protrusionNOTXMesh.size_ibo, GL_UNSIGNED_INT, nullptr);


        // Draw protrusion along Y-axis
        shaderUniform(sScene.shaderColor, "uModel", sScene.cubeTranslationMatrix * sScene.cubeTransformationMatrix * sScene.protrusionYMatrix);
        glBindVertexArray(sScene.protrusionYMesh.vao);
        glDrawElements(GL_TRIANGLES, sScene.protrusionYMesh.size_ibo, GL_UNSIGNED_INT, nullptr);

        shaderUniform(sScene.shaderColor, "uModel", sScene.cubeTranslationMatrix * sScene.cubeTransformationMatrix * sScene.protrusionNOTYMatrix);
        glBindVertexArray(sScene.protrusionNOTYMesh.vao);
        glDrawElements(GL_TRIANGLES, sScene.protrusionNOTYMesh.size_ibo, GL_UNSIGNED_INT, nullptr);


        // Draw protrusion along Z-axis
        shaderUniform(sScene.shaderColor, "uModel", sScene.cubeTranslationMatrix * sScene.cubeTransformationMatrix * sScene.protrusionZMatrix);
        glBindVertexArray(sScene.protrusionZMesh.vao);
        glDrawElements(GL_TRIANGLES, sScene.protrusionZMesh.size_ibo, GL_UNSIGNED_INT, nullptr);

        shaderUniform(sScene.shaderColor, "uModel", sScene.cubeTranslationMatrix * sScene.cubeTransformationMatrix * sScene.protrusionNOTZMatrix);
        glBindVertexArray(sScene.protrusionNOTZMesh.vao);
        glDrawElements(GL_TRIANGLES, sScene.protrusionNOTZMesh.size_ibo, GL_UNSIGNED_INT, nullptr);

        // Draw plane body
        shaderUniform(sScene.shaderColor, "uModel", sScene.planeTransformationMatrix * sScene.bodyMatrix);
        glBindVertexArray(sScene.bodyMesh.vao);
        glDrawElements(GL_TRIANGLES, sScene.bodyMesh.size_ibo, GL_UNSIGNED_INT, nullptr);

        // Draw cockpit
        shaderUniform(sScene.shaderColor, "uModel", sScene.planeTransformationMatrix * sScene.cockpitMatrix);
        glBindVertexArray(sScene.cockpitMesh.vao);
        glDrawElements(GL_TRIANGLES, sScene.cockpitMesh.size_ibo, GL_UNSIGNED_INT, nullptr);

        // Draw wing
        shaderUniform(sScene.shaderColor, "uModel", sScene.planeTransformationMatrix * sScene.wingMatrix);
        glBindVertexArray(sScene.wingMesh.vao);
        glDrawElements(GL_TRIANGLES, sScene.wingMesh.size_ibo, GL_UNSIGNED_INT, nullptr);

        // Draw tail wing
        shaderUniform(sScene.shaderColor, "uModel", sScene.planeTransformationMatrix * sScene.tailWingMatrix);
        glBindVertexArray(sScene.tailWingMesh.vao);
        glDrawElements(GL_TRIANGLES, sScene.tailWingMesh.size_ibo, GL_UNSIGNED_INT, nullptr);

        // Draw rudder
        shaderUniform(sScene.shaderColor, "uModel", sScene.planeTransformationMatrix * sScene.rudderMatrix);
        glBindVertexArray(sScene.rudderMesh.vao);
        glDrawElements(GL_TRIANGLES, sScene.rudderMesh.size_ibo, GL_UNSIGNED_INT, nullptr);

        // Draw propeller
        shaderUniform(sScene.shaderColor, "uModel", sScene.planeTransformationMatrix * sScene.propellerMatrix);
        glBindVertexArray(sScene.propellerMesh.vao);
        glDrawElements(GL_TRIANGLES, sScene.propellerMesh.size_ibo, GL_UNSIGNED_INT, nullptr);

        // Draw pole
        shaderUniform(sScene.shaderColor, "uModel", sScene.planeTransformationMatrix * sScene.poleMatrix);
        glBindVertexArray(sScene.poleMesh.vao);
        glDrawElements(GL_TRIANGLES, sScene.poleMesh.size_ibo, GL_UNSIGNED_INT, nullptr);
    }
    glCheckError();

    /* cleanup opengl state */
    glBindVertexArray(0);
    glUseProgram(0);
}

int main(int argc, char **argv)
{
    /* create window/context */
    int width = 1280;
    int height = 720;
    GLFWwindow *window = windowCreate("Assignment 3 - Transformations, User Input and Camera", width, height);
    if (!window)
    {
        return EXIT_FAILURE;
    }

    /* set window callbacks */
    glfwSetKeyCallback(window, keyCallback);
    glfwSetCursorPosCallback(window, mousePosCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetScrollCallback(window, mouseScrollCallback);
    glfwSetFramebufferSizeCallback(window, windowResizeCallback);

    /*---------- init opengl stuff ------------*/
    glEnable(GL_DEPTH_TEST);

    /* setup scene */
    sceneInit(static_cast<float>(width), static_cast<float>(height));

    /*-------------- main loop ----------------*/
    double timeStamp = glfwGetTime();
    double timeStampNew = 0.0;

    /* loop until user closes window */
    while (!glfwWindowShouldClose(window))
    {
        /* poll and process input and window events */
        glfwPollEvents();

        /* update model matrix of cube */
        timeStampNew = glfwGetTime();
        sceneUpdate(static_cast<float>(timeStampNew - timeStamp));
        timeStamp = timeStampNew;

        /* draw all objects in the scene */
        sceneDraw();

        /* swap front and back buffer */
        glfwSwapBuffers(window);
    }

    /*-------- cleanup --------*/
    /* delete opengl shader and buffers */
    shaderDelete(sScene.shaderColor);
    flagDelete(sScene.flag);
    meshDelete(sScene.cubeMesh);
    meshDelete(sScene.protrusionXMesh);
    meshDelete(sScene.protrusionNOTXMesh);
    meshDelete(sScene.protrusionYMesh);
    meshDelete(sScene.protrusionNOTYMesh);
    meshDelete(sScene.protrusionZMesh);
    meshDelete(sScene.protrusionNOTZMesh);
    shaderDelete(sScene.shaderColor);
    flagDelete(sScene.flag);
    meshDelete(sScene.bodyMesh);
    meshDelete(sScene.cockpitMesh);
    meshDelete(sScene.wingMesh);
    meshDelete(sScene.tailWingMesh);
    meshDelete(sScene.rudderMesh);
    meshDelete(sScene.propellerMesh);
    meshDelete(sScene.poleMesh);

    /* cleanup glfw/glcontext */
    windowDelete(window);

    return EXIT_SUCCESS;
}