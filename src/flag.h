#pragma once

#include "mygl/base.h"
#include "mygl/mesh.h"

struct WaveParams
{
    float amplitude;
    float phi;
    float omega;
    Vector2D direction;
};

struct FlagSim
{
    /**
     * Parameters for the 3 wave functions for the flag simulation
     */
    WaveParams parameter[3] = {
        { 1.0f,  1.0f,  0.25f, normalize(Vector2D{0.0f,  1.0f}) },
        { 1.2f,  1.5f, 0.75f,  normalize(Vector2D{0.0f, 1.0f}) },
        { 0.1f,  5.0f,  2.0f,  normalize(Vector2D{-1.0f / 3.0f, 1.0f}) },
    };

    float accumTime = 0.0f;
};

struct Flag {
    Mesh mesh;
    std::vector<Vertex> vertices;
    std::vector<Vector3D> initialPositions;

};

/**
 * @brief Initializes a plane grid to visualize flag surface. For that a vector containing all grid vertices is created and
 * a mesh (see function meshCreate(...)) is setup with these vertices.
 *
 * @param color Vector of the color of the Flag.
 *
 * @return Object containing the vector of vertices and an initialized mesh structure that can be drawn with OpenGL.
 *
 * usage:
 *
 *   Flag myFlag = flagCreate({0.0, 0.0, 1.0, 0.5})
 *   glBindVertexArray(myFlag.mesh.vao);
 *   glDrawElements(GL_TRIANGLES, myFlag.size_ibo, GL_UNSIGNED_INT, nullptr);
 *
 */
Flag flagCreate(const Vector3D &color);

/**
 * @brief Animates the flag by computing the wave function.
 *
 * @param flag Flag to animate.
 * @param flagSim Parameter for simulation like amplitude, frequency.
 * @param deltaTime Time since last frame.
 */
void flagAnimate(Flag &flag, FlagSim &flagSim, float deltaTime);

/**
 * @brief Cleanup and delete all OpenGL buffers of the flag mesh. Has to be called for each flag after it is not used anymore.
 *
 * @param flag Flag to delete.
 */
void flagDelete(Flag& flag);
