#ifndef DS_EX03_MTGRAPH

#define DS_EX03_MTGRAPH

#ifndef NUMVERTICES
#define NUMVERTICES 40
#endif

using namespace std;

typedef char VertexData;
typedef int EdgeData;

typedef struct 
{
	VertexData vertex[NUMVERTICES];
	EdgeData edge[NUMVERTICES][NUMVERTICES];
	int n;
	int e;
} MTGraph;


void CreateMTGraph1(MTGraph *G);
// 目的：创建无向图的邻接矩阵。
// 参数： G - 无向图的指针。

void CreateMTGraph2(MTGraph *G);
// 目的：创建有向图的邻接矩阵。
// 参数： G - 有向图的指针。

void DFSTraverse(MTGraph *G);
// 目的：深度优先遍历邻接矩阵。
// 参数： G - 无向图指针。

void DFS1(MTGraph *G, int i, bool visited[], int dfn[], int &count);
// 目的：以图中的一个顶点开始做深度优先遍历。
// 参数： G - 无向图指针。
//			i - 顶点编号。
//			visited - 访问标记数组。
//			dfn - 顶点先深编号。

void BFSTraverse(MTGraph *G);
// 目的：广度优先遍历邻接矩阵。
// 参数： G - 无向图指针。

void BFS1(MTGraph *G, int k, bool visited[], int bfn[], int &count);
// 目的：以图中的一个顶点开始做广度优先遍历。
// 参数： G - 无向图指针。
//			i - 顶点编号。
//			visited - 访问标记数组。
//			dfn - 顶点先广编号。

void DFS2(MTGraph *G);
// 目的：对图进行非递归的深度优先遍历。
// 参数： G - 无向图指针。
#endif