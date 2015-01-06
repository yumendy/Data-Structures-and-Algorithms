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
//Ŀ�ģ��ڶ���������в���һ����¼
//������ R - ��Ҫ����ļ�¼
//		F - ��Ҫ�����¼�Ķ��������

BST CreateBST();
//Ŀ�ģ��������������
//���أ�һ������������ڵ��ָ��

void TraverseBST(BST F, Record stack[], int &top);
//Ŀ�ģ�������������������������ѹ��stack��
//������ F - ��Ҫ�����Ķ���������
//		stack - ���ڴ�ű��������ջ
//		top - ջ��ָ��

void isBST(BST F);
//Ŀ�ģ��ж��Ƿ�Ϊ���������
//������ F - ��Ҫ�жϵĶ�����

#endif