#ifndef DS_HOMEWORK05_AVL

#define DS_HOMEWORK05_AVL

bool unbalanced = false;

typedef int records;

struct node
{
	records data;
	int bf;
	node *lchild, *rchild;
};

typedef node* BST;

void AVLInsert(BST &T, records R, int &unbalanced);
//目的：在平衡二叉树中插入一个新的元素。
//参数： T - 平衡二叉树的指针
//		R - 要插入的记录值
//		unbalanced - 平衡标志

void LeftRotation(BST &T, int &unbalanced);
//目的：实现LL和LR旋转。
//参数： T - 需要旋转的平衡二叉树
//		unbalanced - 平衡标志

void RightRotation(BST &T, int &unbalanced);
//目的：实现RL和RR旋转。
//参数： T - 需要旋转的平衡二叉树
//		unbalanced - 平衡标志

#endif