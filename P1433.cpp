#include <bits/stdc++.h>
using namespace std;
int n;
struct cheese
{
    int x, y;
};
struct cheese c[16];
bool way[16];
double path[16][16];
double length_mini = 1 << 29;
void dfs(int last_point, int i, double path_sum)
{
    if (path_sum > length_mini)
    {
        return;
    }
    if (i == n)
    {
        length_mini = min(length_mini, path_sum);
        return;
    }
    for (int k = 1; k <= n; k++)
    {
        if (!way[k])
        {
            way[k] = true;
            dfs(k, i + 1, path_sum + path[last_point][k]);
            way[k] = false;
        }
    }
}
int main()
{
    cin >> n;
    c[0].x = 0, c[0].y = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i].x >> c[i].y;
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            int x1 = c[i].x, y1 = c[i].y;
            int x2 = c[j].x, y2 = c[j].y;
            path[i][j] = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
            path[j][i] = path[i][j];
        }
    }
    dfs(0, 0, 0);
    cout << fixed << setprecision(2) << length_mini;
    return 0;              
}