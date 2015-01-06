#ifndef DS_HOMEWORK04_5_2

#define DS_HOMEWORK04_5_2

#ifndef NUMVERTICES
#define NUMVERTICES 40
#endif

typedef char VertexData;
typedef int EdgeData;

typedef struct node
{
	int adjvex;
	EdgeData cost;
	node *next;
} EdgeNode;

typedef struct
{
	VertexData vertex;
	EdgeNode *firstedge;
} VertexNode;

typedef struct
{
	VertexNode verlist[NUMVERTICES];
	int n, e;
} AdjGraph;

void CreateAdjGraph(AdjGraph *G);
// Ŀ�ģ���������ͼ���ڽӱ�
// ������ G - ����ͼ��ָ�롣

void OutPutAdjGraphOut(AdjGraph *G);
// Ŀ�ģ��������ͼ�����ڽӱ�
// ������ G - ����ͼ��ָ�롣

void Switcher(AdjGraph *G, AdjGraph *T);
// Ŀ�ģ�������ͼ�����ڽӱ�ת��Ϊ���ڽӱ�,�����ڽӱ�ת��Ϊ���ڽӱ�
// ������ G - Դ�ڽӱ��ָ��
//		 T - Ŀ���ڽӱ��ָ��

void OutPutAdjGraphIn(AdjGraph *G);
// Ŀ�ģ��������ͼ�����ڽӱ�
// ������ G - ����ͼ��ָ�롣

#endif