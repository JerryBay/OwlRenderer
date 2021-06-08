#pragma once

#include "BaseShader.h"

namespace Shader
{
    class UnlitShader:public BaseShader
    {
    private:
        
    public:
        virtual void VertexShader();
        virtual void FragmentShader();
        virtual void SetTexture(const char* name,void* image);
    };  
} // namespace Shader

