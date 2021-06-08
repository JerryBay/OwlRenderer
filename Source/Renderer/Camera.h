#pragma once

#include "../Math/Math.h"

namespace Renderer
{
    enum class ProjType
    {
        Perspective,
        Orthographic
    };

    class Camera
    {
    private:
        Math::Vector4 _position;
        Math::Vector3 _up;

        //frustum
        ProjType _projType;
        double _far;
        double _aspectRatio;
        double _width;
        double _height;

        //perspective
        double _fovX;

        //orthographic

    public:
        Math::Matrix4 GetViewMatrix()
        {

        }

        Math::Matrix4 GetProjection()
        {
            switch (_projType)
            {
            case ProjType::Perspective:
                /* code */
                break;
            case ProjType::Orthographic:
                /* code */
                break;           
            default:
                break;
            }
        }
    };
} // namespace Renderer
