#include <algorithm>
#include "flag.h"
#include "mygl/geometry.h"
#include <cmath>

Flag flagCreate(const Vector3D &color)
{
    Flag flag;
    flag.vertices.resize(grid::vertexPos.size());
    // Save original Position
    flag.initialPositions = grid::vertexPos;

    /* Setup matrices for vertex transformations */
    float gridLength = 10.0f;
    float zScale = 0.2f;

    Vector3D flagTranslation = Vector3D(0.0f, 1.4f, -gridLength / 2.0f);
    Matrix3D flagScale = Matrix3D::scale(0.5f, 1.0f, zScale);
    Matrix3D flagRotation = Matrix3D::rotationZ(static_cast<float>(to_radians(-90)));

    /* Transform the grid's vertices and add them to the flag with the given color */
    for (unsigned i = 0; i < flag.vertices.size(); i++)
    {
        /*Vector4D vertexColor = (i % 2 == 0) ? Vector4D(0.0f, 0.0f, 1.0f, 1.0f) : Vector4D(1.0f, 1.0f, 0.0f, 1.0f);
        flag.vertices[i] = {flagRotation * flagScale * (flagTranslation + grid::vertexPos[i]), vertexColor};*/
        Vector3D transformedVertex = flagRotation * flagScale * (flagTranslation + grid::vertexPos[i]);

        Vector4D vertexColor = (transformedVertex.y > 0.0f)
                                ? Vector4D(0.0f, 0.0f, 1.0f, 1.0f)
                                : Vector4D(1.0f, 1.0f, 0.0f, 1.0f);

        flag.vertices[i] = {transformedVertex, vertexColor};


    }
    flag.mesh = meshCreate(flag.vertices, grid::indices, GL_DYNAMIC_DRAW, GL_STATIC_DRAW);

    return flag;
}

void flagAnimate(Flag &flag, FlagSim &flagSim, float deltaTime)
{
    // Accumulate Time
    flagSim.accumTime += deltaTime;

    float gridLength = 10.0f;
    float zScale = 0.2f;

    Vector3D flagTranslation = Vector3D(0.0f, 1.4f, -gridLength / 2.0f);
    Matrix3D flagScale = Matrix3D::scale(0.5f, 1.0f, zScale);
    Matrix3D flagRotation = Matrix3D::rotationZ(static_cast<float>(to_radians(-90)));

    for (unsigned i = 0; i < flag.vertices.size(); i++)
    {
        // Use original Position
        Vector3D originalPos = flag.initialPositions[i];

        float displacementX = 0.0f;

        // Calculate waves H(p, t) = Σ Wi(p, t)
        for (int w = 0; w < 3; w++)
        {
            const WaveParams &wave = flagSim.parameter[w];
            // Position in the yz plane
            Vector2D p = {originalPos.y, originalPos.z};
            // Scalar product p * d
            float dotProduct = p.x * wave.direction.x + p.y * wave.direction.y;

            float waveContribution = wave.amplitude * sin(wave.omega * dotProduct + flagSim.accumTime * wave.phi);
            displacementX += waveContribution;
        }

        // Linear scaling of the displacement along the flag
        // normalize z-coordinate to [0 ,1]
        float normalizedZ = 1.0f - (originalPos.z + gridLength / 2.0f) / gridLength;
        displacementX *= normalizedZ;

        // Update the x-Position
        originalPos.x += displacementX;

        // Apply transformation
        Vector3D transformedVertex = flagRotation * flagScale * originalPos + flagTranslation;

        // Update the vertices position
        flag.vertices[i].pos = transformedVertex;
    }

    // Load updated vertices into the buffer
    glBindBuffer(GL_ARRAY_BUFFER, flag.mesh.vbo);
    glBufferSubData(GL_ARRAY_BUFFER, 0, flag.vertices.size() * sizeof(Vertex), flag.vertices.data());
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void flagDelete(Flag &flag)
{
    meshDelete(flag.mesh);
}
