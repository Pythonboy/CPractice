/*
有一个n*n的方格，从左上角走到右下角有多少种最短路径的走法？

若不加最短路径则n^(n-1)种走法。加上了最短路径就是说横向的距离为n-1，纵向的距离为n-1.总共的距离是2(n-1)步走到。
*/


int main()
{
    int n;
    while (cin >> n)
    {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 1));
        for (int i = 1; i <= n;i++)
        {
            for (int j = 1; j <= n;j++)
            {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        cout << dp[n][n] << endl;
    }
}
