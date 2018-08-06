/*
时间：2018/8/1
作者：楼浩然
功能：利用Kosaraju算法计算有向图的强连通分支个数
*/

#include <stack>
#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 100
using namespace std;

int Graph[MAXN][MAXN];
int NGraph[MAXN][MAXN];
int Book[MAXN];
stack<int>Res;
void DFS_1(int v,int n)
{
    Book[v] = 1;
    int i;
    for(i=1 ; i<=n ; i++)
    {
        if(Graph[v][i]==1 && !Book[i])
        {
            Book[i] = 1;
            DFS_1(i,n);
        }
    }
    Res.push(v);
}

void DFS_2(int v,int n)
{
    Book[v] = 1;
    int i;
    for(i=1 ; i<=n ; i++)
    {
        if(NGraph[v][i]==1 && !Book[i])
        {
            Book[1] = 1;
            DFS_2(i,n);
        }
    }
}

int Kosaraju(int n)
{
    int i;
    for(i=1 ; i<=n ; i++)
    {
        if(!Book[i])
        {
            DFS_1(i,n);
        }
    }
    memset(Book,0,sizeof(Book));
    int cnt = 0;
    while(!Res.empty())
    {
        int node = Res.top();
        if(!Book[node])
        {
            DFS_2(node,n);
            cnt++;
        }
        Res.pop();
    }
    return cnt;
}

int main()
{
    printf("请输入顶点数量和边数量:\n");
    int N,K,i,j,k;
    scanf("%d %d",&N,&K);
    memset(Graph,0,sizeof(Graph));
    memset(NGraph,0,sizeof(NGraph));
    memset(Book,0,sizeof(Book));
    printf("请输入各条边:\n");
    for(i=0 ; i<K ; i++)
    {
        cin>>j>>k;
        Graph[j][k] = 1;
        NGraph[k][j] = 1;
    }
    int cnt = Kosaraju(N);
    cout<<cnt;
    return 0;

}
