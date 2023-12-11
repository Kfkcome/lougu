#include <bits/stdc++.h>
using namespace std;
int T, n, p;
string temp[101];
bool grid[100001];
int main()
{
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cin >> n >> p;
        memset(grid, 0, sizeof(grid));
        for (int j = n - 1; j >= 2; j -= 2)
        {
            grid[j] = 1;
            p--;
            if (p == 0)
            {
                break;
            }
        }
        if (p > 0)
        {
            temp[i].append("-1");
            continue;
        }
        for (int j = 2; j <= n; j++)
        {
            if (grid[j])
            {
                grid[j] = 0;
                grid[j - 1] = 1;
                grid[j + 1] = 1;
                j = j + 1;
            }
        }
        for (int j = 1; j <= n; j++)
        {
            temp[i].push_back('0' + grid[j]);
        }
    }
    for (int i = 1; i <= T; i++)
    {
        cout << temp[i] << endl;
    }
    return 0;
}