#pragma once

#include "Vector.h"

//Matrix

namespace Math
{
    template <int Dimen>
    struct Det;

    template <int RowDimen, int ColDimen>
    struct Mat
    {
        Vec<ColDimen> rows[RowDimen] = {{}};

        Mat() = default;

        Vec<ColDimen> &operator[](const int idx)
        {
            assert(idx >= 0 && idx < RowDimen);
            return rows[idx];
        }

        const Vec<ColDimen> &operator[](const int idx) const
        {
            assert(idx >= 0 && idx < RowDimen);
            return rows[idx];
        }

        Vec<RowDimen> Column(const int idx) const
        {
            assert(idx >= 0 && idx < ColDimen);
            Vec<RowDimen> res;

            for (int i = 0; i < RowDimen; i++)
            {
                res[i] = rows[i][idx];
            }

            return res;
        }

        void SetColumn(const int idx, const Vec<RowDimen> &vec)
        {
            assert(idx >= 0 && idx < ColDimen);

            for (int i = 0; i < RowDimen; i++)
            {
                rows[i][idx] = vec[i];
            }
        }

        Mat<RowDimen-1,ColDimen-1> GetMinor(const int row,const int col) const
        {
            Mat<RowDimen-1,ColDimen-1> res;

            for (int i = 0; i <RowDimen-1; i++)
            {
                for (int j = 0; j < ColDimen-1; j++)
                {
                    res[i][j]=rows[i<row?i:i+1][j<col?j:j+1];
                }               
            }
            
            return res;
        }

        double DetValue() const
        {
            return Det<ColDimen>::Value(*this);
        }

        //代数余子式
        double Cofactor(const int row,const int col) const
        {
            return GetMinor(row,col).DetValue()*((row+col)%2?-1:1);
        }

        //伴随矩阵
        Mat<RowDimen, ColDimen> Adjugate() const
        {
            Mat<RowDimen,ColDimen> res;

            for (int i = 0; i < RowDimen; i++)
            {
                for (int j = 0; j < ColDimen; j++)
                {
                    res[i][j]=Cofactor(i,j);
                }             
            }
            
            return res;
        }

        static Mat<RowDimen, ColDimen> Identity()
        {
            Mat<RowDimen, ColDimen> res;

            for (int i = 0; i < RowDimen; i++)
            {
                for (int j = 0; j < ColDimen; j++)
                {
                    res[i][j] = (i == j);
                }
            }

            return res;
        }

        Mat<ColDimen,RowDimen> Transpose() const
        {
            Mat<ColDimen,RowDimen> res;

            for (int i = 0; i < ColDimen; i++)
            {
                res[i]=this->Column(i);
            }
            
            return res;
        }

        Mat<RowDimen,ColDimen> InverseTranspose() const
        {
            Mat<RowDimen,ColDimen> mat=Adjugate();
            return mat/(mat[0]*rows[0]);
        }

        Mat<RowDimen,ColDimen> Inverse() const
        {
            return InverseTranspose().Transpose();
        }
    };

    template <int RowDimen, int ColDimen>
    std::ostream &operator<<(std::ostream &out, const Mat<RowDimen, ColDimen> &mat)
    {
        for (int i = 0; i < RowDimen; i++)
        {
            out << mat[i];
        }

        return out;
    }

    template <int RowDimen, int ColDimen>
    Mat<RowDimen, ColDimen> operator+(const Mat<RowDimen, ColDimen> &lmat, const Mat<RowDimen, ColDimen> &rmat)
    {
        Mat<RowDimen, ColDimen> res;

        for (int i = 0; i < RowDimen; i++)
        {
            res[i] = lmat[i] + rmat[i];
        }

        return res;
    }

    template <int RowDimen, int ColDimen>
    Mat<RowDimen, ColDimen> operator+=(Mat<RowDimen, ColDimen> &lmat, const Mat<RowDimen, ColDimen> &rmat)
    {
        for (int i = 0; i < RowDimen; i++)
        {
            lmat[i] += rmat[i];
        }

        return lmat;
    }

