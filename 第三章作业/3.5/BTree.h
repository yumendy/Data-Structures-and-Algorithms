#ifndef DS_HOMEWORK03_3_5

#define DS_HOMEWORK03_3_5

#include <iostream>

using namespace std;

void CreateBT(char T[], int n);
//目的：用顺序存储的办法创建一棵二叉树
//参数： T - 需要创建的树T的引用
//		n - 树的节点个数

void PreOrder(char T[], int n, int num);
//目的：先序递归遍历二叉树
//参数： T - 需要遍历的二叉树T
//		n - 二叉树的节点数
//		num - 当前节点的编号

#endif