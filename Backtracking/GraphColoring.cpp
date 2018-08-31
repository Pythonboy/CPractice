/*
给定无向连通图G=(V,E)和m种不同的颜色，用这些颜色为图G的各顶点着色，每个顶点着一种颜色。如果一个图最少需要m种颜色才能使图中每条边连接的
2个顶点着不同颜色，则称m为该图的色数。地图着色问题可转换为图的着色问题：以地图中的区域作为图中顶点，2个区域如果邻接，则这2个区域对应的
顶点间有一条边，即边表示了区域间的邻接关系。著名的四色定理就是指每个平面地图都可以只用四种颜色来染色，而且没有两个邻接的区域颜色相同。
*/

bool ok(int k)
{
    for(int j=1;j<=v;j++)
    {
        if(graph[k][j]&&(color[j]==color[k])) return false;
    }
    return true;
}

void backtrack(int t)
{
    if(t>v) sum++;
     else
     {
        for(int i=1;i<=c;i++)
        {
            color[t]=i;
               if(ok(t)) backtrack(t+1);
               //改回辅助的全局变量 
               color[t]=0;
        }
     }
}

#define N 100
int v,e,c,graph[N][N],color[N];
//顶点数,边数,颜色数 
int sum;
int main()
{
    int i,j;
    cin>>v>>e>>c;                
    for(i=1;i<=v;i++)
    {
        for(j=1;j<=v;j++)
        {
            graph[i][j]=0; 
        }
    }           
    for(int k=1;k<=e;k++)      
    {
        cin>>i>>j;
        graph[i][j]=1;
        graph[j][i]=1;
    }
    for(i=0;i<=v;i++) color[i]=0;
     backtrack(1);
      cout<<sum<<endl;
}
