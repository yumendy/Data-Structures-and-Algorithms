#include "Graph.h"
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
start:
	int choice;
	cout << "1.���ڽӱ�ת���ڽӱ�" << endl;
	cout << "2.���ڽӱ�ת���ڽӱ�" << endl;
	cout << "���������ѡ�� ";
	cin >> choice;
	if (choice == 1)
	{
		AdjGraph *G = new AdjGraph;
		CreateAdjGraph(G);
		cout << "��ǰͼ�����ڽӱ���ʽΪ��" << endl;
		OutPutAdjGraphOut(G);
		AdjGraph *T = new AdjGraph;
		Switcher(G, T);
		cout << "ת��Ϊ���ڽӱ���ʽΪ��" << endl;
		OutPutAdjGraphIn(T);
	}
	else if (choice == 2)
	{
		AdjGraph *G = new AdjGraph;
		AdjGraph *T = new AdjGraph;
		AdjGraph *M = new AdjGraph;

		CreateAdjGraph(G);
		Switcher(G, T);
		cout << "��ǰͼ�����ڽӱ���ʽΪ��" << endl;
		OutPutAdjGraphIn(T);
		cout << "ת��Ϊ���ڽӱ���ʽΪ��" << endl;
		Switcher(T, M);
		OutPutAdjGraphOut(M);
	}
	else
	{
		goto start;
	}
	return 0;
}