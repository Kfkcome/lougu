#include <bits/stdc++.h>
using namespace std;
int N, M;
struct point
{
    int i, j;
};
char place[301][301];
map<char, list<struct point> > transit;
bool path[301][301];
int min_time = 1 << 20;
int start_i, start_j;
bool dfs(int count, int i, int j)
{
    int init_i = i, init_j = j;
    if (place[i][j] == '=')
    {
        min_time = min(count, min_time);
        return true;
    }
    if (i > N || i < 1 || j > M || j < 1 || path[i][j] || place[i][j] == '#')
    {
        return false; // 不满足条件直接回溯
    }
    if (place[i][j] >= 'A' && place[i][j] <= 'Z')
    {
        list<struct point>::iterator it1 = transit[place[i][j]].begin();
        for (; it1 != transit[place[i][j]].end(); it1++)
        {
            if ((*it1).i != i || (*it1).j != j)
            {
                i = (*it1).i;
                j = (*it1).j;
                break;
            }
        }
    }
    path[init_i][init_j]=true;  
    if (i + 1 >= 1 && i + 1 <= N && j >= 1 && j <= M && !path[i + 1][j] && place[i + 1][j] != '#')
        dfs(count + 1, i + 1, j);
    if (i - 1 >= 1 && i - 1 <= N && j >= 1 && j <= M && !path[i - 1][j] && place[i - 1][j] != '#')
        dfs(count + 1, i - 1, j);
    if (i >= 1 && i <= N && j - 1 >= 1 && j - 1 <= M && !path[i][j - 1] && place[i][j - 1] != '#')
        dfs(count + 1, i, j - 1);
    if (i >= 1 && i <= N && j + 1 >= 1 && j + 1 <= M && !path[i][j + 1] && place[i][j + 1] != '#')
        dfs(count + 1, i, j + 1);
    path[init_i][init_j] = false; // 恢复状态
    return false;
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
                struct point p = {i, j};
                transit[place[i][j]].push_back(p);
            }
        }
    }
    dfs(0, start_i, start_j);
    cout << min_time;
    return 0;
}