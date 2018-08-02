/*
Bellman-Ford算法(解决负权边，解决单源最短路径，前几种方法不能求含负权边的图)：：时间复杂度O(nm),空间复杂度O(m)
主要思想：对所有的边进行n-1轮松弛操作，因为在一个含有n个顶点的图中，任意两点之间的最短路径最多包含n-1边。换句话说，第1轮在对所有的边进行松弛后，得到
的是从1号顶点只能经过一条边到达其余各定点的最短路径长度。第2轮在对所有的边进行松弛后，得到的是从1号顶点只能经过两条边到达其余各定点的最短路径长
度，......

此外，Bellman_Ford还可以检测一个图是否含有负权回路：如果在进行n-1轮松弛后仍然存在dst[e[i]] > dst[s[i]]+w[i]。算法核心代码如下：

#define inf 999999999
for(i = 1; i <= n; i++) dst[i] = inf;
dst[1] = 0;
for(k = 1; k <= n-1; k++){
	for(i = 1; i <= m; i++){
		if(dst[e[i]] > dst[s[i]] + w[i])
			dst[e[i]] = dst[s[i]] + w[i];
	}
}
//检测负权回路
flag = 0;
for(i = 1; i <= m; i++){
	if(dst[e[i]] > dst[s[i]] + w[i])
		flag = 1;
}
if(flag) cout << "此图含有负权回路";

*/

//对图示中含负权的有向图，输出从结点1到各结点的最短路径，并判断有无负权回路。
/***先输入n，m，分别表结点数和边数，之后输入m个三元组，各表起点，终点，边权，输出1号结点到各结点的最短路径****/
#include <iostream>
#include <iomanip>
using namespace std;
#define nmax 1001
#define inf 99999999
int n, m, s[nmax], e[nmax], w[nmax], dst[nmax];
int main(){
	while(cin >> n >> m && n != 0 && m != 0){
		int i, j;
		//初始化三个数组：起点数组s[],终点数组e[],权值数组w[],最短路径数组dst[]
		for(i = 1; i <= m; i++)
			cin >> s[i] >> e[i] >> w[i];
		for(i = 1; i <= n; i++)
			dst[i] = inf;
		dst[1] = 0;
		//使用Bellman_Ford算法
		for(j = 1; j <= n-1; j++){
			for(i = 1; i <= m; i++){
				if(dst[e[i]] > dst[s[i]] + w[i])
					dst[e[i]] = dst[s[i]] + w[i];
			}
		}
		//测试是否有负权回路并输出
		int flag = 0;
		for(i = 1; i <= m; i++)
			if(dst[e[i]] > dst[s[i]] + w[i])
				flag = 1;
		if(flag) cout << "此图含有负权回路\n";
		else{
			for(i = 1; i <= n; i++){
				if(i == 1)
					cout << dst[i];
				else 
					cout << setw(3) << dst[i];
			}
			cout << endl;
		}
	}
	return 0;
}
