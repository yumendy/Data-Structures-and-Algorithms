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
//Ŀ�ģ���ƽ��������в���һ���µ�Ԫ�ء�
//������ T - ƽ���������ָ��
//		R - Ҫ����ļ�¼ֵ
//		unbalanced - ƽ���־

void LeftRotation(BST &T, int &unbalanced);
//Ŀ�ģ�ʵ��LL��LR��ת��
//������ T - ��Ҫ��ת��ƽ�������
//		unbalanced - ƽ���־

void RightRotation(BST &T, int &unbalanced);
//Ŀ�ģ�ʵ��RL��RR��ת��
//������ T - ��Ҫ��ת��ƽ�������
//		unbalanced - ƽ���־

#endif