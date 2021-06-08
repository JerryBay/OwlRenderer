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

    int Rasterize::GetIdx(const int x,const int y) const
    {
        return y*_width+x;
        //return (_width-y-1)*y+x;
    }

    void Rasterize::SetColor(const int x,const int y,const Math::Vector4& color)
    {
        int idx=GetIdx(x,y);
        _frameBuffer[idx]=color;
    }

    void Rasterize::SetDepth(const int x,const int y,const double depth)
    {
        int idx=GetIdx(x,y);
        _depthBuffer[idx]=depth; 
    }

    Math::Vector4 Rasterize::GetColor(const int x,const int y) const
    {
        int idx=GetIdx(x,y);
        return _frameBuffer[idx];     
    }

    double Rasterize::GetDepth(const int x,const int y) const
    {
        int idx=GetIdx(x,y);
        return _depthBuffer[idx];             
    } 

    void Rasterize::SetModel(const Math::Matrix4& model)
    {
        _model=model;
    }

    void Rasterize::SetView(const Math::Matrix4& view)
    {
        _view=view;
    }

    void Rasterize::SetProjection(const Math::Matrix4& projection)
    {
        _projection=projection;
    }

    void Rasterize::DrawTriangles(Model::BaseModel* model,Shader::BaseShader* shader)
    {
        
    }
} // namespace Renderer
