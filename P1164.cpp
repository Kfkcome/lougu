#include <bits/stdc++.h>
using namespace std;
int N, M;
int dp[10001][101];
int a[101];
int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
    }
    for (int j = 1; j <= M; j++)
    {
        for (int i = 1; i <= N; i++)
        {
            if (a[i]==j)
            {
                dp[j][i]=dp[j][i-1]+1;
            }
            else if (j > a[i])
                dp[j][i] = dp[j-a[i]][i - 1]+dp[j][i-1];
            else
                dp[j][i] = dp[j][i - 1]; 
        }
    }
    cout << dp[M][N];
}