#ifndef DS_HOMEWORK03_3_3

#define DS_HOMEWORK03_3_3

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

BTREE Parent(char data, BTREE T);
//目的：获取一个元素的双亲节点。
//参数: data - 需要获取双亲节点的元素
//		T - 需要遍历的二叉树T
//返回：返回双亲节点的指针。

#endif