#include "AdjGraph.h"
#include "MTGraph.h"
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	AdjGraph *AG = NULL;
	AG = new AdjGraph();
	cout << "��������ͼ���ڽӱ�" << endl;
	CreateAdjGraph1(AG);
	cout << "DFS����ͼ���ڽӱ�" << endl;
	DFSTraverse(AG);
	cout << "BFS����ͼ���ڽӱ�" << endl;
	BFSTraverse(AG);
	MTGraph *MG = NULL;
	MG = new MTGraph();
	cout << "��������ͼ���ڽӾ���" << endl;
	CreateMTGraph1(MG);
	cout << "DFS����ͼ���ڽӾ���" << endl;
	DFSTraverse(MG);
	cout << "BFS����ͼ���ڽӾ���" << endl;
	BFSTraverse(MG);
	AdjGraph *AG2 = NULL;
	AG2 = new AdjGraph();
	cout << "��������ͼ���ڽӾ���" << endl;
	CreateAdjGraph2(AG2);
	cout << "DFS����ͼ���ڽӱ�" << endl;
	DFSTraverse(AG2);
	cout << "BFS����ͼ���ڽӱ�" << endl;
	BFSTraverse(AG2);
	MTGraph *MT2 = NULL;
	MT2 = new MTGraph();
	cout << "��������ͼ���ڽӾ���" << endl;
	CreateMTGraph2(MT2);
	cout << "DFS����ͼ���ڽӾ���" << endl;
	DFSTraverse(MT2);
	cout << "BFS����ͼ���ڽӾ���" << endl;
	BFSTraverse(MT2);
	return 0;
}