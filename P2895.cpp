#include <bits/stdc++.h>
using namespace std;
int m;
struct point
{
    int x, y, t;
};
struct point star[50001];
int path[306][306];
bool available[306][306];
int x_change[] = {1, -1, 0, 0};
int y_change[] = {0, 0, 1, -1};
queue<point> q;
void crash(int i, int j)
{
    path[i][j] = -1;
    for (int k = 0; k < 4; k++)
    {
        if (i + x_change[k] >= 0 && i + x_change[k] <= 305 && j + y_change[k] >= 0 && j + y_change[k] <= 305)
            path[i + x_change[k]][j + y_change[k]] = -1;
    }
}
bool cmp(struct point a, struct point b)
{
    return a.t > b.t;
}
void update(int t)
{
    for (int i = 1; i <= m; i++)
    {
        if (star[i].t > t)
        {
            continue;
        }
        else
        {
            crash(star[i].x, star[i].y);
        }
    }
}
int main()
{
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> star[i].x >> star[i].y >> star[i].t;
        available[star[i].x][star[i].y] = 1;
        for (int k = 0; k < 4; k++)
        {
            if (star[i].x + x_change[k] >= 0 && star[i].x + x_change[k] <= 305 && star[i].y + y_change[k] >= 0 && star[i].y + y_change[k] <= 305)
                available[star[i].x + x_change[k]][star[i].y + y_change[k]] = 1;
        }
    }
    update(0);
    q.push((point){0, 0, 0});
    struct point temp;
    while (!q.empty())
    {
        temp = q.front();
        int t = temp.t + 1;
        update(t);
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x, y;
            x = temp.x + x_change[i];
            y = temp.y + y_change[i];
            if (path[x][y] == 0 && x >= 0 && x < 306 && y >= 0 && y < 306)
            {
                if (!available[x][y])
                {
                    cout << t;
                    return 0;
                }
                q.push((point){x, y, t});
                path[x][y] = t;
            }
        }
    }
    cout << -1;
    return 0;
}