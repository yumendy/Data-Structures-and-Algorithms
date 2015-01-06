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

BTREE Parent(char data,BTREE T)
{
	BTREE temp = NULL;
	if (T != NULL)
	{
		if (T->lchild!= NULL)
		{
			if (T->lchild->data == data)
			{
				temp = T;
			}
		}
		if (T->rchild != NULL)
		{
			if (T->rchild->data == data)
			{
				temp = T;
			}
		}
		if (!temp)
		{
			temp = Parent(data, T->lchild);
		}
		if (!temp)
		{
			temp = Parent(data, T->rchild);
		}
	}
	return temp;
}
