/*
时间：2018/8/1
作者：楼浩然
功能：检测图中是否存在环
*/
#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
#define MAXN 100
using namespace std;
int Graph[MAXN][MAXN];
vector<int>Book; //用于判断顶点是否已经遍历过

bool CycleDetect(int n,int st)
{
    queue<int>Res;
    int i,j;
    int father;
    Res.push(st);
    Book[st] = 1;
    while(!Res.empty())
    {
        father = Res.front();
        Res.pop();
        for(i=1 ; i<=n ; i++)
        {
            if(Graph[father][i]==1 && !Book[i])
            {
                Book[i] = 1;
                Res.push(i);
                for(j=1 ; j<=n ; j++)
                {
                    if(j!=father && Graph[i][j]==1 && Book[j])
                        return true;
                }
            }
        }
    }
    return false;
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
    printf("请输入起点：\n");
    int st;
    cin>>st;
    if(CycleDetect(N,st))
        cout<<"图中有环";
    else
        cout<<"图中无环";
    return 0;

}
