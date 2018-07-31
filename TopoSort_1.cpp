/*
其基本思想：

拓扑排序的基本操作为：

1.从图中选择一个入度为0的顶点并且输出它；

2.从图中删除此顶点及所有由它发出的边；

3.重复上述过程，直到图中没有入度为0的边。

以上的操作会产生两种结果：一种是图中的全部顶点都被输出，整个拓扑排序完成；另一种是图中顶点未被全部输出，剩余的顶点的入度均不为0，则说明网中存在有向环。
*
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#define MAX 100
usingnamespace std;
 
void toposort(int map[MAX][MAX],int indegree[MAX],int n)
{
    int i,j,k;
    for(i=0;i<n;i++) //遍历n次
    {
        for(j=0;j<n;j++) //找出入度为0的节点
        {
            if(indegree[j]==0)
            {
                indegree[j]--;
                cout<<j<<endl;
                for(k=0;k<n;k++) //删除与该节点关联的边
                {
                    if(map[j][k]==1)
                    {
                        indegree[k]--;
                    }
                }
                break;
            }
        }
    }
}
 
 
int main(void)
{
    int n,m; //n:关联的边数，m:节点数
    while(scanf("%d %d",&n,&m)==2&&n!=0)
    {
        int i;
        int x,y;
        int map[MAX][MAX]; //邻接矩阵
        int indegree[MAX]; //入度
        memset(map,0,sizeof(map));
        memset(indegree,0,sizeof(indegree));
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&x,&y);
            if(!map[x][y])
            {
                map[x][y]=1;
                indegree[y]++;
            }
        }
        toposort(map,indegree,m);
    }
    return0;
}
