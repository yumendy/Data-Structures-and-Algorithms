#ifndef DS_EX03_ADJGRAPH

#define DS_EX03_ADJGRAPH

#ifndef NUMVERTICES
#define NUMVERTICES 40
#endif

using namespace std;

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


void CreateAdjGraph1(AdjGraph *G);
// 目的：创建无向图的邻接表。
// 参数： G - 无向图的指针。

void CreateAdjGraph2(AdjGraph *G);
// 目的：创建有向图的邻接表。
// 参数： G - 有向图的指针。

void DFSTraverse(AdjGraph *G);
// 目的：深度优先遍历邻接表。
// 参数： G - 无向图指针。

void DFS1(AdjGraph *G, int i, bool visited[], int dfn[], int &count);
// 目的：以图中的一个顶点开始做深度优先遍历。
// 参数： G - 无向图指针。
//			i - 顶点编号。
//			visited - 访问标记数组。
//			dfn - 顶点先深编号。

void BFSTraverse(AdjGraph *G);
// 目的：广度优先遍历邻接表。
// 参数： G - 无向图指针。

void BFS1(AdjGraph *G, int k, bool visited[], int bfn[], int &count);
// 目的：以图中的一个顶点开始做广度优先遍历。
// 参数： G - 无向图指针。
//			i - 顶点编号。
//			visited - 访问标记数组。
//			dfn - 顶点先广编号。

void DFS2(AdjGraph *G);
// 目的：对图进行非递归的深度优先遍历。
// 参数： G - 无向图指针。

#endif