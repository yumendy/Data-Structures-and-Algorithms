#ifndef DS_HOMEWORK03_3_2

#define DS_HOMEWORK03_3_2

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
void PostOrder(BTREE T);
//目的：后序非递归遍历二叉树并逆序输出
//参数： T - 需要遍历的二叉树T

#endif