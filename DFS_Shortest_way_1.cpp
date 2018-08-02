//从起始结点开始访问所有的深度遍历路径或广度优先路径，则到达终点结点的路径有多条，取其中路径权值最短的一条则为最短路径
/***先输入n个结点，m条边，之后输入有向图的m条边，边的前两元素表示起始结点，第三个值表权值，输出1号城市到n号城市的最短距离***/  
/***算法的思路是访问所有的深度遍历路径，需要在深度遍历返回时将访问标志置0***/  
#include <iostream>  
#include <iomanip>  
#define nmax 110  
#define inf 999999999  
using namespace std;  
int n, m, minPath, edge[nmax][nmax], mark[nmax];//结点数，边数，最小路径，邻接矩阵，结点访问标记  
void dfs(int cur, int dst){  
    /***operation***/  
  
    /***operation***/  
    if(minPath < dst) return;//当前走过路径大于之前最短路径，没必要再走下去  
    if(cur == n){//临界条件  
        if(minPath > dst) minPath = dst;  
        return;  
    }  
    else{  
        int i;  
        for(i = 1; i <= n; i++){  
            if(edge[cur][i] != inf && edge[cur][i] != 0 && mark[i] == 0){  
                mark[i] = 1;  
                dfs(i, dst+edge[cur][i]);  
                mark[i] = 0;              
            }  
        }  
        return;  
    }  
}  
  
int main(){  
    while(cin >> n >> m && n != 0){  
        //初始化邻接矩阵  
        int i, j;  
        for(i = 1; i <= n; i++){  
            for(j = 1; j <= n; j++){  
                edge[i][j] = inf;  
            }  
            edge[i][i] = 0;  
        }  
        int a, b;  
        while(m--){  
            cin >> a >> b;  
            cin >> edge[a][b];  
        }  
        //以dnf(1)为起点开始递归遍历  
        memset(mark, 0, sizeof(mark));  
        minPath = inf;  
        mark[1] = 1;  
        dfs(1, 0);  
        cout << minPath << endl;  
    }  
    return 0;  
}  
