#ifndef DS_EX04_BST

#define DS_EX04_BST

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

BSTNode* SearchBST(int key, BST F);
//目的：在二叉搜索树中查找关键字所在的位置
//参数： name - 需要查找的关键字
//		F - 需要查找的树
//返回：找到节点的指针，如果未找到返回NULL

void OutBST(BST F);
//目的：遍历并输出前30%的记录。
//		F - 需要遍历的二叉查找树

void TraverseBST(BST F, Record stack[],int &top);
//目的：中序遍历二叉搜索树，将结果压入stack中
//参数： F - 需要遍历的二叉搜索树
//		stack - 用于存放遍历结果的栈
//		top - 栈顶指针

void PrintResult();
//目的：打印排序结果

Record deletemin(BST &F);
//目的：返回删除节点数据后的取代数据（用于某节点左右子树均不为空时）
//参数： F - 要查找的子树F
//返回：用于取代的记录

void DeleteB(int key, BST &F);
//目的：删除指定关键字的节点
//参数： key - 所需删除节点的关键字
//		F - 所需查找的树

#endif