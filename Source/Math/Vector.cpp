#include "Vector.h"

namespace Math
{
    double Cross(const Vector2& lvec,const Vector2& rvec)
    {
        return lvec[0]*rvec[1]-lvec[1]*rvec[0];
    }
    
    Vector3 Cross(const Vector3& lvec,const Vector3& rvec)
    {
        Vector3 res;
        res[0]=lvec[1]*rvec[2]-lvec[2]*rvec[1];
        res[1]=lvec[2]*rvec[0]-lvec[0]*rvec[2];
        res[2]=lvec[0]*rvec[1]-lvec[1]*rvec[0];
        return res;
    }
} // namespace Math
