#include <iostream>
#include "CSTREE.h"

using namespace std;

int main(int argc, char const *argv[])
{
	//测试用树：ABC#DEF#GH##I#####
	CSTREE T = NULL;
	int d;
	CreateCST(T);
	d = Deepth(T);
	cout << "树的高度为：" << d << endl;
	return 0;
}