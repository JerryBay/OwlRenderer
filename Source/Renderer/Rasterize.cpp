#include "Rasterize.h"

namespace Renderer
{
    Rasterize::Rasterize(const int width,const int height):_width(width),_height(height)
    {
        _frameBuffer.reserve(width*height);
        _depthBuffer.reserve(width*height);
    }

    Rasterize::~Rasterize()
    {

    }

    int Rasterize::GetIdx(const Math::Vector2& point) const
    {
        return point[1]*_width+point[0];
        //return (_width-y-1)*y+x;
    }

    void Rasterize::SetColor(const Math::Vector2& point,const Math::Vector4& color)
    {
        int idx=GetIdx(point);
        _frameBuffer[idx]=color;
    }

    void Rasterize::SetDepth(const Math::Vector2& point,const double depth)
    {
        int idx=GetIdx(point);
        _depthBuffer[idx]=depth; 
    }

    Math::Vector4 Rasterize::GetColor(const Math::Vector2& point) const
    {
        int idx=GetIdx(point);
        return _frameBuffer[idx];     
    }

    double Rasterize::GetDepth(const Math::Vector2& point) const
    {
        int idx=GetIdx(point);
        return _depthBuffer[idx];             
    } 
} // namespace Renderer
