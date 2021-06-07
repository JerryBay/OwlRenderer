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

        Math::Matrix4 _model;
        Math::Matrix4 _view;
        Math::Matrix4 _projection;
    public:
        Rasterize(const int width,const int height);
        ~Rasterize();
        int GetIdx(const int x,const int y) const;
        void SetColor(const int x,const int y,const Math::Vector4& color);
        void SetDepth(const int x,const int y,const double depth);
        Math::Vector4 GetColor(const int x,const int y) const;
        double GetDepth(const int x,const int y) const;
        void SetModel(const Math::Matrix4& model);
        void SetView(const Math::Matrix4& view);
        void SetProjection(const Math::Matrix4& projection); 
        void DrawTriangles();
    };
} // namespace Rasterize
