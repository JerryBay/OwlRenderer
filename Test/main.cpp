#include <iostream>
#include "../Include/Core.h"
using namespace std;
using namespace Math;

template<typename... Types>
int add(Types... t)
{
	return (...+t);
}


template<typename T, typename... Ts>
void syszuxPrint(T arg1, Ts... arg_left){
    std::cout<<arg1<<", ";
    syszuxPrint(arg_left...);
}

int main(int argc, char** argv)
{
	double paras[3]={1.0f,2.0f,3.0f};
	Vector3 v(paras);
	cout<<v;
}