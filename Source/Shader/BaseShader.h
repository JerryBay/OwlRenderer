#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include "../Math/Math.h"
#include "../ModelProcessor/ModelProcessor.h"

namespace Shader
{
    class BaseShader
    {
    protected:
        Model::BaseModel* _model;
        std::unordered_map<std::string,int> _intMap;
        std::unordered_map<std::string,float> _floatMap;
        std::unordered_map<std::string,Math::Vector4> _vector4Map;
        std::unordered_map<std::string,void*> _textureMap;
    public:
        virtual void VertexShader()=0;
        virtual void FragmentShader()=0;
        virtual void SetTexture(const char* name,void* image)=0;

        void SetInt(const char* name,const int value)
        {
            std::string strName(name);

            if (_intMap.find(strName)!=_intMap.end())
            {
                _intMap[strName]=value;
            }
            else
            {
                std::cerr<<"Can`t find the para"<<std::endl;
            }
        }

        int GetInt(const char* name)
        {
            std::string strName(name);

            if (_intMap.find(strName)!=_intMap.end())
            {
                return _intMap[strName];
            }
            else
            {
                std::cerr<<"Can`t find the para"<<std::endl;
            }
        }

        void SetFloat(const char* name,const float value)
        {
            std::string strName(name);

            if (_floatMap.find(strName)!=_floatMap.end())
            {
                _floatMap[strName]=value;
            }
            else
            {
                std::cerr<<"Can`t find the para"<<std::endl;
            }
        }

        float GetFloat(const char* name)
        {
            std::string strName(name);

            if (_floatMap.find(strName)!=_floatMap.end())
            {
                return _floatMap[strName];
            }
            else
            {
                std::cerr<<"Can`t find the para"<<std::endl;
            }
        }

        void SetVector4(const char* name,const Math::Vector4& vec)
        {
            std::string strName(name);

            if (_vector4Map.find(strName)!=_vector4Map.end())
            {
                _vector4Map[strName]=vec;
            }
            else
            {
                std::cerr<<"Can`t find the para"<<std::endl;
            }
        }

        Math::Vector4 GetVector4(const char* name)
        {
            std::string strName(name);

            if (_vector4Map.find(strName)!=_vector4Map.end())
            {
                return _vector4Map[strName];
            }
            else
            {
                std::cerr<<"Can`t find the para"<<std::endl;
            }
        }
    };
} // namespace Shader
