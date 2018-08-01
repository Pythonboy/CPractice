/*
时间：2018/8/1
作者：楼浩然
功能：利用Prim算法求得最小生成树
*/

//思路是这样的，但是运行起来有点问题，(lll￢ω￢)
#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 100
#define INF 1000
using namespace std;

int Graph[MAXN][MAXN];
int Visited[MAXN];
int Parent[MAXN];

int Prim(int N,int st)
{
    int minindex,minweight,totalweight = 0;
    int Dist[N+1];
    memset(Dist,0,sizeof(Dist));
    memset(Parent,st,sizeof(Parent));
    Visited[st] = 1;
    int i,j;
    for(i=1 ; i<=N ; i++)
    {
        if(i!=st)
            Dist[i] = Graph[st][i];
    }
    for(i=1 ; i<N ; i++)
    {
        minweight = INF;
        minindex = i;
        for(j=1 ; j<=N ; j++)
        {
            if(Visited[j]==0 && Dist[j] < minweight)
            {
                minweight = Dist[j];
                minindex = j;
            }
        }
        if(minindex == i)
        {
            printf("This is not a connected graph\n");
            return -1;
        }
        Visited[minindex] = 1;
        totalweight += minweight;
//        printf("%d -> %d : %d\n",Parent[minindex],minindex,Graph[minindex][Parent[minindex]]);
        for(j=1 ; j<=N ; j++)
        {
            if(!Visited[j] && Graph[j][minindex] < Dist[j])
            {
                Dist[j] = Graph[j][minindex];
                Parent[j] = minindex;
            }
        }

    }
    return totalweight;
}

int main()
{
    printf("请输入顶点数量和边数量:\n");
    int N,K,i,j,k,temp;
    scanf("%d %d",&N,&K);
    memset(Visited,0,sizeof(Visited));
    memset(Graph,INF,sizeof(Graph));
    printf("请输入各条边:\n");
    for(i=0 ; i<K ; i++)
    {
        cin>>j>>k>>temp;
        Graph[j][k] = Graph[k][j] = temp;
    }
    printf("请输入起点:\n");
    int st;
    cin>>st;
    int total = Prim(N,st);
    cout<<"最小生成树的权值为： "<<total;
    return 0;
}



//他山之玉
#define N 10            // 定义最大节点数，实际有几个是几个
#define MAXDIST 100        // 最大距离，表示两个节点间不可达, 为了输入方便设置成100，实际可用INT_MAX

// 为了计算方便传入的距离矩阵用指针数组的格式，n是节点数
int Prim(int (*map)[N], int n)
{
    int i, j;
    int minDist, minIndex, totalWeight;
    int *visited, *parent, *dist;    // 分别保存节点的已达标志，父节点，到树的距离

    // 申请空间并清零
    visited = (int *)malloc(n * sizeof(int));
    parent = (int *)malloc(n * sizeof(int));
    dist = (int *)malloc(n * sizeof(int));

    memset(visited, 0, n * sizeof(int));
    memset(parent, 0, n * sizeof(int));
    memset(dist, 0, n * sizeof(int));

    // 初始化，设置节点0为根节点
    visited[0] = 1;
    totalWeight = 0;

    // 初始化未达节点到树的距离
    for (i = 1; i < n; ++i)
    {
        parent[i] = 0;
        dist[i] = map[0][i];
    }

    printf("\nEdge\tWeight\n");

    // n - 1次循环找出n - 1条边
    for (i = 0; i < n - 1; ++i)
    {
        minDist = MAXDIST;
        minIndex = i;

        // 找出到树距离最小的节点
        for (j = 1; j < n; ++j)
        {
            if (visited[j] == 0 && dist[j] < MAXDIST)
            {
                minDist = dist[j];
                minIndex = j;
            }
        }

        if (minIndex == i)        // 所有节点到树的距离都为MAXDIST，说明不是连通图，返回
        {
            printf("This is not a connected graph!\n");
            return MAXDIST;
        }

        // 标记并输出找到的节点和边
        visited[minIndex] = 1;
        totalWeight += minDist;
        printf("%d-->%d\t%3d\n", parent[minIndex], minIndex, map[parent[minIndex]][minIndex]);

        // 更新剩余节点到树的距离
        for (j = 1; j < n; ++j)
        {
            if (visited[j] == 0 && map[j][minIndex] < dist[j])
            {
                parent[j] = minIndex;
                dist[j] = map[j][minIndex];
            }
        }
    }

    printf("\nTotal Weight: %d\n\n", totalWeight);

    return totalWeight;
}

int main()
{
    int map[N][N];
    int i, j;
    int n, tmp;

    printf("Num of nodes: ");
    scanf("%d", &n);

    printf("Distance matrix (lower triangular) : ");
    for (i = 1; i < n; ++i)
    {
        map[i][i] = 0;

        for (j = 0; j < i; ++j)
        {
            scanf("%d", &tmp);
            map[i][j] = tmp;
            map[j][i] = tmp;
        }
    }

    Prim(map, n);

    return 0;
}
