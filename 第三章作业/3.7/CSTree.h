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
//Ŀ�ģ�����һ�ö���������
//������ T - ��Ҫ��������T

int Deepth(CSTREE T);
//Ŀ�ģ�����һ�����ĸ߶�
//������ T - ��Ҫ�鿴�߶ȵ���T
//���أ�һ�����ĸ߶�

#endif