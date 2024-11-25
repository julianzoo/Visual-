//
// Created by julian on 23.11.24.
//

#ifndef TRANSFORMSANDCOLORS_H
#define TRANSFORMSANDCOLORS_H

#pragma once

#include "mygl/geometry.h" // Assuming this is where Vector4D and Matrix4D are defined

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
    const Vector4D color = {0.5f, 0.3f, 0.13f, 1.f};; // Brown (Earth)
    const Matrix4D scale = Matrix4D::scale(7.0f, 7.0f, 7.0f);
    const Matrix4D trans = Matrix4D::identity();
}

// Create namespaces for protrusions
namespace protrusionX
{
    const Vector4D color = {0.3f, 0.5f, 0.3f, 1.0f}; // Green color
    const Matrix4D trans = Matrix4D::translation(Vector3D (2.0f, 0.0f, 0.0f));
    const Matrix4D scale = Matrix4D::scale(7.0f, 4.0f, 4.0f);
}

namespace protrusionNOTX
{
    const Vector4D color = {0.3f, 0.5f, 0.3f, 1.0f};
    const Matrix4D trans = Matrix4D::translation(Vector3D (-2.0f, 0.0f, 0.0f));
    const Matrix4D scale = Matrix4D::scale(7.0f, 4.0f, 4.0f);
}

namespace protrusionY
{
    const Vector4D color = {0.3f, 0.5f, 0.3f, 1.0f};
    const Matrix4D trans = Matrix4D::translation(Vector3D (0.0f, 2.0f, 0.0f));
    const Matrix4D scale = Matrix4D::scale(4.0f, 7.0f, 4.0f);
}

namespace protrusionNOTY
{
    const Vector4D color = {0.3f, 0.5f, 0.3f, 1.0f};
    const Matrix4D trans = Matrix4D::translation(Vector3D (0.0f, -2.0f, 0.0f));
    const Matrix4D scale = Matrix4D::scale(4.0f, 7.0f, 4.0f);
}

namespace protrusionZ
{
    const Vector4D color = {0.3f, 0.5f, 0.3f, 1.0f};
    const Matrix4D trans = Matrix4D::translation(Vector3D (0.0f, 0.0f, 2.0f));
    const Matrix4D scale = Matrix4D::scale(4.0f, 4.0f, 7.0f);
}

namespace protrusionNOTZ
{
    const Vector4D color = {0.3f, 0.5f, 0.3f, 1.0f};
    const Matrix4D trans = Matrix4D::translation(Vector3D (0.0f, 0.0f, -2.0f));
    const Matrix4D scale = Matrix4D::scale(4.0f, 4.0f, 7.0f);
}


// Plane parts
namespace planeBody{
    const Vector4D color = {0.5f, 0.0f, 0.0f, 1.0f};
    const Matrix4D trans = Matrix4D::translation(Vector3D (0.0f, 0.0f, 0.0f));
    const Matrix4D scale = Matrix4D::scale(1.0f, 0.25f, 0.25f);
}

namespace planeCockpit{
    const Vector4D color = {0.0f, 0.0f, 1.0f, 1.0f};
    const Matrix4D trans = Matrix4D::translation(Vector3D (0.4f, 0.35f, 0.0f));
    const Matrix4D scale = Matrix4D::scale(0.375f, 0.1f, 0.25f);
}

namespace planeWing
{
    const Vector4D color = {1.0f, 0.0f, 0.0f, 1.0f};
    const Matrix4D scale = Matrix4D::scale(0.25f, 0.05f, 1.5f); // Wide wing
    const Matrix4D trans = Matrix4D::translation(Vector3D (0.0f, 0.0f, 0.0f));
}

namespace planeTailWing
{
    const Vector4D color = {1.0f, 0.0f, 0.0f, 1.0f};
    const Matrix4D scale = Matrix4D::scale(0.125f, -0.025f, 0.5f);
    const Matrix4D trans = Matrix4D::translation(Vector3D(-1.0f, 0.125f, 0.0f));
}

namespace planeRudder
{
    const Vector4D color = {1.0f, 0.0f, 0.0f, 1.0f};
    const Matrix4D scale = Matrix4D::scale(0.025f, 0.25f, 0.25f);
    const Matrix4D trans = Matrix4D::translation(Vector3D(-1.0f, 0.35f, 0.0f));
    const Matrix4D rot = Matrix4D::rotationY(static_cast<float>(M_PI) / 2.0f);
}

namespace planePropeller
{
    const Vector4D color = {0.3f, 0.3f, 0.3f, 1.0f};
    const Matrix4D scale = Matrix4D::scale(0.025f, 0.5f, 0.025f);
    const Matrix4D trans = Matrix4D::translation(Vector3D(1.025f, 0.0f, 0.0f));
}

namespace planePole
{
    const Vector4D color = {0.5f, 0.5f, 0.5f, 1.0f};
    const Matrix4D scale = Matrix4D::scale(0.025f, 0.025f, 0.5f);
    const Matrix4D trans = Matrix4D::translation(Vector3D(-1.125f, 0.0f, 0.0f));
    const Matrix4D rot = Matrix4D::rotationY(static_cast<float>(M_PI) / 2.0f);
}

#endif //TRANSFORMSANDCOLORS_H
