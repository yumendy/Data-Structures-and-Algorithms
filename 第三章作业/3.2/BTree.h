#ifndef DS_HOMEWORK03_3_2

#define DS_HOMEWORK03_3_2

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
void PostOrder(BTREE T);
//Ŀ�ģ�����ǵݹ�������������������
//������ T - ��Ҫ�����Ķ�����T

#endif