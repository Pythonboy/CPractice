/*
给定n个可连乘的矩阵{A1, A2, …,An}，根据矩阵乘法结合律，可有多种不同计算次序，每种次序有不同的计算代价，也就是数乘次数。例如给定2个矩
阵A[pi,pj]和B[pj,pk]，A×B为[pi,pk]矩阵，数乘次数为pi×pj×pk。将矩阵连乘积Ai…Aj简记为A[i:j] ，这里i≤j。考察计算A[i:j]的最优计算次序
，设这个计算次序在矩阵Ak和Ak+1之间将矩阵链断开，i≤k<j，则A[i:j]的计算量=A[i:k]的计算量+A[k+1:j]的计算量+A[i:k]和A[k+1:j]相乘的计算
量。计算A[i:j]的最优次序所包含的计算矩阵子链A[i:k]和A[k+1:j]的次序也是最优的。即矩阵连乘计算次序问题的最优解包含着其子问题的最优解，
这种性质称为最优子结构性质，问题具有最优子结构性质是该问题可用动态规划算法求解的显著特征。

举个例子：

给出N个数，每次从中抽出一个数(第一和最后一个不能抽)，该次的得分即为抽出的数与相邻两个数的乘积。一直这样将每次的得分累加直到只剩下首
尾两个数为止，问最小得分。
*/


#define maxn 105
int dp[maxn][maxn],a[maxn]; 
int main()
{
    int n;
    cin>>n;
    int i,j,k,len;
    memset(dp,0,sizeof(dp)); 
    //len是设置步长,也就是j减i的值 
    for(i=0;i<n;i++) cin>>a[i];
    for(i=0;i<n-2;i++) dp[i][i+2]=a[i]*a[i+1]*a[i+2];
    //如果只有三个数就直接乘起来 
    for(len=3;len<n;len++)
    {
        for(i=0;i+len<n;i++)
        {    
            j=i+len;
            for(k=i+1;k<j;k++)
            {
                if(dp[i][j]==0) dp[i][j]=dp[i][k]+dp[k][j]+a[i]*a[k]*a[j];
                 else dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+a[i]*a[k]*a[j]);
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
    return 0;
}
