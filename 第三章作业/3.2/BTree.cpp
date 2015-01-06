#include "BTREE.h"
#include <iostream>

using namespace std;

void CreateBT(BTREE &T)
{
	char ch;
	cin >> ch;
	if (ch == '#')
	{
		T = NULL;
	}
	else
	{
		T = new node;
		T->data = ch;
		CreateBT(T->lchild);
		CreateBT(T->rchild);
	}
}

void PostOrder(BTREE T)
{
	int top = -1;
	struct st_node
	{
		BTREE ptr;
		int flag;
	} stack[200];
	char datastack[200];
	int data_top = -1;
	while (T != NULL || top != -1)
	{
		while (T != NULL)
		{
			top++;
			stack[top].ptr = T;
			stack[top].flag = 1;
			T = T->lchild;
		}
		while (top != -1 && stack[top].flag == 2)
		{
			datastack[++data_top] = stack[top].ptr->data;
			top--;
		}
		if (top != -1)
		{
			stack[top].flag = 2;
			T = stack[top].ptr->rchild;
		}
	}
	while (data_top > -1)
	{
		cout << datastack[data_top--] << " ";
	}
	cout << endl;
}