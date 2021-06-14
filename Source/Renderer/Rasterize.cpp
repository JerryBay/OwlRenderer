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

    Point Rasterize::NDC2Screen(const double x,const double y) const
    {
        Point res;
        res.x=(x+1)/2*_width;
        res.y=(y+1)/2*_height;
        return res;
    }

    void Rasterize::DrawModel(const Model::BaseModel* model,Shader::BaseShader* shader)
    {
        std::vector<Model::Triangle> tris=model->GetTriangles();
        for (int i = 0; i < tris.size(); i++)
        {
            DrawTriangle(tris[i],shader);
        }
    }

    void Rasterize::DrawTriangle(const Model::Triangle& triangle,Shader::BaseShader* shader)
    {
        std::vector<Math::Vector4> screenPoints;
        Math::Matrix4 mat=_projection*_view*_model;
        auto v1=mat*Math::Embed<4>(*(triangle.ver[0].position));
        auto v2=mat*Math::Embed<4>(*(triangle.ver[1].position));
        auto v3=mat*Math::Embed<4>(*(triangle.ver[2].position));
        Point points[3]={NDC2Screen(v1[0],v1[1]),NDC2Screen(v2[0],v2[1]),NDC2Screen(v3[0],v3[1])};
        int AABB[4]={};
        AABBRect(points,AABB);
        for (int x = AABB[0]; x < AABB[2]; x++)
        {
            for (int y = AABB[1]; y < AABB[3]; y++)
            {
                if (InsideTriangle(Point{x,y},points))
                {
                    /* code */
                }                
            }       
        }
        
    }

    bool InsideTriangle(const Point& point,const Point* points)
    {
        
    }

    void AABBRect(const Point* points,int* AABB)
    {
        AABB[0]=std::min(std::min(points[0].x,points[1].x),points[2].x);
        AABB[1]=std::min(std::min(points[0].y,points[1].y),points[2].y);
        AABB[2]=std::max(std::max(points[0].x,points[1].x),points[2].x);
        AABB[3]=std::max(std::max(points[0].y,points[1].y),points[2].y);
    }
} // namespace Renderer
