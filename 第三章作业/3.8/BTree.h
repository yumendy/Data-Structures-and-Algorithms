#ifndef DS_HOMEWORK03_3_8

#define DS_HOMEWORK03_3_8

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
void IsBTree(BTREE T);
//目的：判断一个树是不是完全二叉树
//参数： T - 需要判断的二叉树T

#endif