#include "Graph.h"
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
start:
	cout << "1.从邻接表转换为邻接矩阵" << endl;
	cout << "2.从邻接矩阵转换为邻接表" << endl;
	cout << "请输入你的选择：";
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		AdjGraph *AG = NULL;
		AG = new AdjGraph();
		CreateAdjGraph(AG);
		Counter(AG);
	}
	else if (choice == 2)
	{
		MTGraph *MT = NULL;
		MT = new MTGraph();
		CreateMTGraph(MT);
		Counter(MT);
	}
	else
	{
		goto start;
	}
	return 0;
}