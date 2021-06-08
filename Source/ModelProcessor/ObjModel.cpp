#include "ObjModel.h"

namespace Model
{
    ObjModel::ObjModel()
    {

    }

    ObjModel::ObjModel(const std::string filename)
    {
        LoadModel(filename);
    }

    void ObjModel::LoadModel(const std::string filename)
    {
        std::ifstream in;
        in.open(filename,std::ifstream::in);

        if (in.fail())
        {
            std::cerr<<"load Obj file failed!"<<std::endl;
            return;
        }
        
        std::string line;

        while (!in.eof())
        {
            char trash;
            std::getline(in,line);
            std::istringstream iss(line.c_str());

            if (!line.compare(0,2,"v "))
            {
                iss>>trash;
                auto pos=std::make_shared<Math::Vector3>();
                for (int i = 0; i < 3; i++)
                {
                    iss>>(*pos)[i];
                }
                _positions.push_back(pos);
            }
            else if (!line.compare(0,3,"vt "))
            {
                iss>>trash>>trash;
                auto uv=std::make_shared<Math::Vector2>();
                for (int i = 0; i < 2; i++)
                {
                    iss>>(*uv)[i];
                }
                _texcoords.push_back(uv);
            }
            else if (!line.compare(0,3,"vn "))
            {
                iss>>trash>>trash;
                auto normal=std::make_shared<Math::Vector3>();
                for (int i = 0; i < 3; i++)
                {
                    iss>>(*normal)[i];
                }
                _normals.push_back(normal);
            }
            else if (!line.compare(0,2,"f "))
            {
                iss>>trash;
                int p,t,n;
                // TriangleIndex tri;
                Triangle triangle;
                int count=0;
                while (iss>>p>>trash>>t>>trash>>n)
                {
                    if (count>=3)
                    {
                        std::cerr<<"Error: the obj file is supposed to be triangulated" << std::endl;
                        in.close();
                        return;
                    }
                    
                    // tri.posidx[count]=--p;
                    // tri.uvidx[count]=--t;
                    // tri.nrmidx[count]=--n;

                    triangle.ver[count]=Vertex{_positions[--p],_texcoords[--t],_normals[--n]};
                    count++;
                }
                if (3!=count) {
                    std::cerr << "Error: the obj file is supposed to be triangulated" << std::endl;
                    in.close();
                    return;
                }
                //_facets.push_back(tri);
                _triangles.push_back(triangle);
            }
        }        
        in.close();       
    }

    std::vector<Triangle> ObjModel::GetTriangles() const
    {
        return _triangles;
    }

    int ObjModel::PosCount() const
    {
        return _positions.size();
    }

    int ObjModel::UVCount() const
    {
        return _texcoords.size();
    }

    int ObjModel::NmrCount() const
    {
        return _normals.size();
    }

    int ObjModel::TriCount() const
    {
        return _triangles.size();
    }
} // namespace Model