    template <int RowDimen, int ColDimen>
    Mat<RowDimen, ColDimen> operator-(const Mat<RowDimen, ColDimen> &lmat, const Mat<RowDimen, ColDimen> &rmat)
    {
        Mat<RowDimen, ColDimen> res;

        for (int i = 0; i < RowDimen; i++)
        {
            res[i] = lmat[i] - rmat[i];
        }

        return res;
    }

    template <int RowDimen, int ColDimen>
    Mat<RowDimen, ColDimen> operator-=(Mat<RowDimen, ColDimen> &lmat, const Mat<RowDimen, ColDimen> &rmat)
    {
        for (int i = 0; i < RowDimen; i++)
        {
            lmat[i] -= rmat[i];
        }

        return lmat;
    }

    template <int RowDimen,int ColDimen>
    Mat<RowDimen,ColDimen> operator*(const Mat<RowDimen,ColDimen>& mat,double value)
    {
        Mat<RowDimen,ColDimen> res;

        for (int i = 0; i < RowDimen; i++)
        {
            res[i]=mat[i]*value;
        }
        
        return res;
    }

    template <int RowDimen,int ColDimen>
    Mat<RowDimen,ColDimen>& operator*=(Mat<RowDimen,ColDimen>& mat,double value)
    {
        for (int i = 0; i < RowDimen; i++)
        {
            mat[i]*=value;
        }
        
        return mat;
    }

    template <int RowDimen,int ColDimen>
    Mat<RowDimen,ColDimen> operator/(const Mat<RowDimen,ColDimen>& mat,double value)
    {
        Mat<RowDimen,ColDimen> res;

        for (int i = 0; i < RowDimen; i++)
        {
            res[i]=mat[i]/value;
        }
        
        return res;
    }

    template <int RowDimen,int ColDimen>
    Mat<RowDimen,ColDimen>& operator/=(Mat<RowDimen,ColDimen>& mat,double value)
    {
        for (int i = 0; i < RowDimen; i++)
        {
            mat[i]/=value;
        }
        
        return mat;
    }

    template <int RowDimen,int ColDimen>
    Mat<RowDimen,ColDimen> operator*(double value,const Mat<RowDimen,ColDimen>& mat)
    {
        Mat<RowDimen,ColDimen> res;

        for (int i = 0; i < RowDimen; i++)
        {
            res[i]=mat[i]*value;
        }
        
        return res;
    }

    template <int RowDimen,int ColDimen>
    Vec<RowDimen> operator*(const Mat<RowDimen,ColDimen>& lmat,const Vec<ColDimen>& rvec)
    {
        Vec<RowDimen> res;

        for (int i = 0; i < RowDimen; i++)
        {
            res[i]=lmat[i]*rvec;
        }
        
        return res;
    }

    template <int RowDimen1,int ColDimen1,int ColDimen2>
    Mat<RowDimen1,ColDimen2> operator*(const Mat<RowDimen1,ColDimen1>& lmat,const Mat<ColDimen1,ColDimen2>& rmat)
    {
        Mat<RowDimen1,ColDimen2> res;

        for (int i = 0; i < ColDimen2; i++)
        {
            res.SetColumn(i,lmat*rmat.Column(i));
        }
        
        return res;
    }

    //行列式Determinant
    template <int Dimen>
    struct Det
    {
        static double Value(const Mat<Dimen,Dimen>& mat)
        {
            double res;

            for (int i = 0; i < Dimen; i++)
            {
                res+=mat[0][i]*mat.Cofactor(0,i);
            }
            
            return res;
        }
    };

    template<>
    struct Det<1>
    {
        static double Value(const Mat<1,1>& mat)
        {
            return mat[0][0];
        }
    };
    
    typedef Mat<2,2> Matrix2;
    typedef Mat<3,3> Matrix3;
    typedef Mat<4,4> Matrix4;
} // namespace Math
