#include <iostream>
#include "BTREE.h"

using namespace std;

int main(int argc, char const *argv[])
{
	//����������ABDH##I##E##CF##G##
	BTREE T = NULL;
	cout << "���������뽨���Ķ�������" << endl;
	CreateBT(T);
	cout << "����ǵݹ���������������������" << endl;
	PostOrder(T);
	cout << endl;
	return 0;
}