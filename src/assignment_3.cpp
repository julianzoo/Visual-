#include <cstdlib>
#include <iostream>

#include "mygl/shader.h"
#include "mygl/mesh.h"
#include "mygl/geometry.h"
#include "mygl/camera.h"

#include <flag.h>

/* translation and color for the flag plane */
namespace flagPlane
{
    const Vector4D color = { 0.96f, 0.57f, 0.0f, 1.0f };
    const Matrix4D trans = Matrix4D::identity();
    // Matrix4D flagScale = Matrix4D::scale(10.5f, 0.5f, 0.5f);
}

/* translation and scale for the scaled cube */
namespace scaledCube
{
    const Vector4D color = {0.55f, 0.27f, 0.07f, 1.0f}; // Brown (Earth)
    const Matrix4D scale = Matrix4D::scale(2.0f, 2.0f, 2.0f);
    const Matrix4D trans = Matrix4D::identity();
}

// Create namespaces for protrusions
namespace protrusionX
{
    const Vector4D color = {0.0f, 1.0f, 0.0f, 1.0f}; // Green color
    const Matrix4D trans = Matrix4D::translation(Vector3D (2.0f, 0.0f, 0.0f));
    const Matrix4D scale = Matrix4D::scale(1.0f, 1.0f, 1.0f);
}

namespace protrusionNOTX
{
    const Vector4D color = {0.0f, 1.0f, 0.0f, 1.0f}; // Green color
    const Matrix4D trans = Matrix4D::translation(Vector3D (-2.0f, 0.0f, 0.0f));
    const Matrix4D scale = Matrix4D::scale(1.0f, 1.0f, 1.0f);
}

namespace protrusionY
{
    const Vector4D color = {0.0f, 1.0f, 0.0f, 1.0f}; // Green color
    const Matrix4D trans = Matrix4D::translation(Vector3D (0.0f, 2.0f, 0.0f));
    const Matrix4D scale = Matrix4D::scale(1.0f, 1.0f, 1.0f);
}

namespace protrusionNOTY
{
    const Vector4D color = {0.0f, 1.0f, 0.0f, 1.0f}; // Green color
    const Matrix4D trans = Matrix4D::translation(Vector3D (0.0f, -2.0f, 0.0f));
    const Matrix4D scale = Matrix4D::scale(1.0f, 1.0f, 1.0f);
}

namespace protrusionZ
{
    const Vector4D color = {0.0f, 1.0f, 0.0f, 1.0f}; // Green color
    const Matrix4D trans = Matrix4D::translation(Vector3D (0.0f, 0.0f, 2.0f));
    const Matrix4D scale = Matrix4D::scale(1.0f, 1.0f, 1.0f);
}

namespace protrusionNOTZ
{
    const Vector4D color = {0.0f, 1.0f, 0.0f, 1.0f}; // Green color
    const Matrix4D trans = Matrix4D::translation(Vector3D (0.0f, 0.0f, -2.0f));
    const Matrix4D scale = Matrix4D::scale(1.0f, 1.0f, 1.0f);
}

// Plane parts
namespace planeBody{
    const Vector4D color = {0.5f, 0.0f, 0.0f, 1.0f};
    const Matrix4D trans = Matrix4D::translation(Vector3D (0.0f, 0.0f, -7.0f));
    const Matrix4D scale = Matrix4D::scale(4.0f, 1.0f, 1.0f);
}

namespace planeCockpit{
    const Vector4D color = {0.0f, 0.0f, 1.0f, 1.0f};
    const Matrix4D trans = Matrix4D::translation(Vector3D (1.75f, 1.3f, -7.0f));
    const Matrix4D scale = Matrix4D::scale(1.5f, 0.4f, 1.0f);
}

namespace planeWing
{
    const Vector4D color = {1.0f, 0.0f, 0.0f, 1.0f};
    const Matrix4D scale = Matrix4D::scale(1.0f, 0.2f, 6.0f); // Wide wing
    const Matrix4D trans = Matrix4D::translation(Vector3D (0.0f, 0.0f, -7.0f));
}

namespace planeTailWing
{
    const Vector4D color = {1.0f, 0.0f, 0.0f, 1.0f};
    const Matrix4D scale = Matrix4D::scale(0.5f, -0.1f, 2.0f);
    const Matrix4D trans = Matrix4D::translation(Vector3D(-3.5f, 0.5f, -7.0f));
}

namespace planeRudder
{
    const Vector4D color = {1.0f, 0.0f, 0.0f, 1.0f};
    const Matrix4D scale = Matrix4D::scale(0.1f, 1.0f, 1.0f);
    const Matrix4D trans = Matrix4D::translation(Vector3D(-4.0f, 1.0f, -7.0f));
    const Matrix4D rot = Matrix4D::rotationY(static_cast<float>(M_PI) / 2.0f);
}

