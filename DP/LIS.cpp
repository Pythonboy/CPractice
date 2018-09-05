/*
最长递增子序列的定义和最长公共子序列的定义差不多，只不过最长递增子序列是针对单个数组的。

举个例子，给出一序列，求出该序列的最长上升子序列的最大长度。

我们可以这么考虑，用数组a[]存储序列，b[i]表示以a[i]为结尾的序列的最大长度。

因此要求出b[i]的最大值，即求出max{b[0],b[1]....b[i-1]}的最大值，那么b[i]的最大值为max{b[0],b[1]....b[i-1]}+1;
即可写出状态方程：b[i]=max{b[0],b[1].....b[j]}+1;(0<=j<i&&a[j]<a[i]),然后求出数组b[]中的最大值即为所求
*/


int main(void)
{
    int i,j,n;
    int a[1001];
    int b[1001];
    int max;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=1;
    }
    for(i=0;i<n;i++)
    {
        max=0;
        for(j=0;j<i;j++)
        {
            if(a[i]>a[j]&&b[j]>max)
            {
                max=b[j];
            }
        }
        b[i]=max+1;
    }
    max=0;
    for(i=0;i<n;i++)
    {
        if(max<b[i])
            max=b[i];
    }
    printf("%d\n",max);
    return 0;
}



#define MAX_N 1010
#define INF 10010
int main()
{
    int i;
    int n;
    cin>>n;
    int a[1010];
    
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int dp[MAX_N];
    fill(dp,dp+n,INF);
    for(i=0;i<n;i++)
    {
        *lower_bound(dp,dp+n,a[i])=a[i];
    }
    cout<<lower_bound(dp,dp+n,INF)-dp<<endl;
}
