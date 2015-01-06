#ifndef DS_HOMEWORK03_3_1

#define DS_HOMEWORK03_3_1

#include <iostream>

using namespace std;

struct node
{
	struct node *lchild;
	struct node *rchild;
	char data;
};

typedef struct node* BTREE;

void CreateBT(BTREE &T);
//目的：用递归的办法创建一棵二叉树
//参数： T - 需要创建的树T的引用
void PreOrder(BTREE T);
//目的：先序递归遍历二叉树
//参数： T - 需要遍历的二叉树T

#endif