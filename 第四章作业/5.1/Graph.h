#ifndef DS_HOMEWORK04_5_1

#define DS_HOMEWORK04_5_1

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

typedef struct
{
	VertexData vertex[NUMVERTICES];
	EdgeData edge[NUMVERTICES][NUMVERTICES];
	int n;
	int e;
} MTGraph;

void CreateMTGraph(MTGraph *G);
// Ŀ�ģ���������ͼ���ڽӾ���
// ������ G - ����ͼ��ָ�롣

void CreateAdjGraph(AdjGraph *G);
// Ŀ�ģ���������ͼ���ڽӱ�
// ������ G - ����ͼ��ָ�롣

void OutPutAdjGraph(AdjGraph *G);
// Ŀ�ģ��������ͼ���ڽӱ�
// ������ G - ����ͼ��ָ�롣

void OutPutMTGraph(MTGraph *G);
// Ŀ�ģ��������ͼ���ڽӾ���
// ������ G - ����ͼ��ָ�롣

void AdjToMT(AdjGraph *G, MTGraph *T);
// Ŀ�ģ�������ͼ���ڽӱ�ת��Ϊ�ڽӾ���
// ������ G - ����ͼ��ָ�롣
//		 T - Ŀ������ָ�롣

void MTToAdj(MTGraph *T, AdjGraph *G);
// Ŀ�ģ�������ͼ���ڽӾ���ת��Ϊ�ڽӱ�
// ������ G - Ŀ���ڽӱ��ָ�롣
//		 T - Դ�����ָ�롣

#endif