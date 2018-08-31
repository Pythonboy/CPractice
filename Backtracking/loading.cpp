/*
有一批共n个集装箱要装上2艘载重量分别为c1和c2的船，其中集装箱i的重量为wi，且。装载问题要求确定是否有一个合理的装载方案可将这些集装箱装上
这2艘船。如果有，找出一种装载方案。例如当n=3，c1=c2=50且w=[10,40,40]时，则可以将集装箱1和2装到第一艘轮船上，而将集装箱3装到第二艘轮船
上；如果w=[20,40,40]，则无法将这3个集装箱都装上轮船。容易证明，如果一个给定装载问题有解，则首先将第一艘船尽可能装满再将剩余的集装箱装上
第二艘船可得到最优装载方案。将第一艘船尽可能装满等价于选取全体集装箱的一个子集，使该子集中集装箱重量之和最接近c1。用回溯法解装载问题, 
时间复杂度O(2^n)，在某些情况下优于动态规划算法。剪枝方案是如果当前已经选择的全部物品载重量cw+剩余集装箱的重量r<=当前已知的最优载重量
bestw，则删去该分支。
*/


void backtrack(int i)  
{        
    if(i>n)    
    {  
        if(ans>bestans) bestans=ans;  
        return;  
    }  
    r-=w[i];  
    if(ans+w[i]<=c1)  
    {   
      ans+=w[i];  
      backtrack(i+1);  
      //改回辅助的全局变量 
      ans-=w[i];  
    }  
    if(ans+r>bestans) backtrack(i+1);    
    //改回辅助的全局变量 
    r+=w[i];  
}

int maxloading()  
{  
    ans=0;  
    bestans=0;  
    backtrack(1);   
    return bestans;  
}

int n;//集装箱数  
int w[40];//集装箱重量
int c1,c2;//两艘船的载重量  
int ans;//当前载重量  
int bestans;//当前最优载重量  
int r;//剩余集装箱重量 
int main()  
{    
    cin>>n>>c1>>c2;  
     int i=1;  
     int sum=0;  
     //集装箱总重量 
     while(i<=n)  
    {  
        cin>>w[i];  
        r+=w[i];  
        sum+=w[i];  
         i++;  
     }    
    maxloading();  
    if(bestans>0&&((sum-bestans)<=c2)) cout<<bestans<<endl;  
     else if(sum<=c2) cout<<bestans<<endl;  
      else cout<<"No"<<endl;  
}
