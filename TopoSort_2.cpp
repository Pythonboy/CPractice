#include <iostream>
#include <queue>
#include <stack>
 
#define Max_V 100   // 最大顶点数 
using namespace std;
 
typedef struct node
{
	int vtex;           //邻接点
	int weight;         //权值 
	struct node *next;  //链域 
} EdgeNode; 
 
typedef struct vnode    //顶点边结点  
{  
    int vertex;         //顶点域
	int InDegree;       //表示该顶点的入度  
    EdgeNode *firstedge;//边表头指针  
} VertexNode;  
 
typedef VertexNode List[Max_V];   //List是邻接表类型  
 
typedef struct graph    //图的结构 
{  
    List adjlist;       //邻接表  
    int v,e;            //图中当前顶点数和边数  
} MGraph;                
 
void CreateGragh(MGraph *G)
{
	cout << "输入顶点数及边数:" << endl;
	cin >> G->v >> G->e;
		
	cout << "输入顶点信息:" << endl;
	int i;
	for (i = 0; i < G->v; i++)
	{
		cin >> G->adjlist[i].vertex;
		G->adjlist[i].firstedge = NULL;
	}
	
	cout << "输入边的信息:" << endl;
	
	int v1,v2;
	EdgeNode *temp;
	
	for (i = 0; i < G->v; i++)        //初始化令所有顶点的入度为0 
	{		
		G->adjlist[i].InDegree = 0; 
	}
	
	for (int k = 0; k < G->e; k++)
	{
		cin >> v1 >> v2;
		temp = new EdgeNode;
		temp->vtex = v2;
		temp->next = G->adjlist[v1].firstedge;
		G->adjlist[v1].firstedge = temp;
		G->adjlist[v2].InDegree++;             //入度+1 
		/*无向图
		temp = new EdgeNode;
		temp->vtex = v1;
		temp->next = G->adjlist[v2].firstedge;
		G->adjlist[v2].firstedge = temp;		
		*/ 
	} 	
}
 
void Degree(MGraph *G)
{
	int i;
	cout << "各顶点初始入度:" << endl;
	for(i = 0; i < G->v; i++)
	{
		cout << G->adjlist[i].InDegree << " " ;
	}
	cout << endl;
}
 
 
void TopoOrder(MGraph *G)
{
	stack<int> S;        //建立空队列 
	int NodeCount;
	int v,w;
	
	cout << "拓扑序列:" << endl; 
	
	for(int i = 0; i < G->v; i++)
	{
		if(G->adjlist[i].InDegree == 0)
		  S.push(i);
	} 
	
	NodeCount = 0;       //顶点计数器置为0
	
	while( !S.empty() )
	{
		v = S.top();
		S.pop();
		cout << v << " " ;   //输出拓扑排序序列 
		
		NodeCount++;
		
		EdgeNode *temp;
		temp = G->adjlist[v].firstedge;
		while(temp != NULL)
		{
			
			G->adjlist[temp->vtex].InDegree--;
			
			if(G->adjlist[temp->vtex].InDegree == 0)
			  S.push(temp->vtex);
	        
	        temp = temp->next;
		}
		
	} 
	
	if(NodeCount < 0)
	{
		cout << "There is cycle on the digragh";
	}
	
} 
 
int main()
{
	MGraph *G;
	G = new MGraph; //注意初始化 
	CreateGragh(G);
	Degree(G);
	TopoOrder(G); 
	cout << endl;
	return 0;
}
