#include <iostream>
#include <queue>
#include <stdio.h>
#include <cstring>
#include <vector>
#define MAXN 100
using namespace std;

int Graph[MAXN][MAXN];
vector<int>Book; //用于判断顶点是否已经遍历过

void BFS(int st,int n) //非递归深度优先遍历
{
    int i;
    queue<int>Res;
    Res.push(st);
    Book[st] = 1;
    while(!Res.empty())
    {
        int node = Res.front();
        Res.pop();
        if(Book[node])
            cout<<node<<" ";
        for(i=1 ; i<=n ; i++)
        {
            if(Graph[node][i]==1 && !Book[i])
            {
                Book[i] = 1;
                Res.push(i);
            }
        }
    }

}

int main()
{
    printf("请输入顶点数量和边数量:\n");
    int N,K,i,j,k;
    scanf("%d %d",&N,&K);
    Book.resize(N+1);
    for(i=0 ; i<=N ; i++)
        Book[i] = 0;
    memset(Graph,0,sizeof(Graph));
    printf("请输入各条边:\n");
    for(i=0 ; i<K ; i++)
    {
        cin>>j>>k;
        Graph[j][k] = Graph[k][j] = 1;
    }
    printf("请输入起点坐标:\n");
    int st;
    cin>>st;
    BFS(st,N);
    return 0;
}
