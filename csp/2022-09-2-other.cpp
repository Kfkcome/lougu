#include <bits/stdc++.h>
using namespace std;
int n, x;
int a[31];
int sum;
int dp[1000000];
int main()
{
    // freopen("1.in", "r", stdin);
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[a[i]] = a[i];
        sum += a[i];
    }
    for (int i = 0; i <= sum; ++i)
    {
        dp[i] = sum;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= sum - a[i]; ++j)
        {
            dp[j] = min(dp[j], dp[j + a[i]] - a[i]);
        }
    }
    cout << dp[x];
    return 0;
}