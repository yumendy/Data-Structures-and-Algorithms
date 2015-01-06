#include "Graph.h"
#include <iostream>
#include <fstream>

using namespace std;

void CreateAdjGraph(AdjGraph *G)
{
	int head, tail, weight;
	ifstream data("data.txt");
	//cout << "请输入图的顶点数和边数：";
	cout << "正在从文件读取图的信息，请稍候..." << endl;
	data >> G->n >> G->e;
	//cout << "请输入" << G->n << "个顶点的信息：";
	for (int i = 0; i < G->n; i++)
	{
		data >> G->verlist[i].vertex;
		G->verlist[i].firstedge = NULL;
	}
	//cout << "请输入边（i,j）及上面的权值：" << endl;
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
	cout << "图创建完毕。" << endl;
}

void CreateMTGraph(MTGraph *G)
{
	int i, j, k, w;

	ifstream data("data.txt");
	//cout << "请输入图的顶点数和边数：";
	cout << "正在从文件读取图的信息，请稍候...." << endl;
	data >> G->n >> G->e;
	//cout << "请输入" << G->n << "个顶点的信息：";
	for (int i = 0; i < G->n; i++)
	{
		data >> G->vertex[i];
	}
	memset(G->edge, 0, NUMVERTICES * NUMVERTICES * sizeof(G->edge[0][0]));
	//cout << "请输入边（i,j）及上面的权值：" << endl;
	for (int k = 0; k < G->e; k++)
	{
		data >> i >> j >> w;
		G->edge[i][j] = w;
	}
	cout << "图建立完毕。" << endl;
}

void OutPutAdjGraph(AdjGraph *G)
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

void OutPutMTGraph(MTGraph *G)
{
	int n;
	n = G->n;
	cout << "    ";
	for (int i = 0; i < n; i++)
	{
		cout << G->vertex[i] << "   ";
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << G->vertex[i] << "   ";
		for (int j = 0; j < n; j++)
		{
			cout << G->edge[i][j] << "   ";
		}
		cout << endl;
	}
}

void AdjToMT(AdjGraph *G, MTGraph *T)
{
	int n;
	n = G->n;
	T->n = G->n;
	T->e = T->e;
	memset(T->edge, 0, NUMVERTICES * NUMVERTICES * sizeof(T->edge[0][0]));
	EdgeNode *temp = NULL;
	for (int i = 0; i < n; i++)
	{
		temp = G->verlist[i].firstedge;
		T->vertex[i] = G->verlist[i].vertex;
		while (temp != NULL)
		{
			T->edge[i][temp->adjvex] = temp->cost;
			temp = temp->next;
		}
	}
}

void MTToAdj(MTGraph *T, AdjGraph *G)
{
	int n;
	G->n = T->n;
	G->e = T->e;
	n = T->n;
	for (int  i = 0; i < n; i++)
	{
		G->verlist[i].vertex = T->vertex[i];
		for (int j = 0; j < n; j++)
		{
			if (T->edge[i][j] != 0)
			{
				EdgeNode *p = new EdgeNode;
				p->adjvex = j;
				p->cost = T->edge[i][j];
				p->next = NULL;
				if (G->verlist[i].firstedge == NULL)
				{
					G->verlist[i].firstedge = p;
				}
				else
				{
					EdgeNode *temp = G->verlist[i].firstedge;
					while (temp->next != NULL)
					{
						temp = temp->next;
					}
					temp->next = p;
				}
			}
		}
	}
}