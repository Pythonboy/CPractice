/*
时间：2018/8/1
作者：楼浩然
功能：检测图中是否存在环
*/

#include <iostream>
#include <stack>
#include <stdio.h>
#include <cstring>
#include <vector>
#define MAXN 100
using namespace std;

int Graph[MAXN][MAXN];
vector<int>Book; //用于判断顶点是否已经遍历过
bool flag = false;
void DFS(int st,int n,int origin) //递归深度优先遍历
{
    if(Book[st])
        cout<<st<<" ";
    int i;
    for(i=1 ; i<=n ; i++)
    {
        if(Graph[st][i]==1 && !Book[i])
        {
            Book[i] = 1;
            DFS(i,n,origin);
        }
        else
        {
            if(Graph[st][i]==1 && Book[i] && i == origin)
            {
                flag = true;
                return;
            }
        }
    }
}

bool CycleDetect(int n)
{
    int i;
    for(i=1 ; i<=n ; i++)
    {
        if(!Book[i])
        {
            Book[i] = 1;
            DFS(i,n,i);
        }
    }
    return flag;
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
        Graph[j][k] = 1;
    }
    if(CycleDetect(N))
        cout<<"图中有环";
    else
        cout<<"图中无环";
    return 0;

}
