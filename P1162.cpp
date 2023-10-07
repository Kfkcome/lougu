#include <bits/stdc++.h>
using namespace std;
int n;
struct point
{
    int x, y;
};
int i_change[] = {1, 0, -1, 0};
int j_change[] = {0, -1, 0, 1};

bool change[4];
queue<point> q;
char my[31][31];
bool possible[31][31];
void bfs()
{
    struct point temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (my[temp.x][temp.y] == '1')
        {
            return;
        }
        for (int i = 0; i < 4; i++)
        {

            if (!possible[temp.x + i_change[i]][temp.y + j_change[i]] && temp.x + i_change[i] > 0 && temp.x + i_change[i] <= n && temp.y + j_change[i] > 0 && temp.y + j_change[i] <= n && my[temp.x + i_change[i]][temp.y + j_change[i]] == '0')
            {
                q.push((point){temp.x + i_change[i], temp.y + j_change[i]});
                possible[temp.x + i_change[i]][temp.y + j_change[i]] = true;
            }
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> my[i][j];
        }
    }
    int loop[] = {1, n};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (!possible[loop[i]][j])
            {
                q.push((point){loop[i], j});
                bfs();
            }
            if (!possible[j][loop[i]])
            {
                q.push((point){j, loop[i]});
                bfs();
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (!possible[i][j] && my[i][j] != '1')
            {
                cout << 2 << ' ';
            }
            else
                cout << my[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}