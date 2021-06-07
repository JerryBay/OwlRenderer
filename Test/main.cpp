#include <iostream>
#include "../Source/Core.h"
using namespace std;
using namespace Math;


static double SumOfFloat(int count, ...)
{
	va_list ap;
	double sum{ 0.f };
	va_start(ap, count);
 
	for (int i = 0; i < count; ++i) {
		sum += va_arg(ap, double);
	}
 
	va_end(ap);
 
	return sum;
}

template<int n> struct vec {
    vec() = default;
    double & operator[](const int i)       { assert(i>=0 && i<n); return data[i]; }
    double   operator[](const int i) const { assert(i>=0 && i<n); return data[i]; }
    double norm2() const { return (*this)*(*this) ; }
    double norm()  const { return std::sqrt(norm2()); }
    double data[n] = {0};
};

template<int n> vec<n> operator*(const double& rhs, const vec<n> &lhs) {
    vec<n> ret = lhs;
    for (int i=n; i--; ret[i]*=rhs);
    return ret;
}

int main(int argc,const char** argv)
{

	double nums[4]={1,2,3,4};
	Vector3 v3={1,2,3};
	Vector4 v4={2,3,4};
	// Vector2 v2(nums);
	// Vector2 v21(nums+1);

	Matrix3 m=Matrix3::Identity();

	m[0]=v3;
	m[1]=Proj<3>(v4);

	Matrix4 t={{{1,0,0,0}, v4, {0,0,1,0}, {0,0,1,1}}};

	cout<<(t);
	//system("pause");
}