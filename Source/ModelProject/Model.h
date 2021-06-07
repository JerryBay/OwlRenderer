#pragma once
#include "../Math/Math.h"

namespace Model
{
    struct Vertex
    {
        Math::Vector3 position;
        Math::Vector2 texcoord;
        Math::Vector3 normal;
    };
} // namespace Model

#include "ObjModel.h"