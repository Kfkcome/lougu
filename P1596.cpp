#include <bits/stdc++.h>
using namespace std;
int n, m;
char ground[101][101];
bool water[101][101];
int i_change[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int j_change[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int num;
bool check(int i, int j)
{
    for (int k = 0; k < 8; k++)
    {
        if (i + i_change[k] > 0 && i + i_change[k] <= n && j + j_change[k] > 0 && j + j_change[k] <= m && water[i + i_change[k]][j + j_change[k]])
        {
            return false;
        }
    }
    return true;
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
            if (ground[i][j] == 'W' && check(i, j))
            {
                num++;
            }
            if (ground[i][j] == 'W')
            {
                water[i][j] = true;
            }
        }
    }
    cout << num;
    return 0;
}