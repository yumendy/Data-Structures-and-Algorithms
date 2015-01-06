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

void DeleteBT(char keyword, BTREE T)
{
	if (T != NULL)
	{
		if (T->lchild != NULL)
		{
			if (T->lchild->data == keyword)
			{
				FreeBT(T->lchild);
				delete T->lchild;
				T->lchild = NULL;
			}
			else
			{
				DeleteBT(keyword, T->lchild);
			}
		}
		if (T->rchild != NULL)
		{
			if (T->rchild->data == keyword)
			{
				FreeBT(T->rchild);
				delete T->rchild;
				T->rchild = NULL;
			}
			else
			{
				DeleteBT(keyword, T->rchild);
			}
		}
	}
}

void FreeBT(BTREE T)
{
	if (T->lchild)
	{
		if (T->lchild->lchild == NULL && T->lchild->rchild == NULL)
		{
			delete T->lchild;
			T->lchild = NULL;
		}
		else
		{
			FreeBT(T->lchild);
			delete T->lchild;
			T->lchild = NULL;
		}
	}
	if (T->rchild)
	{
		if (T->rchild->lchild == NULL && T->rchild->rchild == NULL)
		{
			delete T->rchild;
			T->rchild = NULL;
		}
		else
		{
			FreeBT(T->rchild);
			delete T->rchild;
			T->rchild = NULL;
		}
	}
}

void OutPutBTREE(BTREE T)
{
	cout << '(';
	CreatGeneralList(T);
	cout << ')' << endl;
}

void CreatGeneralList(BTREE T)
{
	if (T != NULL)
	{
		if (T->lchild == NULL && T->rchild == NULL)
		{
			cout << T->data;
		}
		else
		{
			cout << T->data << '(';
			CreatGeneralList(T->lchild);
			cout << ',';
			CreatGeneralList(T->rchild);
			cout << ')';
		}
	}
}