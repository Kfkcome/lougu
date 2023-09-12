#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[101];
int dp[101][101];
int main()
{
    cin >> n >> m;
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (int i = 1; i <= n; i++)
    {

        for (int j = 0; j <= m; j++)
        {
            
            for (int k = 0; k <= min(j,a[i]); k++)
            {
                dp[i][j] =(dp[i][j]+dp[i - 1][j - k])%1000007;
            }
        }
    }
    cout<<dp[n][m];
    return 0;
}