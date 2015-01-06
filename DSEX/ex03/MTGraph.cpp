#include "MTGraph.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>

using namespace std;

void CreateMTGraph1(MTGraph *G)
{
	int i, j, w;

	//cout << "������ͼ�Ķ������ͱ�����";
	cout << "���ڴ��ļ��ж�ȡͼ����Ϣ�����Ժ�...." << endl;
	ifstream data("data.txt");
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
		G->edge[j][i] = w;
	}
	data.close();
	cout << "ͼ�����ɹ�" << endl;
}

void CreateMTGraph2(MTGraph *G)
{
	int i, j, k, w;

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

void DFSTraverse(MTGraph *G)
{
	bool visited[NUMVERTICES];
	int dfn[NUMVERTICES];
	int i, count = 1;
	for (int i = 0; i < G->n; i++)
	{
		visited[i] = false;
	}
	for (int i = 0; i < G->n; i++)
	{
		if (!visited[i])
		{
			DFS1(G, i, visited, dfn, count);
		}
	}
	cout << endl;
}

void DFS1(MTGraph *G, int i, bool visited[], int dfn[], int &count)
{
	int j;
	cout << G->vertex[i] << " ";
	visited[i] = true;
	dfn[i] = count++;
	for (int j = 0; j < G->n; j++)
	{
		if ((G->edge[i][j] == 1) && !visited[j] )
		{
			DFS1(G, j, visited, dfn, count);
		}
	}
}

void BFSTraverse(MTGraph *G)
{
	bool visited[NUMVERTICES];
	int bfn[NUMVERTICES];
	int i, count = 1;
	for (int i = 0; i < G->n; i++)
	{
		visited[i] = false;
	}
	for (int i = 0; i < G->n; i++)
	{
		if (!visited[i])
		{
			BFS1(G, i, visited, bfn, count);
		}
	}
	cout << endl;
}

void BFS1(MTGraph *G, int k, bool visited[], int bfn[], int &count)
{
	int i;
	int Q[200], Q_head, Q_tail;
	Q_head = Q_tail = 0;
	cout << G->vertex[k] << " ";
	visited[k] = true;
	bfn[k] = count++;
	Q[Q_tail] = k;
	while (Q_head != Q_tail)
	{
		i = Q[Q_head++];
		for (int j = 0; j < G->n; j++)
		{
			if (G->edge[i][j] == 1 && !visited[j])
			{
				cout << G->vertex[j] << " ";
				visited[j] = true;
				bfn[j] = count++;
				Q[Q_tail++] = j;
			}
		}
	}
}

void DFS2(MTGraph *G)
{
	bool visited[NUMVERTICES];
	int dfn[NUMVERTICES];
	int count = 1;
	int v;
	int stack[200], top = -1;
	int temp;

	for (int i = 0; i < G->n; i++)
	{
		visited[i] = false;
	}
	v = 0;
	cout << G->vertex[v] << " ";
	visited[v] = true;
	dfn[v] = count++;
	stack[++top] = v;
	int j;
	while (top >= 0)
	{
		v = stack[top];
		for (j = 0; j < G->n; j++)
		{
			if (G->edge[v][j] == 1 && !visited[j])
			{
				cout << G->vertex[j] << " ";
				visited[j] = true;
				dfn[j] = count++;
				stack[++top] = j;
				break;
			}
		}
		if (j == G->n)
		{
			top--;
		}
	}
}