namespace planePropeller
{
    const Vector4D color = {0.3f, 0.3f, 0.3f, 1.0f};
    const Matrix4D scale = Matrix4D::scale(0.1f, 2.0f, 0.1f);
    const Matrix4D trans = Matrix4D::translation(Vector3D(4.1f, 0.0f, -7.0f));
}

namespace planePole
{
    const Vector4D color = {0.5f, 0.5f, 0.5f, 1.0f};
    const Matrix4D scale = Matrix4D::scale(0.1f, 0.1f, 2.0f);
    const Matrix4D trans = Matrix4D::translation(Vector3D(-4.5f, 0.0f, -7.0f));
    const Matrix4D rot = Matrix4D::rotationY(static_cast<float>(M_PI) / 2.0f);
}

/* struct holding all necessary state variables for scene */
struct
{
    /* camera */
    Camera camera;
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
    float propellerRotationAngle = 0.0f;
} sScene;

/* struct holding all state variables for input */
struct
{
    bool mouseLeftButtonPressed = false;
    Vector2D mousePressStart;
    bool keyPressed[4] = {false, false, false, false};
} sInput;

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

    /* input for cube control */
    if (key == GLFW_KEY_W)
    {
        sInput.keyPressed[0] = (action == GLFW_PRESS || action == GLFW_REPEAT);
    }
    if (key == GLFW_KEY_S)
    {
        sInput.keyPressed[1] = (action == GLFW_PRESS || action == GLFW_REPEAT);
    }

    if (key == GLFW_KEY_A)
    {
        sInput.keyPressed[2] = (action == GLFW_PRESS || action == GLFW_REPEAT);
    }
    if (key == GLFW_KEY_D)
    {
        sInput.keyPressed[3] = (action == GLFW_PRESS || action == GLFW_REPEAT);
    }
}

/* GLFW callback function for mouse position events */
void mousePosCallback(GLFWwindow *window, double x, double y)
{
    /* called on cursor position change */
    if (sInput.mouseLeftButtonPressed)
    {
        Vector2D diff = sInput.mousePressStart - Vector2D(static_cast<float>(x), static_cast<float>(y));
        cameraUpdateOrbit(sScene.camera, diff, 0.0f);
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
    cameraUpdateOrbit(sScene.camera, {0, 0}, -sScene.zoomSpeedMultiplier * static_cast<float>(yoffset));
}

/* GLFW callback function for window resize event */
void windowResizeCallback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
    sScene.camera.width = static_cast<float>(width);
    sScene.camera.height = static_cast<float>(height);
}

/* function to setup and initialize the whole scene */
void sceneInit(float width, float height)
{
    /* initialize camera */
    sScene.camera = cameraCreate(width, height, BASE_FOV, 0.01f, 500.0f, {10.0f, 10.0f, 10.0f}, {0.0f, 0.0f, 0.0f});
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

/* function to move and update objects in scene (e.g., rotate cube according to user input) */
void sceneUpdate(float dt)
{
    /* if 'w' or 's' pressed, cube should rotate around x axis */
    int rotationDirX = 0;
    if (sInput.keyPressed[0]) {
        rotationDirX = 1;
    } else if (sInput.keyPressed[1]) {
        rotationDirX = -1;
    }

    /* if 'a' or 'd' pressed, cube should rotate around y axis */
    int rotationDirY = 0;
    if (sInput.keyPressed[2]) {
        rotationDirY = 1;
    } else if (sInput.keyPressed[3]) {
        rotationDirY = -1;
    }

    /* udpate cube transformation matrix to include new rotation if one of the keys was pressed */
    if (rotationDirX != 0 || rotationDirY != 0) {
        sScene.planeTransformationMatrix = Matrix4D::rotationY(rotationDirY * sScene.cubeSpinRadPerSecond * dt) * Matrix4D::rotationX(rotationDirX * sScene.cubeSpinRadPerSecond * dt) * sScene.planeTransformationMatrix;
        sScene.cubeTransformationMatrix = Matrix4D::rotationY(rotationDirY * sScene.cubeSpinRadPerSecond * dt) * Matrix4D::rotationX(rotationDirX * sScene.cubeSpinRadPerSecond * dt) * sScene.cubeTransformationMatrix;
    }

    /* Propeller rotation update */
    float propellerSpeed = 360.0f;
    sScene.propellerRotationAngle += propellerSpeed * dt;

    sScene.propellerMatrix = 
        planePropeller::trans * 
        Matrix4D::rotationX(to_radians(sScene.propellerRotationAngle))
         * planePropeller::scale;
    //sScene.propellerMatrix = sScene.propellerMatrix * Matrix4D::rotationX(5.0f *dt); // rotate propeller continuously
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
        shaderUniform(sScene.shaderColor, "uProj", cameraProjection(sScene.camera));
        shaderUniform(sScene.shaderColor, "uView", cameraView(sScene.camera));

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
