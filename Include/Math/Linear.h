#pragma once

#include <assert.h>
#include <stdarg.h>
#include <iostream>

namespace Math
{
    template<int Dimen>
    struct Vec
    {
        double data[Dimen]={0};

        Vec()=default;

        Vec(int count,...)
        {
            va_list list;
            va_start(list,count);
            int i=0;

            for (int i = 0; i < Dimen; i++)
            {           
                data[i]=va_arg(list,double);
            }

            va_end(list);
        }

        double operator[](const int i) const
        {
            assert(i>=0&&i<Dimen);
            return data[i];
        }
    };


    template<int Dimen>
    double operator*(const Vec<Dimen>& lvec,const Vec<Dimen>& rvec)
    {
        double res=0;

        for (int i = 0; i < Dimen; i++)
        {
            res+=lvec[i]*rvec[i];
        }
        
        return res;
    }

    template<int Dimen>
    Vec<Dimen> operator*(const Vec<Dimen>& vec,double value)
    {
        Vec<Dimen> res=vec;

        for (int i = 0; i < Dimen; i++)
        {
            res[i]*value;
        }
        
        return res;
    }

    template<int Dimen>
    Vec<Dimen> operator*(double value,const Vec<Dimen>& vec)
    {
        Vec<Dimen> res=vec;

        for (int i = 0; i < Dimen; i++)
        {
            res[i]*value;
        }
        
        return res;
    }

    template<int Dimen>
    Vec<Dimen> operator+(const Vec<Dimen>& lvec,const Vec<Dimen>& rvec)
    {
        Vec<Dimen> res=lvec;

        for (int i = 0; i < Dimen; i++)
        {
            res[i]+=rvec[i];
        }
        
        return res;
    }

    template<int Dimen>
    std::ostream& operator<<(std::ostream& out,const Vec<Dimen>& vec)
    {
        for (int i = 0; i < Dimen; i++)
        {
            out<<vec[i]<<" ";
        }

        out<<std::endl;

        return out;
    }

    typedef Vec<2> Vector2;
    typedef Vec<3> Vector3;
    typedef Vec<4> Vector4;
} // namespace Math
