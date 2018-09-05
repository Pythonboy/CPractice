/*
给定一个由n行数字组成的数字三角型，如图所示。设计一个算法，计算从三角形的顶至底的一条路径，使该路径经过的数字总和最大。路径上的每一步都只
能往左下或右下走，给出这个最大和。
        7 
      3  8 
    8  1  0 
  2  7  4  4 
4  5  2  6  5

对于这种问题，我们可以有正向和反向两种思考方式。正向思考这个问题，dp[i][j]表示从第一行第一列到第i行第j列最大的数字总和；反向思考这个问题
，dp[i][j]表示从第i行第j列到最后一行最大的数字总和。反向思考的代码要简洁一些
*/

int triangle[110][110],dp[110][110];
int main()
{
    int N;
    cin>>N;
    memset(dp,0,sizeof(dp));
    memset(triangle,0,sizeof(triangle));
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cin>>triangle[i][j];
        }
    }
    dp[1][1]=triangle[1][1];
    for(int i=2;i<=N;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(j!=1) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+triangle[i][j]);
            if(j!=i) dp[i][j]=max(dp[i][j],dp[i-1][j]+triangle[i][j]);
        }
    }
    int max=-1;
    for(int i=1;i<=N;i++)
    {
        if(dp[N][i]>max) max=dp[N][i];
    }
    cout<<max<<endl;
        return 0;
}


int triangle[110][110],dp[110][110];
int main()
{
    int N;
    cin>>N;
    memset(dp,0,sizeof(dp));
    memset(triangle,0,sizeof(triangle));
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cin>>triangle[i][j];
        }
    }
    for(int i=1;i<=N;i++)
    {
        dp[N][i]=triangle[N][i];
    }
    for(int i=N-1;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
            dp[i][j]=max(dp[i+1][j]+triangle[i][j],dp[i+1][j+1]+triangle[i][j]);
        }
    }
    cout<<dp[1][1]<<endl;
        return 0;
}
