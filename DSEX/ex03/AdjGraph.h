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
// Ŀ�ģ���������ͼ���ڽӱ�
// ������ G - ����ͼ��ָ�롣

void CreateAdjGraph2(AdjGraph *G);
// Ŀ�ģ���������ͼ���ڽӱ�
// ������ G - ����ͼ��ָ�롣

void DFSTraverse(AdjGraph *G);
// Ŀ�ģ�������ȱ����ڽӱ�
// ������ G - ����ͼָ�롣

void DFS1(AdjGraph *G, int i, bool visited[], int dfn[], int &count);
// Ŀ�ģ���ͼ�е�һ�����㿪ʼ��������ȱ�����
// ������ G - ����ͼָ�롣
//			i - �����š�
//			visited - ���ʱ�����顣
//			dfn - ���������š�

void BFSTraverse(AdjGraph *G);
// Ŀ�ģ�������ȱ����ڽӱ�
// ������ G - ����ͼָ�롣

void BFS1(AdjGraph *G, int k, bool visited[], int bfn[], int &count);
// Ŀ�ģ���ͼ�е�һ�����㿪ʼ��������ȱ�����
// ������ G - ����ͼָ�롣
//			i - �����š�
//			visited - ���ʱ�����顣
//			dfn - �����ȹ��š�

void DFS2(AdjGraph *G);
// Ŀ�ģ���ͼ���зǵݹ��������ȱ�����
// ������ G - ����ͼָ�롣

#endif