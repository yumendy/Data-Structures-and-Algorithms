#ifndef DS_HOMEWORK_CYCLIST

#define DS_HOMEWORK_CYCLIST

#include <iostream>

using namespace std;

struct Node
{
	int data;
	struct Node *next;
};

struct CycList
{
	int size;
	Node *R;
};

CycList* MakeNull()
{
	CycList *list = new CycList;
	list->size = 0;
	return list;
}

void LInsert(int x, CycList *list)
{
	Node *p = new Node;
	p->data = x;
	if (list->R == NULL)
	{
		p->next = p;
		list->R = p;
	}
	else
	{
		p->next = list->R->next;
		list->R->next = p;
	}
	list->size++;
}

void RInsert(int x, CycList *list)
{
	LInsert(x, list);
	list->R = list->R->next;
	list->size++;
}

int OutQuree(int position, CycList *list)
{
	if (!list->size)
	{
		cout << "The list is empty!" << endl;
	}
	else
	{
		int i = 1;
		Node *temp = list->R->next;
		while (i != position)
		{
			i++;
			temp = temp->next;
		}
		int item = temp->data;
		cout << "The element out quree is:" << item << endl;
		Delete(item, list);
	}
}

void Delete(int x, CycList *list)
{
	if (!list->size)
	{
		cout << "The list is empty!" << endl;
	}
	else
	{
		if (list->size == 1)
		{
			delete list->R;
			list->R = NULL;
			list->size = 0;
		}
		else
		{
			Node *temp, *p;
			p = NULL;
			temp = list->R->next;
			int flag = 0;
			while (p != list->R)
			{
				if (!flag)
				{
					flag = 1;
					p = list->R;
				}
				if (temp->data == x)
				{
					p->next = temp->next;
					delete temp;
				}
				else
				{
					p = temp;
					temp = temp->next;
				}
				p = temp;
				temp = temp->next;
			}

		}
	}
}

#endif