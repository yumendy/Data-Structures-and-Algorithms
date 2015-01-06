#ifndef DS_HOMEWORK03_3_6

#define DS_HOMEWORK03_3_6

struct node
{
	struct node *firstchild;
	struct node *rightsib;
	char data;
};

typedef struct node* CSTREE;

void CreateCST(CSTREE &T);
//目的：构造一棵二叉链表树
//参数： T - 需要创建的树T

CSTREE Find(char keyword, CSTREE T);
//目的：先序遍历二叉树返回所需查找的节点指针
//参数： keyword - 所需查找的关键字
//		T - 所需查找的树
//返回：找到的节点的指针

void FindChild(CSTREE T, int n);
//目的：输出某子树的第n个孩子的值
//参数： T - 所需查找的子树
//		n - 孩子节点的序号

#endif