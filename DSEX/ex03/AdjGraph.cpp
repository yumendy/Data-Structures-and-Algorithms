#include "AdjGraph.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>

using namespace std;

void CreateAdjGraph1(AdjGraph *G)
{
	int head, tail, weight;
	ifstream data("data.txt");
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
		p = new EdgeNode;
		p->adjvex = tail;
		p->cost = weight;
		p->next = G->verlist[head].firstedge;
		G->verlist[head].firstedge = p;
	}
	data.close();
	cout << "图创建完毕" << endl;
}

void CreateAdjGraph2(AdjGraph *G)
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
	cout << "请输入边（i,j）及上面的权值：" << endl;
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

void DFSTraverse(AdjGraph *G)
{
	bool visited[NUMVERTICES];
	int bfn[NUMVERTICES];
	int count = 1;
	for (int i = 0; i < G->n; i++)
	{
		visited[i] = false;
	}
	for (int i = 0; i < G->n; i++)
	{
		if (!visited[i])
		{
			DFS1(G, i, visited, bfn, count);
		}
	}
	cout << endl;
}

void DFS1(AdjGraph *G, int i, bool visited[], int dfn[],int &count)
{
	EdgeNode *p;
	cout << G->verlist[i].vertex << " ";
	visited[i] = true;
	dfn[i] = count++;
	p = G->verlist[i].firstedge;
	while (p)
	{
		if (!visited[p->adjvex])
		{
			DFS1(G, p->adjvex, visited, dfn, count);
		}
		p = p->next;
	}
}

void BFSTraverse(AdjGraph *G)
{
	bool visited[NUMVERTICES];
	int bfn[NUMVERTICES];
	int count = 1;
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

void BFS1(AdjGraph *G, int k, bool visited[], int bfn[], int &count)
{
	int i;
	EdgeNode *p;
	int Q[200], Q_head, Q_tail;
	Q_head = Q_tail = 0;
	cout << G->verlist[k].vertex << " ";
	visited[k] = true;
	bfn[k] = count++;
	Q[Q_tail++] = k;
	while (Q_head != Q_tail)
	{
		i = Q[Q_head++];
		p = G->verlist[i].firstedge;
		while (p)
		{
			if (!visited[p->adjvex])
			{
				cout << G->verlist[p->adjvex].vertex << " ";
				visited[p->adjvex] = true;
				bfn[p->adjvex] = count++;
				Q[Q_tail++] = p->adjvex;
			}
			p = p->next;
		}
	}
}

void DFS2(AdjGraph *G)
{
	bool visited[NUMVERTICES];
	int dfn[NUMVERTICES];
	int count = 1;
	int stack[200] ,top = -1;
	EdgeNode *temp;
	for (int i = 0; i < G->n; i++)
	{
		visited[i] = false;
	}
	for (int i = 0, v = 0; i < G->n; i++)
	{
		if (!visited[v])
		{
			cout << G->verlist[v].vertex << " ";
			visited[v] = true;
			dfn[v] = count++;
			stack[++top] = v;
			temp = G->verlist[v].firstedge;
			while (temp)
			{
				v = temp->adjvex;
				if (!visited[v])
				{
					break;
				}
				else
				{
					temp = temp->next;
				}
			}
			if (!temp)
			{
				v = stack[top--];
			}
		}
		else
		{
			temp = G->verlist[v].firstedge;
			while (temp)
			{
				v = temp->adjvex;
				if (!visited[v])
				{
					break;
				}
				temp = temp->next;
			}
			if (!temp)
			{
				v = stack[top--];
			}
			i--;
		}
	}
}