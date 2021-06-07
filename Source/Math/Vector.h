#pragma once

#include <assert.h>
#include <math.h>
#include <iostream>

namespace Math
{
    //Vector
    template<int Dimen>
    struct Vec
    {
        double data[Dimen]={0};

        Vec()=default;

        // Vec(double paras[Dimen])
        // {
        //     for (int i = 0; i < Dimen; i++)
        //     {           
        //         data[i]=paras[i];
        //     }
        // }

        double operator[](const int idx) const
        {
            assert(idx>=0&&idx<Dimen);
            return data[idx];
        }

        double& operator[](const int idx)
        {
            assert(idx>=0&&idx<Dimen);
            return data[idx];
        }

        double Norm2()
        {
            return (*this)*(*this);
        }

        double Norm()
        {
            return std::sqrt(Norm2());
        }

        Vec<Dimen>& Normlize()
        {
            *this/=Norm();
            return *this;
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
            res[i]*=value;
        }
        
        return res;
    }

    template<int Dimen>
    Vec<Dimen>& operator*=(Vec<Dimen>& vec,double value)
    {
        for (int i = 0; i < Dimen; i++)
        {
            vec[i]*=value;
        }
        
        return vec;
    }

    //double*Vec
    template<int Dimen>
    Vec<Dimen> operator*(double value,const Vec<Dimen>& vec)
    {
        Vec<Dimen> res=vec;

        for (int i = 0; i < Dimen; i++)
        {
            res[i]*=value;
        }
        
        return res;
    }

    //Vec/double
    template<int Dimen>
    Vec<Dimen> operator/(const Vec<Dimen>& vec,double value)
    {
        Vec<Dimen> res=vec;

        for (int i = 0; i < Dimen; i++)
        {
            res[i]/=value;
        }
        
        return res;
    }

    template<int Dimen>
    Vec<Dimen>& operator/=(Vec<Dimen>& vec,double value)
    {
        for (int i = 0; i < Dimen; i++)
        {
            vec[i]/=value;
        }
        
        return vec;
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
    Vec<Dimen>& operator+=(Vec<Dimen>& lvec,const Vec<Dimen>& rvec)
    {
        for (int i = 0; i < Dimen; i++)
        {
            lvec[i]+=rvec[i];
        }
        
        return lvec;
    }

    template<int Dimen>
    Vec<Dimen> operator-(const Vec<Dimen>& lvec,const Vec<Dimen>& rvec)
    {
        Vec<Dimen> res=lvec;

        for (int i = 0; i < Dimen; i++)
        {
            res[i]-=rvec[i];
        }
        
        return res;
    }

    template<int Dimen>
    Vec<Dimen>& operator-=(Vec<Dimen>& lvec,const Vec<Dimen>& rvec)
    {
        for (int i = 0; i < Dimen; i++)
        {
            lvec[i]-=rvec[i];
        }
        
        return lvec;
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

    template<int Dimen1,int Dimen2>
    Vec<Dimen1> Embed(const Vec<Dimen2>& vec,double fill=1.0f)
    {
        Vec<Dimen1> res;

        for (int i = 0; i < Dimen1; i++)
        {
            res[i]=i<Dimen2?vec[i]:fill;
        }
        
        return res;
    }

    template<int Dimen1,int Dimen2>
    Vec<Dimen1> Proj(const Vec<Dimen2>& vec)
    {
        Vec<Dimen1> res;

        for (int i = 0; i < Dimen1; i++)
        {
            res[i]=vec[i];
        }
        
        return res;
    }

    template<int Dimen>
    Vec<Dimen> Mul(const Vec<Dimen>& lvec,const Vec<Dimen>& rvec)
    {
        Vec<Dimen> res;

        for (int i = 0; i < Dimen; i++)
        {
            res[i]=lvec[i]*rvec[i];
        }
        
        return res;
    }

    typedef Vec<2> Vector2;
    typedef Vec<3> Vector3;
    typedef Vec<4> Vector4;

    typedef Vec<4> Color;

    double Cross(const Vector2& lvec,const Vector2& rvec);
    
    Vector3 Cross(const Vector3& lvec,const Vector3& rvec);
} // namespace Math