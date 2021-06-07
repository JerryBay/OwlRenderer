#include <iostream>
#include "../Source/Core.h"
using namespace std;
using namespace Math;


int main(int argc,const char** argv)
{

	// double nums[4]={1,2,3,4};
	// Vector3 v3={1,2,3};
	// Vector4 v4={2,3,4};
	// Vector2 v2(nums);
	// Vector2 v21(nums+1);

	// Matrix3 m=Matrix3::Identity();

	// m[0]=v3;
	// m[1]=Proj<3>(v4);

	// Matrix4 t={{{1,0,0,1}, {0,1,0,1}, {0,0,1,1}, {0,0,0,1}}};

	// cout<<(t.Inverse()*t);

	Model::ObjModel m(".\\body.obj");

	cout<<m.PosCount()<<endl;
	cout<<m.TriCount()<<endl;
	//system("pause");
}