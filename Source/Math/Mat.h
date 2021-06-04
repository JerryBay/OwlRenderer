#pragma once

#include "Vec.h"

//Matrix

namespace Math
{
    template <int Row, int Col>
    struct Mat
    {
        Vec<Col> rows[Row] = {{}};

        Mat() = default;

        Vec<Col> &operator[](const int idx)
        {
            assert(idx >= 0 && idx < Row);
            return rows[idx];
        }

        const Vec<Col> &operator[](const int idx) const
        {
            assert(idx >= 0 && idx < Row);
            return rows[idx];
        }

        Vec<Row> Column(const int idx) const
        {
            assert(idx >= 0 && idx < Col);
            Vec<Row> res;

            for (int i = 0; i < Row; i++)
            {
                res[i] = rows[i][idx];
            }

            return res;
        }

        void SetColumn(const int idx, const Vec<Row> &vec)
        {
            assert(idx >= 0 && idx < Col);

            for (int i = 0; i < Row; i++)
            {
                rows[i][idx] = vec[i];
            }
        }

        Mat<Row, Col> adjugate() const
        {
        }

        static Mat<Row, Col> Identity()
        {
            Mat<Row, Col> res;

            for (int i = 0; i < Row; i++)
            {
                for (int j = 0; j < Col; j++)
                {
                    res[i][j] = (i == j);
                }
            }

            return res;
        }
    };

    template <int Row, int Col>
    std::ostream &operator<<(std::ostream &out, const Mat<Row, Col> &mat)
    {
        for (int i = 0; i < Row; i++)
        {
            out << mat[i];
        }

        return out;
    }

    template <int Row, int Col>
    Mat<Row, Col> operator+(const Mat<Row, Col> &lmat, const Mat<Row, Col> &rmat)
    {
        Mat<Row, Col> res;

        for (int i = 0; i < Row; i++)
        {
            res[i] = lmat[i] + rmat[i];
        }

        return res;
    }

    template <int Row, int Col>
    Mat<Row, Col> operator-(const Mat<Row, Col> &lmat, const Mat<Row, Col> &rmat)
    {
        Mat<Row, Col> res;

        for (int i = 0; i < Row; i++)
        {
            res[i] = lmat[i] - rmat[i];
        }

        return res;
    }

    // template <int Row1,int Col1,int Row2,int Col2>
    // Mat<
} // namespace Math
