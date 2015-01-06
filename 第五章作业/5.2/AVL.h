#ifndef DS_HOMEWORK05_AVL

#define DS_HOMEWORK05_AVL

struct TreeNode
{
	struct TreeNode *left;
	struct TreeNode *right;
	int key;
};

bool isAVL(TreeNode *root, int depth);
//目的：判断一棵树是不是平衡二叉树。
//参数： root - 指向树根的指针。
//		depth - 树的高度。
//返回： true - 是AVL树。
//		false - 不是AVL树。

bool isBST(TreeNode *root);
//目的：判断一棵树是不是BST。
//参数： root - 指向树根的指针。
//返回： true - 是BST。
//		false - 不是BST。

bool isBalance(TreeNode *root, int *depth);
//目的：判断是否平衡。
//参数： root - 指向树根的指针。
//		depth - 树的高度。
//返回： true - 平衡。
//		false - 不平衡。
#endif