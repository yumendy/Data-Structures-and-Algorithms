#include "BTREE.h"
#include <iostream>

using namespace std;

void CreateBT(char T[], int n)
{
	T[0] = '#';
	cout << "�밴������������������ݣ�" << endl;
	for (int i = 1; i <= n; i++)
	{
		cin >> T[i];
	}
}

void PreOrder(char T[], int n, int num)
{
	if (num <= n)
	{
		cout << T[num] << " ";
		PreOrder(T, n, 2 * num);
		PreOrder(T, n, 2 * num + 1);
	}
}
