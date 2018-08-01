#include <iostream>
#include <stack>
#include <stdio.h>
#include <cstring>
#include <vector>
#define MAXN 100
using namespace std;

int Graph[MAXN][MAXN];
vector<int>Book; //用于判断顶点是否已经遍历过

void DFS(int st,int n) //非递归深度优先遍历
{
    if(Book[st])
        cout<<st<<" ";
    int i;
    for(i=1 ; i<=n ; i++)
    {
        if(Graph[st][i]==1 && !Book[i])
        {
            Book[i] = 1;
            DFS(i,n);
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
    Book[st] = 1;
    DFS(st,N);
    return 0;
}
