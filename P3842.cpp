#include <bits/stdc++.h>
using namespace std;
int n;
struct line
{
    int l;
    int r;
};
long dp[2][20001];
struct line lines[20001];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> lines[i].l >> lines[i].r;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int maxi;
            if (j <= lines[i].l)
            {
                dp[i % 2][j] = dp[(i - 1) % 2][lines[i].r] + lines[i].r - j;
            }
            else if (j >= lines[i].r)
            {
                dp[i % 2][j] = dp[(i - 1) % 2][lines[i].l] + j - lines[i].r;
            }
            else if (j > lines[i].l && j < lines[i].r)
            {
                if (j - lines[i].l < lines[i].r - j)
                {
                    dp[i % 2][j] = dp[(i - 1) % 2][lines[i].r] + j - lines[i].l + lines[i].r - lines[i].l;
                }
                else
                {
                    dp[i % 2][j] = dp[(i - 1) % 2][lines[i].l] + lines[i].r - j + lines[i].r - lines[i].l;
                }
            }
            dp[i % 2][j]++;
        }
    }
    cout << dp[n % 2][n];
    return 0;
}