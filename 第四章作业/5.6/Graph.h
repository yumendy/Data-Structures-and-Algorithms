#ifndef DS_HOMEWORK04_5_3

#define DS_HOMEWORK04_5_3

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

void Counter(AdjGraph *G);
// Ŀ�ģ�ͳ������ͼ�ڽӱ�ĳ��Ⱥ���ȡ�
// ������ G - ����ͼ��ָ�롣

void Counter(MTGraph *G);
// Ŀ�ģ�ͳ������ͼ�ڽӾ���ĳ��Ⱥ���ȡ�
// ������ G - ����ͼ��ָ�롣
#endif