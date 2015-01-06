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
// 目的：创建有向图的邻接矩阵。
// 参数： G - 有向图的指针。

void CreateAdjGraph(AdjGraph *G);
// 目的：创建有向图的邻接表。
// 参数： G - 有向图的指针。

void OutPutAdjGraph(AdjGraph *G);
// 目的：输出有向图的邻接表。
// 参数： G - 有向图的指针。

void OutPutMTGraph(MTGraph *G);
// 目的：输出有向图的邻接矩阵。
// 参数： G - 有向图的指针。

void AdjToMT(AdjGraph *G, MTGraph *T);
// 目的：将有向图的邻接表转化为邻接矩阵。
// 参数： G - 有向图的指针。
//		 T - 目标矩阵的指针。

void MTToAdj(MTGraph *T, AdjGraph *G);
// 目的：将有向图的邻接矩阵转化为邻接表。
// 参数： G - 目标邻接表的指针。
//		 T - 源矩阵的指针。

#endif