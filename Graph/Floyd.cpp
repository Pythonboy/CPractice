/*
弗洛伊德算法（解决多源最短路径）：时间复杂度O(n^3),空间复杂度O(n^2)

基本思想：最开始只允许经过1号顶点进行中转，接下来只允许经过1号和2号顶点进行中转......允许经过1~n号所有顶点进行中转，来不断动态更新任意两点之间
的最短路程。即求从i号顶点到j号顶点只经过前k号点的最短路程。

分析如下：1，首先构建邻接矩阵Floyd[n+1][n+1]，假如现在只允许经过1号结点，求任意两点间的最短路程，很显然Floyd[i][j] = min{Floyd[i][j],
Floyd[i][1]+Floyd[1][j]}，代码如下：

for(i = 1; i <= n; i++){
	for(j = 1; j <= n; j++){
		if(Floyd[i][j] > Floyd[i][1] + Floyd[1][j])
			Floyd[i][j] = Floyd[i][1] + Floyd[1][j];
	}
}

2，接下来继续求在只允许经过1和2号两个顶点的情况下任意两点之间的最短距离，在已经实现了从i号顶点到j号顶点只经过前1号点的最短路程的前提下，现在
再插入第2号结点，来看看能不能更新更短路径，故只需在步骤1求得的Floyd[n+1][n+1]基础上，进行Floyd[i][j] = min{Floyd[i][j], 
Floyd[i][2]+Floyd[2][j]}；......
3，很显然，需要n次这样的更新，表示依次插入了1号，2号......n号结点，最后求得的Floyd[n+1][n+1]是从i号顶点到j号顶点只经过前n号点的最短路程。
故核心代码如下：

#define inf 99999999
for(k = 1; k <= n; k++){
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			if(Floyd[i][k] < inf && Floyd[k][j] < inf && Floyd[i][j] > Floyd[i][k] + Floyd[k][j])
				Floyd[i][j] = Floyd[i][k] + Floyd[k][j];
		}
	}
}

*/


/***先输入n，m，再输入m个三元组，n为路口数，m表示有几条路其中1为商店，n为赛场，三元组分别表起点，终点，该路径长，输出1到n的最短路径***/
#include <iostream>
using namespace std;
#define inf 99999999
#define nmax 110
int edge[nmax][nmax], n, m;
int main(){
	while(cin >> n >> m && n!= 0){
		//构建邻接矩阵
		int i, j;
		for(i = 1; i <= n; i++){
			for(j = 1; j <= n; j++){
				edge[i][j] = inf;
			}
			edge[i][i] = 0;
		}
		while(m--){
			cin >> i >> j;
			cin >> edge[i][j];
			edge[j][i] = edge[i][j];
		}
		//使用弗洛伊德算法
		int k;
		for(k = 1; k <= n; k++){
			for(i = 1; i <= n; i++){
				for(j = 1; j <= n; j++){
					if(edge[i][k] < inf && edge[k][j] < inf && edge[i][j] > edge[i][k] + edge[k][j])
						edge[i][j] = edge[i][k] + edge[k][j];
				}
			}
		}
		cout << edge[1][n] << endl;   //这里可以求出任意两点之间的最短距离
	}
	return 0;
}
