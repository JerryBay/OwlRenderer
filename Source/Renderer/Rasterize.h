#pragma once

#include <vector>
#include "../Math/Math.h"

namespace Renderer
{
    class Rasterize
    {
    private:
        int _width,_height;
        std::vector<Math::Vector4> _frameBuffer;
        std::vector<double> _depthBuffer;
    public:
        Rasterize(const int width,const int height);
        ~Rasterize();
        int GetIdx(const Math::Vector2& point) const;
        void SetColor(const Math::Vector2& point,const Math::Vector4& color);
        void SetDepth(const Math::Vector2& point,const double depth);
        Math::Vector4 GetColor(const Math::Vector2& point) const;
        double GetDepth(const Math::Vector2& point) const;


    };
} // namespace Rasterize
