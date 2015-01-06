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

void IsBTree(BTREE T)
{
	int front = 0, rear = 0;
	BTREE querry[200];
	BTREE q;
	bool last = false;
	bool isCompBTree = true;
	if (T != NULL)
	{
		querry[++rear] = T;
		while (rear != front)
		{
			q = querry[++front];
			if (!last)
			{
				if (q->lchild != NULL && q->rchild != NULL)
				{
					querry[++rear] = q->lchild;
					querry[++rear] = q->rchild;
				}
				else if (q->lchild != NULL && q->rchild == NULL)
				{
					last = true;
					querry[++rear] = q->lchild;
				}
				else if (q->lchild == NULL && q->rchild != NULL)
				{
					last = true;
					isCompBTree = false;
					break;
				}
				else
				{
					last = true;
				}
			}
			else
			{
				if (q->lchild != NULL || q->rchild != NULL)
				{
					isCompBTree = false;
					break;
				}
			}
		}
		if (isCompBTree)
		{
			cout << "是完全二叉树" << endl;
		}
		else 
		{
			cout << "不是完全二叉树" << endl;
		}

	}
}