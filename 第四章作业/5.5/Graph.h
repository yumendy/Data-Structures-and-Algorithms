#ifndef DS_HOMEWORK04_5_5

#define DS_HOMEWORK04_5_5

#ifndef NUMVERTICES
#define NUMVERTICES 40
#endif

typedef char VertexData;
typedef int EdgeData;


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

void Prim(EdgeData C[NUMVERTICES][NUMVERTICES], int n);
// Ŀ�ģ�����ķ�㷨
// ������ C - �ߵ�Ȩֵ��
//		 n - ������


#endif