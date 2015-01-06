#ifndef DS_HOMEWORK03_3_4

#define DS_HOMEWORK03_3_4

#include <iostream>

using namespace std;

struct node
{
	struct node *lchild;
	struct node *rchild;
	char data;
};

typedef struct node* BTREE;

void CreateBT(BTREE &T);
//Ŀ�ģ��õݹ�İ취����һ�ö�����
//������ T - ��Ҫ��������T������

void DeleteBT(char keyword, BTREE T);
//Ŀ�ģ����Ҳ�ɾ���ؼ���Ϊkeyword������
//������keyword - ��Ҫɾ���������ĸ��ڵ�
//		T - ��Ҫ���ҵĶ�����

void FreeBT(BTREE T);
//Ŀ�ģ��ݹ��ͷ�����ռ�õĿռ�

void OutPutBTREE(BTREE T);
//Ŀ�ģ��Թ�������ʽ���������
//������ T - ��Ҫ����Ķ�������ָ��

void CreatGeneralList(BTREE T);
//Ŀ�ģ�Ϊ���������������
//������ T - ��Ҫ���������Ķ�����ָ��

#endif