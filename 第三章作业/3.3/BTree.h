#ifndef DS_HOMEWORK03_3_3

#define DS_HOMEWORK03_3_3

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

BTREE Parent(char data, BTREE T);
//Ŀ�ģ���ȡһ��Ԫ�ص�˫�׽ڵ㡣
//����: data - ��Ҫ��ȡ˫�׽ڵ��Ԫ��
//		T - ��Ҫ�����Ķ�����T
//���أ�����˫�׽ڵ��ָ�롣

#endif