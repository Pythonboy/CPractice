#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef int VertexType;
typedef int EdgeType;
struct ListEdgeNode
{
    int val; //代表边的下标
    struct ListEdgeNode * next;
};

struct ListVertexNode
{
    int vertex;  //代表顶点下标
    struct ListEdgeNode * FirstEdge;
};

struct GraphNode
{
    int vertexnum; //顶点数量
    int edgenum; //边数量
    struct ListVertexNode * VertexList;  //顶点表
};

typedef struct GraphNode * Graph;

void CreateGraph(Graph p)
{
    printf("请输入顶点数量和边的数量:\n");
    cin>>p->vertexnum>>p->edgenum;
    int i,j,k;
    p->VertexList = (struct ListVertexNode *)malloc(sizeof(struct ListVertexNode)*p->vertexnum);
    for(i=0 ; i<p->vertexnum ; i++)
    {
        p->VertexList[i].vertex = i;
        p->VertexList[i].FirstEdge = NULL;
    }
    printf("请输入各条边的信息:\n");
    for(i=0 ; i<p->edgenum ; i++)
    {
        cin>>j>>k;
        struct ListEdgeNode * NewEdge;
        NewEdge = (struct ListEdgeNode *)malloc(sizeof(struct ListEdgeNode));
        NewEdge->val = k;
        NewEdge->next = p->VertexList[j].FirstEdge;
        p->VertexList[j].FirstEdge = NewEdge;
    }
    printf("以下是有向图各条边的信息:\n");
    struct ListEdgeNode * Node = NULL;
    for(i=0 ; i<p->vertexnum ; i++)
    {
        if(p->VertexList[i].FirstEdge!=NULL)
            Node = p->VertexList[i].FirstEdge;
        while(Node!=NULL)
        {
            cout<<i<<"->"<<Node->val<<"\n";
            Node = Node->next;
        }
    }
}

int main()
{
    Graph g;
    g = (Graph)malloc(sizeof(struct GraphNode));
    CreateGraph(g);
    return 0;
}
