#include "Graph.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <cstdio>
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
	memset(G->edge, -1, NUMVERTICES * NUMVERTICES * sizeof(G->edge[0][0]));
	//cout << "请输入边（i,j）及上面的权值：" << endl;
	for (int k = 0; k < G->e; k++)
	{
		data >> i >> j >> w;
		G->edge[i][j] = w;
	}
	cout << "图建立完毕。" << endl;
}
