#ifndef DS_HOMEWORK03_3_7

#define DS_HOMEWORK03_3_7

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

int Deepth(CSTREE T);
//目的：返回一个树的高度
//参数： T - 需要查看高度的树T
//返回：一个树的高度

#endif