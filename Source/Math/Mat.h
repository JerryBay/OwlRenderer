#pragma once

#include "Vec.h"

//Matrix

namespace Math
{
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

        Mat<RowDimen, ColDimen> Adjugate() const
        {

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
    Mat<RowDimen, ColDimen> operator-(const Mat<RowDimen, ColDimen> &lmat, const Mat<RowDimen, ColDimen> &rmat)
    {
        Mat<RowDimen, ColDimen> res;

        for (int i = 0; i < RowDimen; i++)
        {
            res[i] = lmat[i] - rmat[i];
        }

        return res;
    }

    // template <int Row1,int Col1,int Row2,int Col2>
    // Mat<
} // namespace Math
