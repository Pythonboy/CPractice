/*
时间：2018/8/1
作者：楼浩然
功能：检测图中是否存在环
*/
#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
#define MAXN 100
using namespace std;
int Graph[MAXN][MAXN];
vector<int>Book; //用于判断顶点是否已经遍历过

bool CycleDetect(int n,int st)
{
    queue<int>Res;
    int i,j;
    int father;
    Res.push(st);
    Book[st] = 1;
    while(!Res.empty())
    {
        father = Res.front();
        Res.pop();
        for(i=1 ; i<=n ; i++)
        {
            if(Graph[father][i]==1 && !Book[i])
            {
                Book[i] = 1;
                Res.push(i);
                for(j=1 ; j<=n ; j++)
                {
                    if(j!=father && Graph[i][j]==1 && Book[j])
                        return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    printf("请输入顶点数量和边数量:\n");
    int N,K,i,j,k;
    scanf("%d %d",&N,&K);
    Book.resize(N+1);
    for(i=0 ; i<=N ; i++)
        Book[i] = 0;
    memset(Graph,0,sizeof(Graph));
    printf("请输入各条边:\n");
    for(i=0 ; i<K ; i++)
    {
        cin>>j>>k;
        Graph[j][k] = Graph[k][j] = 1;
    }
    printf("请输入起点：\n");
    int st;
    cin>>st;
    if(CycleDetect(N,st))
        cout<<"图中有环";
    else
        cout<<"图中无环";
    return 0;

}





//他山之玉

//从某点出判断无向图是否有回路（图用邻接矩阵表示）。假如有N个点，需要调用N次该函数。因为考虑到孤立点的因素，需要从每个点都开始一次。
    bool isHuiLu(int begin, int temp[][MAXLEN])
    {
        bool flag[MAXLEN];
        int i, j;
        stack <int>stk;
        queue <int> vexQueue;
        for (i = 0; i<vexnum; i++)
            flag[i] = false;
        //从a或b点出发，广度遍历所有点
        //如果该点和之前已访问过的点（除了它父亲）有边，
        //说明有回路
        vexqueue.push(begin);
        flag[begin] = true;
        int father;
        while (vexqueue.empty() == false) {
            father = vexQueue.front();
            vexQueue.pop();
            for (int i = 0; i < vexnum; ++i) {
                if (temp[father][i] != MAX && flag[i] == false) {
                    vexQueue.push(i);
                    flag[i] = true;
                    //看看当前点和其他已访问点是否有边
                    for (int j = 0; j < vexnum; ++j) {
                        if (temp[i][j] != MAX && j != father && flag[j] == true) {
                            return true;//如果有边，说明有回路
                        }
                    }

                }

            }
        }
        return false;    
    }
