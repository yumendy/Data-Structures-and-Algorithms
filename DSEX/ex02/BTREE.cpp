#define _CRT_SECURE_NO_WARNINGS
#include "BTREE.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void CreateBT1(BTREE &T)
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
		CreateBT1(T->lchild);
		CreateBT1(T->rchild);
	}
}

BTREE CreateBT2(struct node *s[])
{
	int i, j;
	char ch;
	struct node *bt = NULL, *p = NULL;
	cin >> i >> ch;
	while(i != 0 && ch != '\0')
	{
		p = new node;
		p->data = ch;
		p->lchild = p->rchild = NULL;
		s[i] = p;
		if (i == 1)
		{
			bt = p;
		}
		else
		{
			j = i / 2;
			if (j % 2 == 0)
			{
				s[j]->lchild = p;
			}
			else
			{
				s[j]->rchild = p;
			}
		}
		cin >> i >> ch;
	}
	return bt;
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

void PreOrder1(BTREE T)
{
	if (T != NULL)
	{
		cout << T->data << ' ';
		PreOrder1(T->lchild);
		PreOrder1(T->rchild);
	}
}

void PreOrder2(BTREE T)
{
	int top = -1;
	BTREE stack[200];
	while(T != NULL || top != -1)
	{
		while(T != NULL)
		{
			cout << T->data << " ";
			stack[++top] = T;
			T = T->lchild;	
		}
		if (top != -1)
		{
			T = stack[top--];
			T = T->rchild;
		}
	}
}

void InOrder1(BTREE T)
{
	if (T != NULL)
	{
		InOrder1(T->lchild);
		cout << T->data << " ";
		InOrder1(T->rchild);
	}
}

void InOrder2(BTREE T)
{
	int top = -1;
	BTREE stack[200];
	while(T != NULL || top != -1)
	{
		while(T != NULL)
		{
			stack[++top] = T;
			T = T->lchild;
		}
		if (top != -1)
		{
			T = stack[top--];
			cout << T->data << ' ';
			T = T->rchild;
		}
	}
}

void PostOrder1(BTREE T)
{
	if (T != NULL)
	{
		PostOrder1(T->lchild);
		PostOrder1(T->rchild);
		cout << T->data << ' ';
	}
}

void PostOrder2(BTREE T)
{
	int top = -1;
	struct st_node
	{
		BTREE ptr;
		int flag;
	} stack[200];
	while(T != NULL || top != -1)
	{
		while(T != NULL)
		{
			top++;
			stack[top].ptr = T;
			stack[top].flag = 1;
			T = T->lchild;
		}
		while(top != -1 && stack[top].flag == 2)
		{
			cout << stack[top].ptr->data << ' ';
			top--;
		}
		if (top != -1)
		{
			stack[top].flag = 2;
			T = stack[top].ptr->rchild;
		}
	}
}

void LeverOrder(BTREE T)
{
	int front = 0, rear = 0;
	BTREE querry[200];
	BTREE q;
	if (T != NULL)
	{
		querry[++rear] = T;
		while(rear != front)
		{
			q = querry[++front];
			cout << q->data << ' ';
			if (q->lchild != NULL)
			{
				querry[++rear] = q->lchild;
			}
			if (q->rchild != NULL)
			{
				querry[++rear] = q->rchild;
			}
		}
	}
}

BTREE CopyBTREE(BTREE T)
{
	BTREE t = NULL;
	if (T != NULL)
	{
		t = new node;
		t->data = T->data;
		t->lchild = CopyBTREE(T->lchild);
		t->rchild = CopyBTREE(T->rchild);
	}
	return t;
}

void InOrderTh(BTREE T, BTREE &pre)
{
	if (T != NULL)
	{
		InOrderTh(T->lchild, pre);
		T->lTag = (T->lchild != NULL) ? true : false;
		T->rTag = (T->rchild != NULL) ? true : false;
		if (T->lTag == false)
		{
			T->lchild = pre;
		}
		if (pre->rTag == false)
		{
			pre->rchild = T;
		}
		pre = T;
		InOrderTh(T->rchild, pre);
	}
}

void OutPutBTREE2(BTREE T, bool tag)
{
	if (tag == true)
	{
		cout << T->data;
		if (T->lTag == true || T->rTag == true)
		{
			cout << '(';
			OutPutBTREE2(T->lchild, T->lTag);
			if (T->rTag == true)
			{
				cout << ',';
			}
			OutPutBTREE2(T->rchild, T->rTag);
			cout << ')';
		}
	}
}

void InOrderThreading(BTREE &InHEAD, BTREE T, BTREE &pre)
{
	InHEAD = new node;
	InHEAD->lTag = InHEAD->rTag = true;
	InHEAD->rchild = InHEAD;
	if (T == NULL)
	{
		InHEAD->lchild = InHEAD;
		InHEAD->lTag = false;
	} 
	else
	{
		InHEAD->lchild = T;
		pre = InHEAD;
		InOrderTh(T, pre);
		pre->rchild = InHEAD;
		pre->rTag = false;
	}
	pre = NULL;
}

BTREE InOrderNext(BTREE T)
{
	BTREE temp;
	temp = T->rchild;
	if (T->rTag)
	{
		while(temp->lTag)
		{
			temp = temp->lchild;
		}
	}
	return temp;
}

BTREE Location(char x, BTREE InHEAD)
{
	BTREE temp = InOrderNext(InHEAD);
	while(temp != InHEAD)
	{
		if (temp->data == x)
		{
			return temp;
		}
		temp = InOrderNext(temp);
	}
	return NULL;
}

BTREE PreOrderNext(BTREE T)
{
	BTREE temp;
	if (T->lTag)
	{
		temp = T->lchild;
	}
	else
	{
		temp = T;
		while(!temp->rTag)
		{
			temp = temp->rchild;
		}
		temp = temp->rchild;
	}
	return temp;
}

BTREE PostOrderNext(BTREE T, BTREE InHEAD)
{
	BTREE temp, parent;
	parent = Parent(InHEAD, T);
	if (parent == InHEAD)
	{
		temp = InHEAD;
	}
	else if (T == parent->rchild || parent->rTag == false)
	{
		temp = parent;
	}
	else
	{
		while(parent->rTag == true)
		{
			parent = parent->rchild;
			while(parent->lTag == true)
			{
				parent = parent->lchild;
			}
		}
		temp = parent;
	}
	return temp;
}

BTREE Parent(BTREE InHEAD, BTREE T)
{
	BTREE temp;
	temp = InHEAD;
	if (temp->lchild == T)
	{
		return temp;
	}
	else
	{
		temp = temp->lchild;
		while(temp->lchild != T && temp->rchild != T)
		{
			if (temp->rTag)
			{
				temp = temp->rchild;
			}
			else
			{
				temp = temp->lchild;
			}
		}
		return temp;
	}
}

void ThInOrder(BTREE InHEAD)
{
	BTREE temp = InOrderNext(InHEAD);
	while(temp != InHEAD)
	{
		cout << temp->data << " ";
		temp = InOrderNext(temp);
	}
}