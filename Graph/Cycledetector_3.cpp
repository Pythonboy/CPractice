/*
时间：2018/8/6
作者：楼浩然
功能：利用拓扑排序实现有向图中是否有环的判断
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <set>
#define MAXN 100
using namespace std;

int Graph[MAXN][MAXN];
int visited[MAXN];
int Indegree[MAXN];


void TopoSort(vector<int>&R,int N)
{
    int i,j,k;
    for(k=0 ; k<N ; k++)
    {
        for(i=1 ; i<=N ; i++)
        {
            if(Indegree[i]==0)
            {
                R.push_back(i);
                Indegree[i]--;
                for(j=1 ; j<=N ; j++)
                {
                    if(Graph[i][j] == 1)
                        Indegree[j]--;
                }
                break;
            }
        }
    }
}

int main()
{
    memset(Graph,0,sizeof(Graph));
    memset(visited,0,sizeof(visited));
    memset(Indegree,0,sizeof(Indegree));
    printf("请输入顶点数量和边长数量:\n");
    int N,M;
    cin>>N>>M;
    printf("请输入边的顶点:\n");
    int i;
    for(i=0 ; i<M ; i++)
    {
        int j,k;
        cin>>j>>k;
        Graph[j][k] = 1;
        Indegree[k]++;
    }
    vector<int>Res;
    TopoSort(Res,N);
    if(Res.size() == N)
        cout<<"图中无环\n";
    else
        cout<<"图中有环\n";
    return 0;

}
