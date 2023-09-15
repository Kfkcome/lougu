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
int min_time;
int start_i, start_j, end_i, end_j;
bool dfs(int count, int i, int j)
{
    path[i][j] = true;
    if (place[i][j] == '=')
    {
        min_time = min(count, min_time);
        return true;
    }
    if (place[i][j] >= 'A' && place[i][j] <= 'Z')
    {

        list<struct point>::iterator it1 = transit[place[i][j]].begin();
        for (; it1 != transit[place[i][j]].end(); it1++)
        {
            if ((*it1).i != i || (*it1).j != j)
                dfs(count + 1, (*it1).i, (*it1).j);
        }
        for()
    }
    if (!path[i - 1][j])
        dfs(count + 1, i - 1, j);
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
            if (place[i][j] == '=')
            {
                end_i = i;
                end_j = j;
            }
            if (place[i][j] >= 'A' && place[i][j] <= 'Z')
            {
                struct point p = {i, j};
                transit[place[i][j]].insert(transit[place[i][j]].end(), p);
            }
        }
    }
    // cout << dfs(0)

    return 0;
}