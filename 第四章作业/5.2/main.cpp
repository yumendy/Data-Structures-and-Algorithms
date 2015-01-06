#include "Graph.h"
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
start:
	int choice;
	cout << "1.正邻接表转逆邻接表" << endl;
	cout << "2.逆邻接表转正邻接表" << endl;
	cout << "请输入你的选择： ";
	cin >> choice;
	if (choice == 1)
	{
		AdjGraph *G = new AdjGraph;
		CreateAdjGraph(G);
		cout << "当前图的正邻接表形式为：" << endl;
		OutPutAdjGraphOut(G);
		AdjGraph *T = new AdjGraph;
		Switcher(G, T);
		cout << "转换为逆邻接表形式为：" << endl;
		OutPutAdjGraphIn(T);
	}
	else if (choice == 2)
	{
		AdjGraph *G = new AdjGraph;
		AdjGraph *T = new AdjGraph;
		AdjGraph *M = new AdjGraph;

		CreateAdjGraph(G);
		Switcher(G, T);
		cout << "当前图的逆邻接表形式为：" << endl;
		OutPutAdjGraphIn(T);
		cout << "转换为正邻接表形式为：" << endl;
		Switcher(T, M);
		OutPutAdjGraphOut(M);
	}
	else
	{
		goto start;
	}
	return 0;
}