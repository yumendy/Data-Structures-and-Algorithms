#ifndef DS_HOMEWORK03_3_1

#define DS_HOMEWORK03_3_1

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
void PreOrder(BTREE T);
//Ŀ�ģ�����ݹ����������
//������ T - ��Ҫ�����Ķ�����T

#endif