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
//�����ж�x��y�Ƿ���ͨ
int Check_DFS_Matrix(MTGraph* G,int x, int y)
{
    Found = false;
    memset(visit, 0, sizeof(visit));
    DFS_Matrix(G, x, y);
    return Found;
}

//�����ж��Ƿ����·�����ڽӾ���
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

//�����ж��Ƿ����·�����ڽӱ�
int Check_DFS_List(AdjGraph *G, int x, int y)
{
    Found = false;
    memset(visit, 0, sizeof(visit));
    DFS_List(G, x, y);
    return Found;
}

//�����ж��Ƿ����·�����ڽӱ�
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

        int vi, vj ;
		cout << "������vi �� vj(�ڽӱ������ж�)" << endl;
		cin >> vi >> vj;
		int flag = Check_DFS_List(AG, vi, vj);
		if(flag)
            cout << vi << "��" << vj<<"�����·����" <<endl;
        else
            cout << vi << "��" << vj<<"�䲻����·����" <<endl;

        cout << "������vi �� vj(�ڽӱ������ж�)" << endl;
		cin >> vi >> vj;
		flag = Check_BFS_List(AG, vi, vj);
		if(flag)
            cout << vi << "��" << vj<<"�����·����" <<endl;
        else
            cout << vi << "��" << vj<<"�䲻����·����" <<endl;

	}
	else if (choice == 2)
	{
		MTGraph *MT = NULL;
		MT = new MTGraph();
		CreateMTGraph(MT);

		cout << "������vi �� vj(�ڽӾ��������ж�)" << endl;
		int vi, vj ;
		cin >> vi >> vj;
		int flag = Check_DFS_Matrix(MT, vi, vj);
		if(flag)
            cout << vi << "��" << vj<<"�����·����" <<endl;
        else
            cout << vi << "��" << vj<<"�䲻����·����" <<endl;

        cout << "������vi �� vj(�ڽӾ��󣬹����ж�)" << endl;
		cin >> vi >> vj;
		flag = Check_BFS_Matrix(MT, vi, vj);
		if(flag)
            cout << vi << "��" << vj<<"�����·����" <<endl;
        else
            cout << vi << "��" << vj<<"�䲻����·����" <<endl;

	}
	else
	{
		goto start;
	}
	return 0;
}
