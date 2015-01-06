#ifndef DS_HOMEWORK03_3_6

#define DS_HOMEWORK03_3_6

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

CSTREE Find(char keyword, CSTREE T);
//Ŀ�ģ������������������������ҵĽڵ�ָ��
//������ keyword - ������ҵĹؼ���
//		T - ������ҵ���
//���أ��ҵ��Ľڵ��ָ��

void FindChild(CSTREE T, int n);
//Ŀ�ģ����ĳ�����ĵ�n�����ӵ�ֵ
//������ T - ������ҵ�����
//		n - ���ӽڵ�����

#endif