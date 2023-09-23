#include <bits/stdc++.h>
using namespace std;
int n;
double dp[18][34000];
double length[20][20];
struct point
{
    double x, y;
};
struct point p[20];
int main()
{

    cin >> n;
    memset(dp, 127, sizeof(dp));
    p[0].x = 0, p[0].y = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i].x >> p[i].y;
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            double x1 = p[i].x, y1 = p[i].y;
            double x2 = p[j].x, y2 = p[j].y;
            length[i][j] = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
            length[j][i] = length[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][1 << (i - 1)] = length[0][i];
    }
    for (int k = 1; k < (1 << n); k++)
    {
        for (int i = 1; i <= n; i++)
        {
            if ((k & (1 << (i - 1))) == 0)
            {
                continue;
            }
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                {
                    continue;
                }
                if ((k & (1 << (j - 1))) == 0)
                {
                    continue;
                }
                dp[i][k] = min(dp[i][k], dp[j][k - (1 << (i - 1))] + length[i][j]);
            }
        }
    }
    double ans = dp[0][0];
    for (int i = 1; i <= n; i++)
    {
        ans = min(dp[i][(1 << n) - 1], ans);
    }
    printf("%.2f\n", ans);
    return 0;
}