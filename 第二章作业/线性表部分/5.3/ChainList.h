#ifndef DS_HOMEWORK_CHAINLIST

#define DS_HOMEWORK_CHAINLIST

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;
//definition
struct node
{
	int data;
	struct node *next;
};

struct List
{
	int size;
	struct node *first;
};

node* AddEnd(List *L, int data);
// purpose :Add an element to the end of the list.
// Parameters : L - The pointer of the list.
//				data - The data you want to add.
// Return : If success return the head of the list, else return NULL;

node* AddFirst(List *L, int data);
// purpose :Add an element to the head of the list.
// Parameters : The pointer of the list.
//				data - The data you want to add.
// Return : If success return the head of the list, else return NULL;

node* Find(List *L, int data);
// purpose :Find the element in the list according to the data.
// Parameters : The pointer of the list.
//				data - The data you want to find.
// Return : If find return the pointer, else return NULL.

node* Insert(List *L, int key, int data);
// purpose :Insert an element after the key node.
// Parameters : The pointer of the list.
//				key - The key to find in the list to find the position.
//				data - The data you want to insert.
// Return : The pointer of the list.

int Delete(List *L, int key);
// purpose : Delete an element in the list.
// Parameters : The pointer of the list.
//				key - The key of the node you want to del.
// Return : 0 - delete failed.
//			1 = delete success.

int Length(List *L);
// purpose : Get the length of the list.
// Parameters : The pointer of the list.
// Return : The length of the list.

//instantiation
node* AddEnd(List *L, int date)
{
	node* temp = new node;
	node* pt;
	temp->data = date;
	temp->next = NULL;
	L->size++;
	if (L->first == NULL)
	{
		L->first = temp;
		return L->first;
	}
	pt = L->first;
	while (pt->next != NULL)
	{
		pt = pt->next;
	}
	pt->next = temp;
	return L->first;
}

node* AddFirst(List *L, int data)
{
	node* temp = new node;
	temp->data = data;
	temp->next = L->first;
	L->first = temp;
	L->size++;
	return L->first;
}

node* Find(List *L, int key, int &num)
{
	num = 1;
	node *temp = L->first;
	while (temp != NULL)
	{
		if (temp->data == key)
		{
			return temp;
		}
		else
		{
			temp = temp->next;
			num++;
		}
	}
	return NULL;
}

node *Insert(List *L, int key, int data)
{
	node *temp, *position;
	temp = new node;
	temp->data = data;
	int n = 0;
	position = Find(L, key, n);
	if (position != NULL)
	{
		temp->next = position->next;
		position->next = temp;
	}
	else
	{
		delete temp;
		cout << "Not find the insert position!" << endl;
	}
	return L->first;
}

int Delete(List *L, int key)
{
	node *temp, *pt;
	if (L->first->data == key)
	{
		temp = L->first;
		L->first = temp->next;
		delete temp;
		L->size--;
	}
	else
	{
		temp = pt = L->first->next;
		while (temp != NULL)
		{
			if (temp->data == key)
			{
				pt->next = temp->next;
				delete temp;
				L->size--;
				return 1;
			}
			else
			{
				pt = temp;
				temp = temp->next;
			}
		}
	}
	
	return 0;
}

int Length(List* L)
{
	node *temp = L->first;
	int i = 0;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return i;
}

void Output(List* L)
{
	node *temp = L->first;
	cout << "< ";
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << ">" << endl;
}

#endif