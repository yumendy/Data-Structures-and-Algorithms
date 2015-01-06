#include "Graph.cpp"
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
bool Found, visit[1000];

void DFS_Matrix(MTGraph *G, int now, int des)
{
    if(now == des) {
        Found = true;
        return;
    }
    for(int i = 0; i < G->n; i++)
        if(G->edge[now][i] > 0 && !visit[i])
        {
            visit[i] = true;
            DFS_Matrix(G, i, des);
            if(Found) return;
        }
}
//深搜判断x与y是否联通
int Check_DFS_Matrix(MTGraph* G,int x, int y)
{
    Found = false;
    memset(visit, 0, sizeof(visit));
    DFS_Matrix(G, x, y);
    return Found;
}

//广搜判断是否存在路径，邻接矩阵
int Check_BFS_Matrix(MTGraph* G,int x, int y)
{
    queue<int> Q;
    while(!Q.empty()) Q.pop();
    Q.push(x); visit[x] = true;
    memset(visit, 0, sizeof(visit));
    Found = false;
    while(!Q.empty())
    {
        int now = Q.front(); Q.pop();
        for(int i = 0; i < G->n; i++)
            if(G->edge[now][i] > 0 && ! visit[i])
        {
            if(i == y){
                Found = true; break;
            }
            Q.push(i); visit[i] =true;
        }
        if(Found) break;
    }
    return Found;
}

void DFS_List(AdjGraph *G, int now, int des)
{
    if(now == des){
        Found = true;
        return;
    }
    EdgeNode *temp = G->verlist[now].firstedge;
    while (temp != NULL)
    {
        if(!visit[temp->adjvex])
        {
            visit[temp->adjvex] = true;
            DFS_List(G, temp->adjvex, des);
        }
        if(Found) return;
        temp = temp->next;
    }
}

//深搜判断是否存在路径，邻接表
int Check_DFS_List(AdjGraph *G, int x, int y)
{
    Found = false;
    memset(visit, 0, sizeof(visit));
    DFS_List(G, x, y);
    return Found;
}

//广搜判断是否存在路径，邻接表
int Check_BFS_List(AdjGraph *G, int x, int y)
{
    queue<int> Q;
    while(!Q.empty()) Q.pop();
    Q.push(x); visit[x] = true;
    memset(visit, 0, sizeof(visit));
    Found = false;
    while(!Q.empty())
    {
        int now = Q.front(); Q.pop();
        EdgeNode *temp = G->verlist[now].firstedge;
        while (temp != NULL)
        {
            if(!visit[temp->adjvex])
            {
                visit[temp->adjvex] = true;
                Q.push(temp->adjvex);
                visit[temp->adjvex] =true;
                if(temp->adjvex == y){
                    Found = true; break;
                }
            }
            if(Found) return true;
            temp = temp->next;
        }
    }
    return Found;
}

int main()
{
start:
	cout << "1.从邻接表转换为邻接矩阵" << endl;
	cout << "2.从邻接矩阵转换为邻接表" << endl;
	cout << "请输入你的选择：";
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		AdjGraph *AG = NULL;
		AG = new AdjGraph();
		CreateAdjGraph(AG);

        int vi, vj ;
		cout << "请输入vi 和 vj(邻接表，深搜判断)" << endl;
		cin >> vi >> vj;
		int flag = Check_DFS_List(AG, vi, vj);
		if(flag)
            cout << vi << "和" << vj<<"间存在路径！" <<endl;
        else
            cout << vi << "和" << vj<<"间不存在路径！" <<endl;

        cout << "请输入vi 和 vj(邻接表，广搜判断)" << endl;
		cin >> vi >> vj;
		flag = Check_BFS_List(AG, vi, vj);
		if(flag)
            cout << vi << "和" << vj<<"间存在路径！" <<endl;
        else
            cout << vi << "和" << vj<<"间不存在路径！" <<endl;

	}
	else if (choice == 2)
	{
		MTGraph *MT = NULL;
		MT = new MTGraph();
		CreateMTGraph(MT);

		cout << "请输入vi 和 vj(邻接矩阵，深搜判断)" << endl;
		int vi, vj ;
		cin >> vi >> vj;
		int flag = Check_DFS_Matrix(MT, vi, vj);
		if(flag)
            cout << vi << "和" << vj<<"间存在路径！" <<endl;
        else
            cout << vi << "和" << vj<<"间不存在路径！" <<endl;

        cout << "请输入vi 和 vj(邻接矩阵，广搜判断)" << endl;
		cin >> vi >> vj;
		flag = Check_BFS_Matrix(MT, vi, vj);
		if(flag)
            cout << vi << "和" << vj<<"间存在路径！" <<endl;
        else
            cout << vi << "和" << vj<<"间不存在路径！" <<endl;

	}
	else
	{
		goto start;
	}
	return 0;
}
