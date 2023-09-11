#include <bits/stdc++.h>
using namespace std;
int t, m;
long dp[2][10000100];
struct medicine
{
    int t, v;
};
struct medicine g[10001];
int main()
{
    cin >> t >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> g[i].t >> g[i].v;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= t; j++)
        {
            if (j >= g[i].t)
                dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[i % 2][j - g[i].t] + g[i].v);
            else
                dp[i % 2][j] = dp[(i - 1) % 2][j];
        }
    }
    cout << max(dp[m % 2][t], dp[(m - 1) % 2][t]);
    return 0;
}