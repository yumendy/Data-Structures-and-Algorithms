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
//Ŀ�ģ��ڶ���������в���һ����¼
//������ R - ��Ҫ����ļ�¼
//		F - ��Ҫ�����¼�Ķ��������

BST CreateBST();
//Ŀ�ģ��������������
//���أ�һ������������ڵ��ָ��

BSTNode* SearchBST(int key, BST F);
//Ŀ�ģ��ڶ����������в��ҹؼ������ڵ�λ��
//������ name - ��Ҫ���ҵĹؼ���
//		F - ��Ҫ���ҵ���
//���أ��ҵ��ڵ��ָ�룬���δ�ҵ�����NULL

void OutBST(BST F);
//Ŀ�ģ����������ǰ30%�ļ�¼��
//		F - ��Ҫ�����Ķ��������

void TraverseBST(BST F, Record stack[],int &top);
//Ŀ�ģ�������������������������ѹ��stack��
//������ F - ��Ҫ�����Ķ���������
//		stack - ���ڴ�ű��������ջ
//		top - ջ��ָ��

void PrintResult();
//Ŀ�ģ���ӡ������

Record deletemin(BST &F);
//Ŀ�ģ�����ɾ���ڵ����ݺ��ȡ�����ݣ�����ĳ�ڵ�������������Ϊ��ʱ��
//������ F - Ҫ���ҵ�����F
//���أ�����ȡ���ļ�¼

void DeleteB(int key, BST &F);
//Ŀ�ģ�ɾ��ָ���ؼ��ֵĽڵ�
//������ key - ����ɾ���ڵ�Ĺؼ���
//		F - ������ҵ���

#endif