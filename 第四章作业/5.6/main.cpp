#include "Graph.cpp"
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int early[1000], late[1000];

void Get_Key_Path(MTGraph * G)
{
    memset(early, 0, sizeof(early)); //��¼����ڵ�i�����ʱ��
    memset(late, 0, sizeof(late));  //��¼����ڵ�j�����ʱ��

    //����Early
    for(int i = 1; i < G->n; i++)
    {
        int maxt = 0;
        for(int j = 0; j < G->n; j++)
            if(G->edge[j][i] != -1)
                if (G->edge[j][i] + early[j] > maxt)
                    maxt = G->edge[j][i] + early[j];
        early[i] = maxt;
    }
    late[G->n - 1] = early[G->n - 1];
    //����late
    for(int i = G->n - 2; i >= 0; i--)
    {
        int mint = 0x7fffffff;
        for(int j = 0; j < G->n; j++)
            if(G->edge[i][j] != -1)
                if(late[j] - G->edge[i][j] < mint)
                    mint = late[j] - G->edge[i][j];
       late[i] = mint;
    }
    for(int i = 0; i < G->n - 1; i++)
        if(late[i] == early[i])  //�ؼ�·���ϵĵ�����early[i] == late[i]
            cout << i << " -> ";
    cout << G->n - 1;
}


int main()
{
    MTGraph *MT = NULL;
    MT = new MTGraph();
    CreateMTGraph(MT);
    Get_Key_Path(MT);
	return 0;
}
