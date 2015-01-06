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

	cout << "请输入根节点的数据('#'为空)： ";
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
			cout << "请依次输入" << temp->data << "的所有孩子节点（'#'结束）：" << endl;
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

int Deepth(CSTREE T)
{
	CSTREE temp;
	int deep, max;
	deep = max = 0;
	if (T == NULL)
	{
		return 0;
	}
	if (T->firstchild == NULL)
	{
		return 1;
	}
	for (temp = T->firstchild; temp != NULL; temp = temp->rightsib)
	{
		deep = Deepth(temp);
		if (deep > max)
		{
			max = deep;
		}
	}
	return max + 1;
}