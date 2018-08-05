/*
广度优先搜索算法可以得到从已知源点到每个可达顶点的最短距离，此时的最短距离指的是路径上边的个数最少，使用parent数组记录当前顶点的父节点，
比如parent[u] = v表示u的父节点为v。最短路径的长度记录在d数组中，比如d[v] = 3表示从源点(s)到v的最短路径为3。最后我们使用showPath()函数把最短路径
输出。
*/

#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
 
vector<vector<int>> mGraph;//图结构
int nodeNum;//图中顶点数
int edgeNum;//图中边数
int *colour;//-1:表示该节点未被访问 0:表示该节点被发现,它的邻接点没有被访问完 1:该节点的邻接点被访问完
int *parent;//当前节点的父节点(由那个节点发现)
int *d;//源点到该节点的最短距离
 
void readGraph()
{
	fstream fin("E:\\algData\\data01.txt");//打开文件
	fin>>nodeNum>>edgeNum;//读取顶点数和边数
	mGraph.resize(nodeNum);//设置图的大小
	colour = new int[nodeNum];
	parent = new int[nodeNum];
	d = new int[nodeNum];
	int num1, num2;
	while(fin>>num1>>num2)//读取每一条边
	{
		mGraph[num1].push_back(num2);//存储边的信息
		mGraph[num2].push_back(num1);
	}
	fin.close();//关闭文件
 
	for(int i = 0; i < nodeNum; ++i)
	{
		sort(mGraph[i].begin(),mGraph[i].end());//图中节点的邻接点排序
	}
}
 
void BFS_Visit()
{
	for(int i = 0; i < nodeNum; ++i)
	{
		colour[i] = -1;//初始化-1
		parent[i] = -1;//初始化
		d[i] = 0;//初始化
	}
 
	queue<int> q;//创建一个队列
	colour[0] = 0;//该节点被发现
	q.push(0);//入队
	while(!q.empty())//判断队列是否为空
	{
		int val = q.front();//取得队头元素
		int count = mGraph[val].size();//邻接点的个数
		for(int i = 0; i < count; ++i)
		{
			int adj = mGraph[val][i];//邻接点
			if(colour[adj] == -1)//如果该节点没有被发现
			{
				colour[adj] = 0;//颜色置为0
				parent[adj] = val;//当前的父节点
				d[adj] = d[val] + 1;//父节点的距离加1
				q.push(adj);//入队
			}
		}
		colour[val] = 1;//当前节点的邻接点访问完毕
		q.pop();
	}
}
 
//输出从s到v的最短路径
void showPath(int s, int v)
{
	if(s == v)
		cout<<s<<endl;
	else if(parent[v] == -1)
	{
		cout<<"不存在路径";
		return;
	}
	else
	{
		showPath(s,parent[v]);
		cout<<v<<endl;
	}
}
 
int main(void)
{
	readGraph();
	BFS_Visit();
	showPath(0,7);
	system("pause");
	return 0;
}
