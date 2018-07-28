（一）图的邻接矩阵存储
/*GraphStruct.h
* 图的邻接矩阵存储方式，结构由顶点数量、边数量、顶点集合和边集合组成。
* 其中顶点集合一维数组，根据顶点的数量动态分配数组大小。
* 边集合是二维数组，根据顶点的数量来动态分配数组大小，对于无向图来说，该邻接矩阵是对称矩阵。
* 邻接矩阵比较适用于稠密图
*/
typedef char vertexType;
typedef int edgeType;
typedef struct GraphMatrix{

    int vertexNumber;            // 顶点数量
    int edgeNumber;                // 边的数量
    vertexType *vertex;            // 顶点集合，动态数组
    edgeType** edge;            // 边集合，二维动态数组

} GraphMatrix;

void GraphMatrix_create(GraphMatrix *g);



#include <stdio.h>
#include <malloc.h>
#include"GraphStruct.h"
void GraphMatrix_create(GraphMatrix *g){

    printf("请分别输入图的顶点数量和边的数量，用空格隔开：");
    scanf("%d %d", &g->vertexNumber, &g->edgeNumber);  //将顶点数量和边的数量存储在结构体g中相应的变量
    g->vertex = (vertexType*)malloc(g->vertexNumber * sizeof(vertexType)); //为动态数组申请空间
    //二维动态数组申请空间
    g->edge = (edgeType**)malloc(g->vertexNumber * sizeof(edgeType));        
    for (int i = 0; i < g->vertexNumber; i++){
        g->edge[i] = (edgeType*)malloc(g->vertexNumber * sizeof(edgeType));
    }
    //初始化邻接矩阵的所有元素
    for (int i = 0; i < g->vertexNumber; i++){
        for (int j = 0; j < g->vertexNumber; j++)
            g->edge[i][j] = 0;
    }
    
    //输入图的信息
    for (int k = 0; k < g->edgeNumber; k++){

        int i, j;
        printf("请输入边(vi,vj)的下标, i和j，用空格隔开:");
        scanf("%d%d", &i, &j);
        g->edge[i][j] = 1;    //（i，j）和(j，i)指的是一条边
        g->edge[j][i] = 1;
    }
    
    //输出图的信息
    printf("Your graph matrix is :\n");
    for (int i = 0; i < g->vertexNumber; i++){
        for (int j = 0; j < g->vertexNumber; j++){
            printf("%d\t", g->edge[i][j]);
        }
        printf("\n");
    }

#include<stddef.h>
#include "GraphStruct.h"

int main(){
    
    GraphMatrix *gm;
    gm = (GraphMatrix *)malloc(sizeof(GraphMatrix));
    GraphMatrix_create(gm);
   10 
    return 0;
}



（二）图的邻接表存储结构
/*
 *图的另一种存储结构是邻接表

*/
typedef struct ListEdgeNode{
    int index;                    // 边的下标
    struct ListEdgeNode *next;            // 指向下一个节点的指针
}ListEdgeNode;

typedef struct ListVertexNode {
    vertexType vertex;            // 顶点
     ListEdgeNode *fistEdge;        // 指向第一条边
} ListVertexNode;

typedef struct GraphList{
    int vertexNumber;            // 顶点的数量
    int edgeNumber;                // 边的数量
    ListVertexNode *vertex;        // 顶点集合，动态数组
}GraphList;

void GraphList_create(GraphList *g);


#include<stddef.h>
#include "GraphStruct.h"

int main(){
    
    
    GraphList *gl;
    gl = (GraphList*)malloc(sizeof(GraphList));
    GraphList_create(gl);
    return 0;
}

void GraphList_create(GraphList *g){
    printf("请分别输入图的顶点数量和边的数量，用空格隔开：");
    scanf("%d %d", &g->vertexNumber, &g->edgeNumber);        //将顶点数量和边的数量存储在结构体g中相应的变量
    //为动态数组申请空间
    g->vertex = (ListVertexNode*)malloc(g->vertexNumber * sizeof(ListVertexNode));
    //初始化顶点指的第一条边
    for (int i = 0; i < g->edgeNumber; i++){
        g->vertex[i].fistEdge = NULL;
    }

    //输入图的信息
    ListEdgeNode *listEdgeNode;
    for (int k = 0; k < g->edgeNumber; k++){
        int i, j;
        printf("请输入边(vi,vj)的下标, i和j，用空格隔开:");
        scanf("%d%d", &i, &j);
        //始终将插入的节点放在顶点所指的地一条边
        listEdgeNode = (ListEdgeNode *)malloc(sizeof(ListEdgeNode));
        listEdgeNode->index = j;
        listEdgeNode->next = g->vertex[i].fistEdge;
        g->vertex[i].fistEdge = listEdgeNode;

        listEdgeNode = (ListEdgeNode*)malloc(sizeof(ListEdgeNode));
        listEdgeNode->index = i;
        listEdgeNode->next = g->vertex[j].fistEdge;
        g->vertex[j].fistEdge = listEdgeNode;

    }

    //输出图的信息
    ListEdgeNode * len = NULL;
    for (int i = 0; i < g->vertexNumber; i++){
        
        if (g->vertex[i].fistEdge != NULL)
            len = g->vertex[i].fistEdge;
        while (len!= NULL){
            printf("%d --- %d\t", i,len->index);
            len = len->next;
        }
        printf("\n");
    }
}










