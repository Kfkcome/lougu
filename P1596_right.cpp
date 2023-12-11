#include <bits/stdc++.h>
using namespace std;
int n, m, num;
char ground[101][101];
int i_change[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int j_change[] = {-1, 0, 1, -1, 1, -1, 0, 1};
void dfs(int i, int j)
{
    ground[i][j] = '.';
    for (int k = 0; k < 8; k++)
    {
        if (ground[i + i_change[k]][j + j_change[k]] == 'W')
            dfs(i + i_change[k], j + j_change[k]);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> ground[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (ground[i][j] == 'W')
            {
                num++;
                dfs(i, j);
            }
        }
    }
    cout << num;
    return 0;
}