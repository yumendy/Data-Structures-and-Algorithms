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
// 目的：创建有向图的邻接表。
// 参数： G - 有向图的指针。

void OutPutAdjGraphOut(AdjGraph *G);
// 目的：输出有向图的正邻接表。
// 参数： G - 有向图的指针。

void Switcher(AdjGraph *G, AdjGraph *T);
// 目的：将有向图的正邻接表转化为逆邻接表,将逆邻接表转化为正邻接表。
// 参数： G - 源邻接表的指针
//		 T - 目标邻接表的指针

void OutPutAdjGraphIn(AdjGraph *G);
// 目的：输出有向图的逆邻接表。
// 参数： G - 有向图的指针。

#endif