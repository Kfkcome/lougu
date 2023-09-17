#include <bits/stdc++.h>
using namespace std;
int n, x;
int rem[31][300001];
int dp[31][300001];
int a[31];
bool goods[31];
int main()
{
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            if (j >= a[i] && dp[i - 1][j] < dp[i - 1][j - a[i]] + a[i])
            {
                rem[i][j] = j - a[i];
                dp[i][j] = dp[i - 1][j - a[i]] + a[i];
            }
            else
            {
                rem[i][j] = j;
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    int j = x;
    for (int i = n; i >= 1; i--)
    {
        if (rem[i][j] != j)
        {
            goods[i] = true;
        }
        j = rem[i][j];
    }
    int min_goods = 10001;
    for (int i = 1; i <= n; i++)
    {
        if (!goods[i])
        {
            min_goods = min(min_goods, a[i]);
        }
    }
    if (min_goods == 10001 || dp[n][x] == x)
    {
        min_goods = 0;
    }
    cout << dp[n][x] + min_goods;
    return 0;
}