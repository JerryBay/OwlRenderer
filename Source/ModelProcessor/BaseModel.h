#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <string>
#include <vector>
#include "../Math/Math.h"

namespace Model
{
    struct Vertex
    {
        // Math::Vector3 position;
        // Math::Vector2 texcoord;
        // Math::Vector3 normal;
        std::shared_ptr<Math::Vector3> position;
        std::shared_ptr<Math::Vector2> uv;
        std::shared_ptr<Math::Vector3> normal;
        std::shared_ptr<Math::Color> color;
    };

    struct Triangle
    {
        Vertex ver[3];
    };

    class BaseModel
    {
    protected:
        std::vector<Triangle> _triangles;
    public:
        virtual void LoadModel(const std::string filename)=0;
        virtual std::vector<Triangle> GetTriangles() const=0;
    };
} // namespace Model
