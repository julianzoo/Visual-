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
}

/* translation and scale for the scaled cube */
namespace scaledCube
{
    const Matrix4D scale = Matrix4D::scale(2.0f, 2.0f, 2.0f);
    const Matrix4D trans = Matrix4D::identity();
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
    sScene.cubeMesh = meshCreate(cube::vertices, cube::indices, GL_STATIC_DRAW, GL_STATIC_DRAW);
    sScene.flag = flagCreate(flagPlane::color);

    /* setup transformation matrices for objects */
    sScene.flagModelMatrix = flagPlane::trans;

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
        sScene.cubeTransformationMatrix = Matrix4D::rotationY(rotationDirY * sScene.cubeSpinRadPerSecond * dt) * Matrix4D::rotationX(rotationDirX * sScene.cubeSpinRadPerSecond * dt) * sScene.cubeTransformationMatrix;
    }
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
        shaderUniform(sScene.shaderColor, "uModel", sScene.flagModelMatrix);
        glBindVertexArray(sScene.flag.mesh.vao);
        glDrawElements(GL_TRIANGLES, sScene.flag.mesh.size_ibo, GL_UNSIGNED_INT, nullptr);

        /* draw cube, requires to calculate the final model matrix from all transformations */
        shaderUniform(sScene.shaderColor, "uModel", sScene.cubeTranslationMatrix * sScene.cubeTransformationMatrix * sScene.cubeScalingMatrix);
        glBindVertexArray(sScene.cubeMesh.vao);
        glDrawElements(GL_TRIANGLES, sScene.cubeMesh.size_ibo, GL_UNSIGNED_INT, nullptr);
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

    /* cleanup glfw/glcontext */
    windowDelete(window);

    return EXIT_SUCCESS;
}
