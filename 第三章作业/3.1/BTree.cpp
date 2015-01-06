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

void PreOrder(BTREE T)
{
	if (T != NULL)
	{
		if (T->lchild == NULL && T->rchild == NULL)
		{
			cout << T->data << ' ';
		}
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
