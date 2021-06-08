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

        void SetFloat(const char* name,const float value)
        {

        }

        void SetVector4(const char* name,const Math::Vector4& vec)
        {

        }
    };
} // namespace Shader
