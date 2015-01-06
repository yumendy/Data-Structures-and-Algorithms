#include "CSTREE.h"
#include <iostream>

using namespace std;

void CreateCST(CSTREE &T)
{
	char childQ[100];
	int CQ_head, CQ_tail;
	CQ_head = CQ_tail = 0;

	CSTREE tempQ[200];
	int TQ_head, TQ_tail;
	TQ_head = TQ_tail = 0;

	char ch;
	CSTREE temp;
	CSTREE t;

	cout << "��������ڵ������('#'Ϊ��)�� ";
	cin >> ch;
	if (ch != '#')
	{
		T = new node;
		T->data = ch;
		T->rightsib = NULL;
		tempQ[TQ_tail++] = T;
		while (TQ_head != TQ_tail)
		{
			temp = tempQ[TQ_head++];
			cout << "����������" << temp->data << "�����к��ӽڵ㣨'#'��������" << endl;
			while (true)
			{
				cin >> ch;
				if (ch != '#')
				{
					childQ[CQ_tail++] = ch;
				}
				else
				{
					break;
				}
			}
			if (CQ_tail - CQ_head > 0)
			{
				t = temp->firstchild = new node;
				t->data = childQ[CQ_head++];
				while (CQ_head != CQ_tail)
				{
					t->rightsib = new node;
					tempQ[TQ_tail++] = t;
					t = t->rightsib;
					t->data = childQ[CQ_head++];
				}
				t->rightsib = NULL;
				tempQ[TQ_tail++] = t;
			}
			else
			{
				temp->firstchild = NULL;
			}
		}
	}
	else
	{
		T = NULL;
	}
}

CSTREE Find(char keyword, CSTREE T)
{
	int top = -1;
	CSTREE stack[200];
	while (T != NULL || top != -1)
	{
		while (T != NULL)
		{
			if (T->data == keyword)
			{
				return T;
			}
			stack[++top] = T;
			T = T->firstchild;
		}
		if (top != -1)
		{
			T = stack[top--];
			T = T->rightsib;
		}
	}
	return NULL;
}

void FindChild(CSTREE T, int n)
{
	if (T->firstchild != NULL)
	{
		if (n == 1)
		{
			cout << "Ҫ���ҵĽ���ǣ�" <<T->firstchild->data << endl;
		}
		else
		{
			CSTREE temp = T->firstchild;
			n--;
			while (n > 0)
			{
				if (temp != NULL)
				{
					temp = temp->rightsib;
				}
				else
				{
					cout << "δ�ҵ���Ҫ���ҵĺ��ӽڵ�" << endl;
					break;
				}
				n--;
			}
			if (temp != NULL)
			{
				cout << "Ҫ���ҵĽ���ǣ�" << temp->data << endl;
			}
			else
			{
				cout << "δ�ҵ���Ҫ���ҵĺ��ӽڵ�" << endl;
			}
		}
	}
	else
	{
		cout << T->data << "�ڵ�û�к��ӽڵ�" << endl;
	}
}