#include "Rasterize.h"

namespace Renderer
{
    Rasterize::Rasterize(const int width,const int height,Camera* camera):_width(width),_height(height),_camera(camera)
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

    Rasterize::Point Rasterize::NDC2Screen(const double x,const double y) const
    {
        Point res;
        res.x=(x+1)/2*_width;
        res.y=(y+1)/2*_height;
        return res;
    }

    void Rasterize::DrawTriangles(const Model::BaseModel* model,Shader::BaseShader* shader)
    {
        Math::Matrix4 mat=_projection*_view*_model;
        std::vector<Math::Vector4> screenPoints;
        std::vector<Model::Triangle> tris=model->GetTriangles();
        for (int i = 0; i < tris.size(); i++)
        {
            Model::Triangle triangle=tris[i];
            auto v1=mat*Math::Embed<4>(*(triangle.ver[0].position));
            auto v2=mat*Math::Embed<4>(*(triangle.ver[1].position));
            auto v3=mat*Math::Embed<4>(*(triangle.ver[2].position));
        }
        
    }
} // namespace Renderer
