#pragma once

#include "Model.h"

namespace Model
{
    struct TriangleIndex
    {
        int posidx[3];
        int uvidx[3];
        int nrmidx[3];
    };

    class ObjModel:public Model
    {
    private:
        std::vector<Math::Vector3> _positions;
        std::vector<Math::Vector2> _texcoords;
        std::vector<Math::Vector3> _normals;

        std::vector<TriangleIndex> _facets;
    public:
        ObjModel();
        ObjModel(const std::string filename);
        virtual void LoadModel(const std::string filename);
        int PosCount() const;
        int UVCount() const;
        int NmrCount() const;
        int TriCount() const;
    };
} // namespace Model
