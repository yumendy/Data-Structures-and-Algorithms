#ifndef DS_EX02_BTREE

#define DS_EX02_BTREE

#include <iostream>

using namespace std;

struct node
{
	struct node *lchild;
	struct node *rchild;
	bool lTag;
	bool rTag;
	char data;
};

typedef struct node* BTREE;

void CreateBT1(BTREE &T);
// Purpose :Create a BTREE with recurrence method
// Parameters : T - the pointer of a btree.

BTREE CreateBT2(struct node *s[]);
// Purpose :Create a BTREE without recurrence method;
// Parameters : s[] - the list of the node pointer.
// Retuen : The pointer to a BTREE.

void OutPutBTREE(BTREE T);
// Purpose :Out put a BTREE as general list.
// Parameters : T - the pointer of the BTREE that you want to out put.

void CreatGeneralList(BTREE T);
// Purpose :Create the general list for the tree.
// Parameters : T - the pointer of the tree.
//				position - the next position on the general list.
// 				genlist - the general list.

void PreOrder1(BTREE T);
// Purpose : Pre order to travel a tree(recurrence method).
// Parameters : T - the pointer to the tree.

void PreOrder2(BTREE T);
// Purpose : Pre order to travel a tree(not recurrence method).
// Parameters : T - the pointer to the tree.

void InOrder1(BTREE T);
// Purpose : In order to travel a tree(recurrence method).
// Parameters : T - the pointer to the tree.

void InOrder2(BTREE T);
// Purpose : In order to travel a tree(not recurrence method).
// Parameters : T - the pointer to the tree.

void PostOrder1(BTREE T);
// Purpose : Post order to travel a tree(recurrence method).
// Parameters : T - the pointer to the tree.

void PostOrder2(BTREE T);
// Purpose : Post order to travel a tree(not recurrence method).
// Parameters : T - the pointer to the tree.

void LeverOrder(BTREE T);
// Purpose : Lever order to travel a tree.
// Parameters : T - the pointer to the tree.

BTREE CopyBTREE(BTREE T);
// Purpose : To deep copy a BTREE.
// Parameters : T - the tree to copy;
// Return : The pointer to the new tree.

void InOrderTh(BTREE T, BTREE &pre);
// Purpose : In order to threading the tree.
// Parameters : T - the tree to threading.
// 				pre - temp node;

void OutPutBTREE2(BTREE T, bool tag);
// Purpose :Out put a threading BTREE as general list.
// Parameters : T - the pointer of the BTREE that you want to out put.
//				tag - the tag of the sub tree.

void InOrderThreading(BTREE &InHEAD, BTREE T, BTREE &pre);
// Purpose :Add header to a threading BTREE.
// Parameters : InHEAD - the pointer to the new header.
//				T - the tree to threading.
//				pre - temp node;

BTREE InOrderNext(BTREE T);
// Purpose : Get the next element in the threading BTREE in order.
// Parameters : T - The pointer to the tree will get the next node.
// Return : the pointer to the next element.

BTREE Location(char x, BTREE InHEAD);
// Purpose : Get the location of a element;
// Parameters : x - the element will be find;
//				InHEAD - the header of the threading BTREE.
// Return : the pointer to the element.

BTREE PreOrderNext(BTREE T);
// Purpose : Get the next element in the threading BTREE pre order.
// Parameters : T - the pointer to the node will get the next node.
// Return : the pointer to the next element.

BTREE PostOrderNext(BTREE T, BTREE InHEAD);
// Purpose : Get the next element in the threading BTREE post order.
// Parameters : T - the pointer to the node will get the next node.
//				InHEAD - the poiunter to the header of the tree.
// Return : the pointer to the next element.

BTREE Parent(BTREE InHEAD, BTREE T);
// Purpose : Get the parent node of the element.
// Parameters : InHEAD - the head of the threading BTREE
//				T - the node want to get parent.
// Return : the pointer to the parent node.

void ThInOrder(BTREE InHEAD);
// Purpose : Travel the threading tree by in order.
// Parameters : InHEAD - the head of the threading BTREE.

#endif