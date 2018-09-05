/*
求一个最大为100*100矩阵中的子矩阵中元素之和的最大值

主要思想为将其转化为一维数组求最大子段和，如果最优解左起第i列，右止于第j列，那么我们相当于把这些列的对应位加和，成为一列，并对改列求
最大子段和即可（降维思想）。
*/
#define maxn 105
#define inf 0x3f3f3f3f

int array[maxn][maxn];
int f[maxn][maxn][maxn];

int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++){scanf("%d", &array[i][j]);}
    }
    memset(f, 0, sizeof(f));
    int ans=-inf;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int sum=0;
            for(int k=j;k<=n;k++)
            {
                sum+=array[i][k];
                f[i][j][k]=max(f[i-1][j][k]+sum,sum);//i是指行，j是起始列，k是终结列，f存的值为在ijk范围内的元素和最大值
                ans=max(ans,f[i][j][k]);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
