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
		cout << "��ǰͼ���ڽӱ���ʽΪ��" << endl;
		OutPutAdjGraph(AG);
		cout << "ת��Ϊ�ڽӾ�����ʽΪ��" << endl;
		MTGraph *MT = NULL;
		MT = new MTGraph();
		AdjToMT(AG, MT);
		OutPutMTGraph(MT);
	}
	else if (choice == 2)
	{
		MTGraph *MT = NULL;
		MT = new MTGraph();
		CreateMTGraph(MT);
		cout << "��ǰͼ���ڽӾ�����ʽΪ��" << endl;
		OutPutMTGraph(MT);
		cout << "ת��Ϊ�ڽӱ���ʽΪ��" << endl;
		AdjGraph *AG = NULL;
		AG = new AdjGraph();
		MTToAdj(MT, AG);
		OutPutAdjGraph(AG);
	}
	else
	{
		goto start;
	}
	return 0;
}