/*
有N件物品和一个容量为V的背包。第i件物品的费用是c[i]，价值是w[i]。求解将哪些物品装入背包可使这些物品的费用总和不超过背包容量，
且价值总和最大。 

f[i][v]表示前i件物品恰放入一个容量为v的背包可以获得的最大价值。则其状态转移方程便是：f[i][v]=max{f[i-1][v],f[i-1][v-c[i]]+w[i]}。

将前i件物品放入容量为v的背包中”这个子问题，若只考虑第i件物品的策略（放或不放），那么就可以转化为一个只牵扯前i-1件物品的问题。如果不放
第i件物品，那么问题就转化为“前i-1件物品放入容量为v的背包中”；如果放第i件物品，那么问题就转化为“前i-1件物品放入剩下的容量为v-c[i]的背
包中”，此时能获得的最大价值就是f [i-1][v-c[i]]再加上通过放入第i件物品获得的价值w[i]。
*/
//DP + 回溯
void backtrack(int i,int cp,int cw)
{
    if(i>n) //结束条件
    {
        if(cp>bestp)
        {
            bestp=cp;
            for(i=1;i<=n;i++) bestx[i]=x[i];
        }
    }
    else
    {
        for(int j=0;j<=1;j++)  
        {
            x[i]=j;
            if(cw+x[i]*w[i]<=c)   //剪枝条件
            {
                cw+=w[i]*x[i];
                cp+=p[i]*x[i];
                backtrack(i+1,cp,cw);
                cw-=w[i]*x[i];
                cp-=p[i]*x[i];
            }
        }
    }
}

int n,c,bestp;//物品个数,背包容量,最大价值
int p[10000],w[10000],x[10000],bestx[10000];//物品的价值,物品的重量,物品的选中情况
int main()
{
    bestp=0; 
    cin>>c>>n;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<=n;i++) cin>>p[i];
    backtrack(1,0,0);
    cout<<bestp<<endl;
}
