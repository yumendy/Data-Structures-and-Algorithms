#include "Graph.h"
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
start:
	cout << "1.���ڽӱ�ת��Ϊ�ڽӾ���" << endl;
	cout << "2.���ڽӾ���ת��Ϊ�ڽӱ�" << endl;
	cout << "���������ѡ��";
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