#ifndef DS_HOMEWORK_LIST

#define DS_HOMEWORK_LIST

#define MAXSIZE 100

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;


//definition
Node SPACE[MAXSIZE];

typedef struct
{
	char element;
	int next;
} Node;

typedef int position, Cursor;
Cursor L, M, avail;

void Init();
// Purpose : Do some initialize work.

Cursor GetNode();
// Purpose : Space alocation.
// Return : The cursor of the space.

void FreeNode(Cursor q);
// Purpose : Free a node to reless the space;
// Parameters : The cursor of the node will be freed.

void Insert(char element, position p, Node *SPACE);
// Purpose : Insert an element in the list;
// Parameters : element - the element you want to insert;
//				p - the position you want to insert;
//				SPACE - the list you want to insert;

void Delete(position p, Node *SPACE);
// Purpose : Delete an element in the list.
// Parameters : p - the position of the element before you want to delete.
//				SPACE - the list you want to delete element;


//instantiation
void Init()
{
	int j;
	for ( j = 0; j < MAXSIZE - 1; j++)
	{
		SPACE[j].next = j + 1;
	}
	SPACE[j].next = -1;
	avail = 0;
}

Cursor GetNode()
{
	Cursor p;
	if (SPACE[avail].next == -1)
	{
		p = -1;
	}
	else
	{
		p = SPACE[avail].next;
		SPACE[avail].next = SPACE[p].next;
	}
	return p;
}

void FreeNode(Cursor q)
{
	SPACE[q].next = SPACE[avail].next;
	SPACE[avail].next = q;
}

void Insert(char element, position p, Node *SPACE)
{
	position q = GetNode();
	SPACE[q].element = element;
	SPACE[q].next = SPACE[p].next;
	SPACE[p].next = q;
}

void Delete(position p, Node *SPACE)
{
	position q;
	if (SPACE[p].next != -1)
	{
		q = SPACE[p].next;
		SPACE[p].next = SPACE[q].next;
		FreeNode(q);
	}
}

#endif