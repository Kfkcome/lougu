#include <bits/stdc++.h>
using namespace std;
int n, m;
struct point
{
    int x, y;
};
struct point horse;
long dp[22][22];
bool check(int i, int j)
{
    if (i == horse.x && j == horse.y)
    {
        return true;
    }
    else if (i == horse.x - 2 && j == horse.y - 1)
    {
        return true;
    }
    else if (i == horse.x - 1 && j == horse.y - 2)
    {
        return true;
    }
    else if (i == horse.x + 1 && j == horse.y - 2)
    {
        return true;
    }
    else if (i == horse.x + 2 && j == horse.y - 1)
    {
        return true;
    }
    else if (i == horse.x + 2 && j == horse.y + 1)
    {
        return true;
    }
    else if (i == horse.x + 1 && j == horse.y + 2)
    {
        return true;
    }
    else if (i == horse.x - 1 && j == horse.y + 2)
    {
        return true;
    }
    else if (i == horse.x - 2 && j == horse.y + 1)
    {
        return true;
    }
    return false;
}
int main()
{
    cin >> n >> m;
    cin >> horse.x >> horse.y;
    dp[0][1] = 1;
    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = 1; j <= m + 1; j++)
        {
            if (!check(i - 1, j - 1))
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    cout << dp[n + 1][m + 1];
    return 0;
}