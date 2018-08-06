/*
例 利用 Kruskal 算法求无向网的最小生成树，并输出依次选择的各条边及最终求得的最小生成树的权。

假设数据输入时采用如下的格式进行输入：首先输入顶点个数 n 和边数 m，然后输入 m 条边的数据。每条边的数据格式为：u v w，分别表示这条边的两个顶点及边上的
权值。顶点序号从 1开始计起。

分析：

在下面的代码中，首先读入边的信息，存放到数组 edges[ ]中，并按权值从小到大进行排序。

Kruskal( )函数用于实现 ：首先初始化并查集，然后从 edges[ ]数组中依次选用每条边，如果这条边的两个顶点位于同一个连通分量，则要弃用这条边；否则合并这
两个顶点所在的连通分量。
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAXN 11  //顶点个数的最大值
#define MAXM 20  //边的个数的最大值
using namespace std; 

struct edge  //边
{
    int u, v, w; //边的顶点、权值
}edges[MAXM]; //边的数组

int parent[MAXN];  //parent[i]为顶点 i 所在集合对应的树中的根结点
int n, m;  //顶点个数、边的个数
int i, j;  //循环变量
void UFset( )  //初始化
{
    for( i=1; i<=n; i++ ) 
        parent[i] = -1;
}
int Find( int x ) //查找并返回节点 x 所属集合的根结点
{
    int s; //查找位置
    for( s=x; parent[s]>=0; s=parent[s] );
    while( s!=x ) //优化方案―压缩路径，使后续的查找操作加速。
    {
        int tmp = parent[x];
        parent[x] = s;
        x = tmp;
    }
    return s;
}

//将两个不同集合的元素进行合并，使两个集合中任两个元素都连通
void Union( int R1, int R2 )
{
    int r1 = Find(R1), r2 = Find(R2); //r1 为 R1 的根结点，r2 为 R2 的根结点
    int tmp = parent[r1] + parent[r2]; //两个集合结点个数之和(负数)
    //如果 R2 所在树结点个数 > R1 所在树结点个数(注意 parent[r1]是负数)
    if( parent[r1] > parent[r2] ) //优化方案――加权法则
    {
        parent[r1] = r2; 
        parent[r2] = tmp;
    }
    else
    {
        parent[r2] = r1; 
        parent[r1] = tmp;
    }
}
bool cmp( edge a, edge b ) //实现从小到大排序的比较函数
{
    return a.w <= b.w;
}
void Kruskal( )
{
    int sumweight = 0;  //生成树的权值
    int num = 0;  //已选用的边的数目
    int u, v;  //选用边的两个顶点
    UFset( ); //初始化 parent[]数组
    for( i=0; i<m; i++ )
    {
        u = edges[i].u; v = edges[i].v;
        if( Find(u) != Find(v) )
        {
            printf( "%d %d %d\n", u, v, edges[i].w );
            sumweight += edges[i].w; num++;
            Union( u, v );
        }
        if( num>=n-1 ) break;
    }
    printf( "weight of MST is %d\n", sumweight );
}
int main( )
{
    int u, v, w; //边的起点和终点及权值
    scanf( "%d%d", &n, &m ); //读入顶点个数 n
    for( int i=0; i<m; i++ )
    {
    scanf( "%d%d%d", &u, &v, &w ); //读入边的起点和终点
    edges[i].u = u; edges[i].v = v; edges[i].w = w;
    }
    sort(edges,edges+m,cmp);
    Kruskal();
    return 0;
}
