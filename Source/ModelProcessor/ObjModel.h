#pragma once

#include "BaseModel.h"

namespace Model
{
    // struct TriangleIndex
    // {
    //     int posidx[3];
    //     int uvidx[3];
    //     int nrmidx[3];
    // };

    class ObjModel:public BaseModel
    {
    private:
        std::vector<std::shared_ptr<Math::Vector3>> _positions;
        std::vector<std::shared_ptr<Math::Vector2>> _texcoords;
        std::vector<std::shared_ptr<Math::Vector3>> _normals;

        //std::vector<TriangleIndex> _facets;
    public:
        ObjModel();
        ObjModel(const std::string filename);
        virtual void LoadModel(const std::string filename);
        virtual std::vector<Triangle> GetTriangles() const;
        int PosCount() const;
        int UVCount() const;
        int NmrCount() const;
        int TriCount() const;
    };
} // namespace Model
