#ifndef DS_HOMEWORK03_3_4

#define DS_HOMEWORK03_3_4

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

void DeleteBT(char keyword, BTREE T);
//目的：查找并删除关键字为keyword的子树
//参数：keyword - 需要删除的子树的根节点
//		T - 需要查找的二叉树

void FreeBT(BTREE T);
//目的：递归释放子树占用的空间

void OutPutBTREE(BTREE T);
//目的：以广义表的形式输出二叉树
//参数： T - 需要输出的二叉树的指针

void CreatGeneralList(BTREE T);
//目的：为二叉树建立广义表
//参数： T - 需要建立广义表的二叉树指针

#endif