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
// Ŀ�ģ���������ͼ���ڽӾ���
// ������ G - ����ͼ��ָ�롣

void CreateMTGraph2(MTGraph *G);
// Ŀ�ģ���������ͼ���ڽӾ���
// ������ G - ����ͼ��ָ�롣

void DFSTraverse(MTGraph *G);
// Ŀ�ģ�������ȱ����ڽӾ���
// ������ G - ����ͼָ�롣

void DFS1(MTGraph *G, int i, bool visited[], int dfn[], int &count);
// Ŀ�ģ���ͼ�е�һ�����㿪ʼ��������ȱ�����
// ������ G - ����ͼָ�롣
//			i - �����š�
//			visited - ���ʱ�����顣
//			dfn - ���������š�

void BFSTraverse(MTGraph *G);
// Ŀ�ģ�������ȱ����ڽӾ���
// ������ G - ����ͼָ�롣

void BFS1(MTGraph *G, int k, bool visited[], int bfn[], int &count);
// Ŀ�ģ���ͼ�е�һ�����㿪ʼ��������ȱ�����
// ������ G - ����ͼָ�롣
//			i - �����š�
//			visited - ���ʱ�����顣
//			dfn - �����ȹ��š�

void DFS2(MTGraph *G);
// Ŀ�ģ���ͼ���зǵݹ��������ȱ�����
// ������ G - ����ͼָ�롣
#endif