#include "Graph.h"
#include <iostream>
#include <fstream>

using namespace std;

void CreateAdjGraph(AdjGraph *G)
{
	int head, tail, weight;
	ifstream data("data.txt");
	//cout << "������ͼ�Ķ������ͱ�����";
	cout << "���ڴ��ļ���ȡͼ����Ϣ�����Ժ�..." << endl;
	data >> G->n >> G->e;
	//cout << "������" << G->n << "���������Ϣ��";
	for (int i = 0; i < G->n; i++)
	{
		data >> G->verlist[i].vertex;
		G->verlist[i].firstedge = NULL;
	}
	//cout << "������ߣ�i,j���������Ȩֵ��" << endl;
	for (int i = 0; i < G->e; i++)
	{
		data >> tail >> head >> weight;
		EdgeNode *p = new EdgeNode;
		p->adjvex = head;
		p->cost = weight;
		p->next = G->verlist[tail].firstedge;
		G->verlist[tail].firstedge = p;
	}
	data.close();
	cout << "ͼ������ϡ�" << endl;
}

void OutPutAdjGraphOut(AdjGraph *G)
{
	int n;
	n = G->n;
	EdgeNode *temp = NULL;
	for (int i = 0; i < n; i++)
	{
		cout << G->verlist[i].vertex << ": ";
		temp = G->verlist[i].firstedge;
		if (temp == NULL)
		{
			cout << "NULL";
		}
		while (temp != NULL)
		{
			cout << "-> " << temp->adjvex << " ";
			temp = temp->next;
		}
		cout << endl;
	}
}

void OutToIn(AdjGraph *G, AdjGraph *T)
{
	int n = G->n;
	T->n = n;
	T->e = G->e;
	for (int i = 0; i < n; i++)
	{
		T->verlist[i].vertex = G->verlist[i].vertex;
		T->verlist[i].firstedge = NULL;
		for (int j = 0; j < n; j++)
		{
			if (G->verlist[j].firstedge != NULL)
			{
				EdgeNode *temp = G->verlist[j].firstedge;
				while (temp != NULL)
				{
					if (temp->adjvex == i)
					{
						EdgeNode *p = new EdgeNode;
						p->adjvex = j;
						p->cost = temp->cost;
						p->next = T->verlist[i].firstedge;
						T->verlist[i].firstedge = p;
					}
					temp = temp->next;
				}
			}
		}
	}
}

void OutPutAdjGraphIn(AdjGraph *G)
{
	int n;
	n = G->n;
	EdgeNode *temp = NULL;
	for (int i = 0; i < n; i++)
	{
		cout << G->verlist[i].vertex << ": ";
		temp = G->verlist[i].firstedge;
		if (temp == NULL)
		{
			cout << "NULL";
		}
		while (temp != NULL)
		{
			cout << "<- " << temp->adjvex << " ";
			temp = temp->next;
		}
		cout << endl;
	}
}