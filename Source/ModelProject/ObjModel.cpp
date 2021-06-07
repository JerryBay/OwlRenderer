#include "ObjModel.h"

namespace Model
{
    ObjModel::ObjModel()
    {

    }

    ObjModel::ObjModel(const std::string filename)
    {
        LoadObjMode(filename);
    }

    void ObjModel::LoadObjMode(const std::string filename)
    {
        std::ifstream in;
        in.open(filename,std::ifstream::in);

        if (in.fail())
        {
            std::cerr<<"load Obj file failed!";
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
                Math::Vector3 pos;
                for (int i = 0; i < 3; i++)
                {
                    iss>>pos[i];
                }
                _positions.push_back(pos);
            }
            else if (!line.compare(0,3,"vt "))
            {
                iss>>trash>>trash;
                Math::Vector2 uv;
                for (int i = 0; i < 2; i++)
                {
                    iss>>uv[i];
                }
                _texcoords.push_back(uv);
            }
            else if (!line.compare(0,3,"vn "))
            {
                iss>>trash>>trash;
                Math::Vector3 normal;
                for (int i = 0; i < 3; i++)
                {
                    iss>>normal[i];
                }
                _normals.push_back(normal);
            }
            else if (!line.compare(0,2,"f "))
            {
                iss>>trash;
                int p,t,n;
                TriangleIndex tri;
                int count=0;
                while (iss>>p>>trash>>t>>trash>>n)
                {
                    tri.posidx[count]=p--;
                    tri.uvidx[count]=t--;
                    tri.nrmidx[count]=n--;
                    count++;
                }
                if (3!=count) {
                    std::cerr << "Error: the obj file is supposed to be triangulated" << std::endl;
                    in.close();
                    return;
                }
                facets.push_back(tri);
            }

            in.close();            
        }        
    }
} // namespace Model
