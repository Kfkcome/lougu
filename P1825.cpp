#include <bits/stdc++.h>
using namespace std;
int N, M;
struct point
{
    int i, j, c;
};
char place[301][301];
map<char, list<struct point> > transit;
bool path[301][301];
int min_time = 1 << 20;
int temp[4] = {1, 0, -1, 0};
int temp2[4] = {0, 1, 0, -1};
int start_i, start_j;
queue<point> q;

int bfs()
{
    q.push((struct point){start_i, start_j});
    struct point p;
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        if (place[p.i][p.j] == '=')
        {
            return p.c;
        }
        if (place[p.i][p.j] >= 'A' && place[p.i][p.j] <= 'Z')
        {
            list<struct point>::iterator it1 = transit[place[p.i][p.j]].begin();
            for (; it1 != transit[place[p.i][p.j]].end(); it1++)
            {
                if ((*it1).i != p.i || (*it1).j != p.j)
                {
                    p.i = (*it1).i;
                    p.j = (*it1).j;
                    break;
                }
            }
        }
        for (int i = 0; i < 4; i++)
        {
            int x = p.i + temp[i], y = p.j + temp2[i];
            if (place[x][y] != '#' && !path[x][y] && x >= 1 && x <= N && y >= 1 && y <= M)
            {
                path[x][y] = true;
                q.push((point){x, y, p.c + 1});
            }
        }
    }
    return -1;
}
int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> place[i][j];
            if (place[i][j] == '@')
            {
                start_i = i;
                start_j = j;
            }
            else if (place[i][j] >= 'A' && place[i][j] <= 'Z')
            {
                struct point p = {i, j, 0};
                transit[place[i][j]].push_back(p);
            }
        }
    }
    cout << bfs();
    return 0;
}
