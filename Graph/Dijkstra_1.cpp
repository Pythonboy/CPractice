/*
迪杰斯特拉算法（解决单源最短路径）
基本思想：每次找到离源点（如1号结点）最近的一个顶点，然后以该顶点为中心进行扩展，最终得到源点到其余所有点的最短路径。
基本步骤：1，设置标记数组book[]：将所有的顶点分为两部分,已知最短路径的顶点集合P和未知最短路径的顶点集合Q，很显然最开始集合P只有源点一个顶点。
book[i]为1表示在集合P中；
2，设置最短路径数组dst[]并不断更新：初始状态下，令dst[i] = edge[s][i](s为源点，edge为邻接矩阵)，很显然此时dst[s]=0，book[s]=1。此时，在集合Q中可
选择一个离源点s最近的顶点u加入到P中。并依据以u为新的中心点，对每一条边进行松弛操作(松弛是指由结点s-->j的途中可以经过点u，并令dst[j]=min{dst[j], 
dst[u]+edge[u][j]})，并令book[u]=1;
3，在集合Q中再次选择一个离源点s最近的顶点v加入到P中。并依据v为新的中心点，对每一条边进行松弛操作(即dst[j]=min{dst[j], dst[v]+edge[v][j]}),
并令book[v]=1;
4，重复3，直至集合Q为空。

核心代码：
#define inf 99999999
/***构建邻接矩阵edge[][],且1为源点***/
for(i = 1; i <= n; i++) dst[i] = edge[1][s]；
for(i = 1; i <= n; i++) book[i] = 0;
book[1] = 1;
for(i = 1; i <= n-1; i++){
	//找到离源点最近的顶点u，称它为新中心点
	min = inf;
	for(j = 1; j <= n; j++){
		if(book[j] == 0 && dst[j] < min){
			min = dst[j];
			u = j;
		}
	}
	book[u] = 1;
	//更新最短路径数组
	for(k = 1; k <= n; k++){
		if(edge[u][k] < inf && book[k] == 0){
			if(dst[k] > dst[u] + edge[u][k])
				dst[k] = dst[u] + edge[u][k];			
		}
	}

*/

/*
例1：给你n个点，m条无向边，每条边都有长度d和花费p，给你起点s，终点t，要求输出起点到终点的最短距离及其花费，如果最短距离有多条路线，则输出花费最少的。
输入：输入n,m，点的编号是1~n,然后是m行，每行4个数 a,b,d,p，表示a和b之间有一条边，且其长度为d，花费为p。最后一行是两个数s,t;起点s，终点 t。n和m为
0 时输入结束。(1<n<=1000, 0<m<100000, s != t)
输出：输出一行，有两个数， 最短距离及其花费。
分析：由于每条边有长度d和花费p，最好构建边结构体存放，此外可以使用邻接链表，使用邻接链表时需要将上面的核心代码修改几个地方：
1，初始化dst[]时使用结点1的邻接链表；
2，更新最短路径数组时，k的范围由1~n变为1~edge[u].size()。先采用邻接矩阵解决此题，再使用邻接表解决此题，两种方法的思路都一样：初始化邻接矩阵或邻接
链表，并
初始化最短路径数组dst ----> n-1轮边的松弛中，先找到离新源点最近的中心点u，之后根据中心点u为转折点来更新路径数组。
*/

//使用邻接矩阵求解：

/***对于无向图，输入n,m，点的编号是1~n,然后是m行，每行4个数 a,b,d,p，表示a和b之间有一条边，且其长度为d，花费为p。最后一行是两个数s,t;起点s，终点 t。***/
/***n和m为 0 时输入结束。(1<n<=1000, 0<m<100000, s != t)     输出：输出一行，有两个数， 最短距离及其花费。***/
#include <iostream>
#include <iomanip>
using namespace std;
#define nmax 1001
#define inf 99999999
struct Edge{
	int len;
	int cost;
};
Edge edge[nmax][nmax];
int dst[nmax], spend[nmax], book[nmax], n, m, stNode, enNode;
int main(){
	while(cin >> n >> m && n != 0 && m != 0){
		int a, b, i, j;
		//构建邻接矩阵和最短路径数组
		for(i = 1; i <= n; i++){
			for(j = 1; j <= n; j++){
				edge[i][j].cost = 0;
				edge[i][j].len = inf;
			}
			edge[i][i].len = 0;
		}
		while(m--){
			cin >> a >> b;
			cin >> edge[a][b].len >> edge[a][b].cost;
			edge[b][a].len = edge[a][b].len;
			edge[b][a].cost = edge[a][b].cost;
		}
		cin >> stNode >> enNode;
		for(i = 1; i <= n; i++){
			dst[i] = edge[stNode][i].len;
			spend[i] = edge[stNode][i].cost;
		}
		memset(book, 0, sizeof(book));
		book[stNode] = 1;
		//开始迪杰斯特拉算法，进行剩余n-1次松弛
		int k;
		for(k = 1; k <= n-1; k++){
			//找离源点最近的顶点u
			int minNode, min = inf;
			for(i = 1; i <= n; i++){
				if(book[i] == 0 && min > dst[i] /* || min == dst[i]&& edge[stNode][min].cost > edge[stNode][i].cost*/){
					min = dst[i];
					minNode = i;
				}
			}
			//cout << setw(2) << minNode;
			book[minNode] = 1;//易错点1，错写成book[i]=1
			//以中心点u为转折点来更新路径数组和花费数组
			for(i = 1; i <= n; i++){
				if(book[i] == 0 && dst[i] > dst[minNode] + edge[minNode][i].len || dst[i] == dst[minNode] + edge[minNode][i].len && spend[i] > spend[minNode] + edge[minNode][i].cost){
					dst[i] = dst[minNode] + edge[minNode][i].len;//易错点2，错写成dst[i]+
					spend[i] = spend[minNode] + edge[minNode][i].cost;
				}
			}
		}
		cout << dst[enNode] << setw(3) << spend[enNode] << endl;
	}
	return 0;
}


//使用邻接表
/***对于无向图，输入n,m，点的编号是1~n,然后是m行，每行4个数 a,b,d,p，表示a和b之间有一条边，且其长度为d，花费为p。最后一行是两个数s,t;起点s，终点 t。***/
/***n和m为 0 时输入结束。(1<n<=1000, 0<m<100000, s != t)     输出：输出一行，有两个数， 最短距离及其花费。***/
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
#define nmax 1001
#define inf 99999999
struct Edge{
	int len;
	int cost;
	int next;
};
vector<Edge> edge[nmax];
int dst[nmax], spend[nmax], book[nmax], n, m, stNode, enNode;
int main(){
	while(cin >> n >> m && n != 0 && m != 0){
		int a, b, i, j;
		//构建邻接表和最短路径数组
		for(i = 1; i <= n; i++) edge[i].clear();
		while(m--){
			Edge tmp;
			cin >> a >> b;
			tmp.next = b;
			cin >> tmp.len >> tmp.cost;
			edge[a].push_back(tmp);
			tmp.next = a;
			edge[b].push_back(tmp);
		}
		cin >> stNode >> enNode;
		for(i = 1; i <= n; i++) dst[i] = inf; //注意2，别忘记写此句来初始化dst[]
		for(i = 0; i < edge[stNode].size(); i++){//注意1，从下标0开始存元素，误写成i <= edge[stNode].size()
			dst[edge[stNode][i].next] = edge[stNode][i].len;
			//cout << dst[2] << endl;
			spend[edge[stNode][i].next] = edge[stNode][i].cost;
		}
		memset(book, 0, sizeof(book));
		book[stNode] = 1;
		//开始迪杰斯特拉算法，进行剩余n-1次松弛
		int k;
		for(k = 1; k <= n-1; k++){
			//找离源点最近的顶点u
			int minnode, min = inf;
			for(i = 1; i <= n; i++){
				if(book[i] == 0 && min > dst[i] /* || min == dst[i]&& edge[stnode][min].cost > edge[stnode][i].cost*/){
					min = dst[i];
					minnode = i;
				}
			}
			//cout << setw(2) << minnode;
			book[minnode] = 1;//易错点1，错写成book[i]=1
			//以中心点u为转折点来更新路径数组和花费数组
			for(i = 0; i < edge[minnode].size(); i++){
				int t = edge[minnode][i].next;//别忘了加此句，表示与结点minnode相邻的点
				if(book[t] == 0 && dst[t] > dst[minnode] + edge[minnode][i].len || dst[t] == dst[minnode] + edge[minnode][i].len && spend[t] > spend[minnode] + edge[minnode][i].cost){
					dst[t] = dst[minnode] + edge[minnode][i].len;
					spend[t] = spend[minnode] + edge[minnode][i].cost;
				}
			}
		}
		cout << dst[enNode] << setw(3) << spend[enNode] << endl;
	}
	return 0;
}
