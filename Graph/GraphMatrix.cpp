#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

typedef int EdgeType;
typedef char VertexType;

typedef struct graphMatrix
{
    int VertexNum; //顶点数
    int EdgeNum;  //边数
    EdgeType ** Edge; //边数组
    VertexType * Vertex;  //顶点数组
}GraphMatrix;

void CreateGraphMatrix(GraphMatrix * g)
{
    printf("请分别输入顶点个数和边的个数：\n");
    cin>>g->VertexNum>>g->EdgeNum;
    int i,j,k;
    g->Vertex = (VertexType *)malloc(sizeof(VertexType)*g->VertexNum);
    g->Edge = (EdgeType **)malloc(sizeof(EdgeType)*g->VertexNum);
    for(i=0 ; i<g->VertexNum ; i++)
        g->Edge[i] = (EdgeType *)malloc(sizeof(EdgeType) * g->VertexNum);
    for(i=0 ; i<g->VertexNum ; i++)
    {
        for(j=0 ; j<g->VertexNum ;j++)
            g->Edge[i][j] = 0;
    }
    printf("请输入边的信息：\n");
    for(k=0 ; k<g->EdgeNum ; k++)
    {
        cin>>i>>j;
        g->Edge[i][j] = 1;
        g->Edge[j][i] = 1;
    }
    for(i=0 ; i<g->VertexNum ; i++)
    {
        for(j=0 ; j<g->VertexNum ; j++)
        {
            if(g->Edge[i][j]!=0)
            {
                printf("%d->%d\n",i,j);
            }
        }
    }
}

int main()
{
    GraphMatrix * g;
    g = (GraphMatrix *)malloc(sizeof(struct graphMatrix));
    CreateGraphMatrix(g);
    return 0;
}
