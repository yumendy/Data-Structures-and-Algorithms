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
// 目的：创建有向图的邻接矩阵。
// 参数： G - 有向图的指针。

void Prim(EdgeData C[NUMVERTICES][NUMVERTICES], int n);
// 目的：普里姆算法
// 参数： C - 边的权值表
//		 n - 顶点数


#endif