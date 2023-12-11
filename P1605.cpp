#include <bits/stdc++.h>
using namespace std;
int n, m, t, sx, sy, fx, fy, time_count;
int change_x[] = {-1, 1, 0, 0};
int change_y[] = {0, 0, -1, 1};
bool path[10][10];
void dfs(int x, int y)
{
    if (x == fx && y == fy)
    {
        time_count++;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int x1 = x + change_x[i], y1 = y + change_y[i];
        if (x1 > 0 && x1 <= n && y1 > 0 && y1 <= m && !path[x1][y1])
        {
            path[x1][y1] = true;
            dfs(x1, y1);
            path[x1][y1] = false;
        }
    }
}
int main()
{ 
    cin >> n >> m >> t >> sx >> sy >> fx >> fy;
    for (int i = 1; i <= t; i++)
    {
        int temp_x, temp_y;
        cin >> temp_x >> temp_y;
        path[temp_x][temp_y] = true;
    }
    path[sx][sy]=true;
    dfs(sx, sy);
    
    cout << time_count;
    return 0;
}