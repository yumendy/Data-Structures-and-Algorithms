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
// 目的：创建有向图的邻接矩阵。
// 参数： G - 有向图的指针。

void CreateAdjGraph(AdjGraph *G);
// 目的：创建有向图的邻接表。
// 参数： G - 有向图的指针。

void Counter(AdjGraph *G);
// 目的：统计有向图邻接表的出度和入度。
// 参数： G - 有向图的指针。

void Counter(MTGraph *G);
// 目的：统计有向图邻接矩阵的出度和入度。
// 参数： G - 有向图的指针。
#endif