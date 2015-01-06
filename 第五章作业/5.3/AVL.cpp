#include "AVL.h"
#include <iostream>

using namespace std;

void AVLInsert(BST &T, records R, int &unbalanced)
{
	if (!T)
	{
		unbalanced = true;
		T = new node;
		T->data = R;
		T->lchild = T->rchild = NULL;
		T->bf = 0;
	}
	else if (R < T->data)
	{
		AVLInsert(T->lchild, R, unbalanced);
		if (unbalanced)
		{
			switch (T->bf)
			{
				case -1: 
					T->bf = 0;
					unbalanced = false;
					break;
				case 0: 
					T->bf = 1;
					break;
				case 1:
					LeftRotation(T, unbalanced);
					break;
			}
		}
	}
	else if (R > T->data)
	{
		AVLInsert(T->rchild, R, unbalanced);
		if (unbalanced)
		{
			switch (T->bf)
			{
				case -1:
					T->bf = 0;
					unbalanced = false;
					break;
				case 0:
					T->bf = -1;
					break;
				case 1:
					RightRotation(T, unbalanced);
			}
		}
	}
	else
	{
		unbalanced = false;
	}
}

void LeftRotation(BST &T, int &unbalanced)
{
	BST gc, lc;
	lc = T->lchild;
	if (lc->bf == 1)
	{
		T->lchild = lc->rchild;
		lc->rchild = T;
		T->bf = 0;
		T = lc;
	}
	else
	{
		gc = lc->rchild;
		lc->rchild = gc->lchild;
		gc->lchild = lc;
		T->lchild = gc->rchild;
		gc->rchild = T;
		switch (gc->bf)
		{
			case 1:
				T->bf = -1;
				lc->bf = 0;
				break;
			case 0:
				T->bf = lc->bf = 0;
				break;
			case -1:
				T->bf = 0;
				lc->bf = 1;
		}
		T = gc;
	}
	T->bf = 0;
	unbalanced = false;
}

void RightRotation(BST &T, int &unbalanced)
{
	BST gc, lc;
	lc = T->rchild;
	if (lc->bf == -1)
	{
		T->rchild = lc->lchild;
		lc->lchild = T;
		T->bf = 0;
		T = lc;
	}
	else
	{
		gc = lc->lchild;
		lc->lchild = gc->rchild;
		gc->rchild = lc;
		T->rchild = gc->lchild;
		gc->lchild = T;
		switch (gc->bf)
		{
			case 1:
				T->bf = 0;
				lc->bf = -1;
				break;
			case 0:
				T->bf = lc->bf = 0;
				break;
			case -1:
				T->bf = 1;
				lc->bf = 0;
				break;
		}
		T = gc;
	}
	T->bf = 0;
	unbalanced = false;
}