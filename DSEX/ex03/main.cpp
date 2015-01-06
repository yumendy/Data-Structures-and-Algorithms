#include "AdjGraph.h"
#include "MTGraph.h"
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	AdjGraph *AG = NULL;
	AG = new AdjGraph();
	cout << "创建无向图的邻接表" << endl;
	CreateAdjGraph1(AG);
	cout << "DFS无向图的邻接表" << endl;
	DFSTraverse(AG);
	cout << "BFS无向图的邻接表" << endl;
	BFSTraverse(AG);
	MTGraph *MG = NULL;
	MG = new MTGraph();
	cout << "创建无向图的邻接矩阵" << endl;
	CreateMTGraph1(MG);
	cout << "DFS无向图的邻接矩阵" << endl;
	DFSTraverse(MG);
	cout << "BFS无向图的邻接矩阵" << endl;
	BFSTraverse(MG);
	AdjGraph *AG2 = NULL;
	AG2 = new AdjGraph();
	cout << "创建有向图的邻接矩阵" << endl;
	CreateAdjGraph2(AG2);
	cout << "DFS有向图的邻接表" << endl;
	DFSTraverse(AG2);
	cout << "BFS有向图的邻接表" << endl;
	BFSTraverse(AG2);
	MTGraph *MT2 = NULL;
	MT2 = new MTGraph();
	cout << "创建有向图的邻接矩阵" << endl;
	CreateMTGraph2(MT2);
	cout << "DFS有向图的邻接矩阵" << endl;
	DFSTraverse(MT2);
	cout << "BFS有向图的邻接矩阵" << endl;
	BFSTraverse(MT2);
	return 0;
}