#include <iostream>
#include "BTREE.h"

#define MAXNUM 40

using namespace std;

int main(int argc, char const *argv[])
{
	//����������ABCDEFGHI
	char T[MAXNUM];
	int n;
	cout << "���������Ľڵ����� ";
	cin >> n;
	CreateBT(T, n);
	cout << "�ݹ������������ӡ�������Ľڵ㣺" << endl;
	PreOrder(T, n, 1);
	cout << endl;
	return 0;
}