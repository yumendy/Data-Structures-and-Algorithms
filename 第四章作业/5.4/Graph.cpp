#include "Graph.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <cstdio>
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

void CreateMTGraph(MTGraph *G)
{
	int i, j, w;

	ifstream data("data.txt");
	//cout << "������ͼ�Ķ������ͱ�����";
	cout << "���ڴ��ļ���ȡͼ����Ϣ�����Ժ�...." << endl;
	data >> G->n >> G->e;
	//cout << "������" << G->n << "���������Ϣ��";
	for (int i = 0; i < G->n; i++)
	{
		data >> G->vertex[i];
	}
	memset(G->edge, 0, NUMVERTICES * NUMVERTICES * sizeof(G->edge[0][0]));
	//cout << "������ߣ�i,j���������Ȩֵ��" << endl;
	for (int k = 0; k < G->e; k++)
	{
		data >> i >> j >> w;
		G->edge[i][j] = w;
	}
	cout << "ͼ������ϡ�" << endl;
}

void Counter(AdjGraph *G)
{
	int degree = 0;
	EdgeNode *temp = NULL;
	cout << "���ȱ�" << endl;
	for (int i = 0; i < G->n; i++)
	{
		cout << G->verlist[i].vertex << ": ";
		degree = 0;
		temp = G->verlist[i].firstedge;
		while (temp != NULL)
		{
			degree++;
			temp = temp->next;
		}
		cout << degree << endl;
	}
	cout << "��ȱ�" << endl;
	for (int i = 0; i < G->n; i++)
	{
		degree = 0;
		cout << G->verlist[i].vertex << ": ";
		for (int j = 0; j < G->n; j++)
		{
			temp = G->verlist[j].firstedge;
			while (temp != NULL)
			{
				if (temp->adjvex == i)
				{
					degree++;
				}
				temp = temp->next;
			}
		}
		cout << degree << endl;
	}
}

void Counter(MTGraph *G)
{
	int degree = 0;
	cout << "���ȱ�" << endl;
	for (int i = 0; i < G->n; i++)
	{
		degree = 0;
		cout << G->vertex[i] << ":";
		for (int j = 0; j < G->n; j++)
		{
			if (G->edge[i][j])
			{
				degree++;
			}
		}
		cout << degree << endl;
	}
	cout << "��ȱ�" << endl;
	for (int i = 0; i < G->n; i++)
	{
		degree = 0;
		cout << G->vertex[i] << ":" ;
		for (int j = 0; j < G->n; j++)
		{
			if (G->edge[j][i])
			{
				degree++;
			}
		}
		cout << degree << endl;
	}
}
