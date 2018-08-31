/*
给定无向图G=(V, E)，U是V的子集。如果对任意u,v属于U有(u,v)属于E，则称U是G的完全子图。G的完全子图U是G的团当且仅当U不包含在G的更大的完全
子图中。G的最大团是指G中所含顶点数最多的团。如果对任意u,v属于U有(u, v)不属于E，则称U是G的空子图。G的空子图U是G的独立集当且仅当U不包含
在G的更大的空子图中。G的最大独立集是G中所含顶点数最多的独立集。G的补图G'=(V', E')定义为V'=V且(u, v)属于E'当且仅当(u, v)不属于E。
如图所示，给定无向图G={V, E}，其中V={1,2,3,4,5}，E={(1,2),(1,4),(1,5),(2,3),(2,5),(3,5),(4,5)}。根据最大团定义，子集{1,2}是图G的一
个大小为2的完全子图，但不是一个团，因为它包含于G的更大的完全子图{1,2,5}之中。{1,2,5}是G的一个最大团。{1,4,5}和{2,3,5}也是G的最大团。
右侧图是无向图G的补图G'。根据最大独立集定义，{2,4}是G的一个空子图，同时也是G的一个最大独立集。虽然{1,2}也是G'的空子图，但它不是G'的独
立集，因为它包含在G'的空子图{1,2,5}中。{1,2,5}是G'的最大独立集。{1,4,5}和{2,3,5}也是G'的最大独立集。
最大团问题可以用回溯法在O(n2^n)的时间内解决。首先设最大团为一个空团，往其中加入一个顶点，然后依次考虑每个顶点，查看该顶点加入团之后仍然
构成一个团。程序中采用了一个比较简单的剪枝策略，即如果剩余未考虑的顶点数加上团中顶点数不大于当前解的顶点数，可停止回溯。用邻接矩阵表示
图G，n为G的顶点数，cn存储当前团的顶点数，bestn存储最大团的顶点数。当cn+n-i<bestn时，不能找到更大的团，利用剪枝函数剪去
*/

void backtrack(int i)
{
    if(i>v)
    {
        if(cn>bestn)
        {
            bestn=cn;
            for(int j=1;j<=v;j++) bestuse[j]=use[j];
            return;
        }
    }
    bool flag=true;
    for(int j=1;j<i;j++)
    {
        if(use[j]&&!graph[j][i])
        {
            flag=false;
            break;
        }
    }
    if(flag)
    {
        cn++;
        use[i]=true;
        backtrack(i+1);
        use[i]=false;
        cn--;
    }
    if(cn+v-i>bestn)  
    {
        use[i]=false;
        backtrack(i+1);
    }
}

const int maxnum=101;
bool graph[maxnum][maxnum];
bool use[maxnum],bestuse[maxnum]; 
int cn,bestn,v,e;
int main()
{
    cin>>v>>e;
    for(int i=1;i<=e;i++)
    {
        int p1,p2;
        cin>>p1>>p2;
          graph[p1][p2]=true;
          graph[p2][p1]=true;
    }
    backtrack(1);
    cout<<bestn<<endl;
    for(int i=1;i<=v;i++) 
    {
        if(bestuse[i]) cout<<i<<" ";
    }
    cout<<endl;  
}
