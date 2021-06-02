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

        Vec(double paras[Dimen])
        {
            for (int i = 0; i < Dimen; i++)
            {           
                data[i]=paras[i];
            }
        }

        double operator[](const int i) const
        {
            assert(i>=0&&i<Dimen);
            return data[i];
        }
    };

    //dot
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

    //Vec*double
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

    //double*Vec
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
