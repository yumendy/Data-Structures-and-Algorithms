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
	int i, j, w;

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

void Counter(AdjGraph *G)
{
	int degree = 0;
	EdgeNode *temp = NULL;
	cout << "出度表：" << endl;
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
	cout << "入度表：" << endl;
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
	cout << "出度表：" << endl;
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
	cout << "入度表：" << endl;
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
