#include <iostream>
#include "CSTREE.h"

using namespace std;

int main(int argc, char const *argv[])
{
	//����������ABC#DEF#GH##I#####
	CSTREE T = NULL;
	int d;
	CreateCST(T);
	d = Deepth(T);
	cout << "���ĸ߶�Ϊ��" << d << endl;
	return 0;
}