#ifndef DS_HOMEWORK03_3_8

#define DS_HOMEWORK03_3_8

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
void IsBTree(BTREE T);
//Ŀ�ģ��ж�һ�����ǲ�����ȫ������
//������ T - ��Ҫ�жϵĶ�����T

#endif