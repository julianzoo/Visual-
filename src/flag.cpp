#include <algorithm>

#include "flag.h"
#include "mygl/geometry.h"

Flag flagCreate(const Vector3D &color)
{
    Flag flag;
    flag.vertices.resize(grid::vertexPos.size());

    /* Setup matrices for vertex transformations */
    int gridLength = 40;
    float zScale = 0.2f;
    Vector3D flagTranslation = Vector3D(0.0f, 0.0f, -gridLength / 2.0f);
    Matrix3D flagScale = Matrix3D::scale(0.1f, 0.0f, zScale);
    Matrix3D flagRotation = Matrix3D::rotationZ(static_cast<float>(to_radians(-90)));

    /* Transform the grid's vertices and add them to the flag with the given color */
    for (unsigned i = 0; i < flag.vertices.size(); i++)
    {
        flag.vertices[i] = {flagRotation * flagScale * (flagTranslation + grid::vertexPos[i]), color};
    }
    flag.mesh = meshCreate(flag.vertices, grid::indices, GL_DYNAMIC_DRAW, GL_STATIC_DRAW);

    return flag;
}

void flagDelete(Flag &flag)
{
    meshDelete(flag.mesh);
}
