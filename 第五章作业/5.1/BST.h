#ifndef DS_HOMEWORK05_BST

#define DS_HOMEWORK05_BST

typedef struct
{
	char name[20];
	int score;
} Record;

typedef struct celltype
{
	Record data;
	struct celltype *lchild, *rchild;
} BSTNode;

typedef BSTNode *BST;

void Insert(Record R, BST &F);
//目的：在二叉查找树中插入一个记录
//参数： R - 需要插入的记录
//		F - 需要插入记录的二叉查找树

BST CreateBST();
//目的：创建二叉查找树
//返回：一个二叉查找树节点的指针

void TraverseBST(BST F, Record stack[], int &top);
//目的：中序遍历二叉搜索树，将结果压入stack中
//参数： F - 需要遍历的二叉搜索树
//		stack - 用于存放遍历结果的栈
//		top - 栈顶指针

void isBST(BST F);
//目的：判断是否为二叉查找树
//参数： F - 需要判断的二叉树

#endif