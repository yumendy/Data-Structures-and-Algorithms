#include "Graph.h"
#include <iostream>
#include <fstream>

using namespace std;

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
		G->edge[j][i] = w;
	}
	data.close();
	cout << "图建立完毕。" << endl;
}

void Prim(EdgeData C[NUMVERTICES][NUMVERTICES], int n)
{
	EdgeData LOWCOST[NUMVERTICES];
	int CLOSSET[NUMVERTICES];
	int k;
	EdgeData min;
	for (int i = 2; i <= n; i++)
	{
		LOWCOST[i] = C[1][i];
		CLOSSET[i] = 1;
	}
	for (int i = 2; i <= n; i++)
	{
		min = LOWCOST[i];
		k = i;
		for (int j = 2; j < n; j++)
		{
			if (LOWCOST[j] < min)
			{
				min = LOWCOST[j];
				k = j;
			}
		}
		cout << "(" << k << "," << CLOSSET[k] << ")" << endl;
		LOWCOST[k] = INFINITY;
		for (int j = 2; j < n; j++)
		{
			if (C[k][j] < LOWCOST[j] && LOWCOST[j] < INFINITY)
			{
				LOWCOST[j] = C[k][j];
				CLOSSET[j] = k;
			}
		}
	}
}