#include "BTREE.h"
#include <iostream>

using namespace std;

void CreateBT(char T[], int n)
{
	T[0] = '#';
	cout << "请按层序输入二叉树的数据：" << endl;
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
