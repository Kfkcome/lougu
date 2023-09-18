#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
struct point
{
    int i, j, s;
};
int t_map[402][402];
int x_change[] = {1, 2, -1, -2, 1, 2, -1, -2};
int y_change[] = {2, 1, 2, 1, -2, -1, -2, -1};
queue<point> q;
int main()
{
    struct point temp;
    cin >> n >> m >> x >> y;
    q.push((point){x, y, 0});
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int t_x = temp.i + x_change[i], t_y = temp.j + y_change[i];
            if (t_x > n || t_x <= 0 || t_y > m || t_y <= 0)
            {
                continue;
            }
            if (t_map[t_x][t_y] == 0)
            {
                t_map[t_x][t_y] = temp.s + 1;
                q.push((point){t_x, t_y, temp.s + 1});
            }
        }
    }
    t_map[x][y] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (t_map[i][j] == 0 && (i != x || j != y))
            {
                t_map[i][j] = -1;
            }
            cout << t_map[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}