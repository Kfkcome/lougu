#include <bits/stdc++.h>
using namespace std;
int rug[1002][1002]; // 地毯
int rug2[1002][1002];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        rug[x1][y1]++;
        rug[x2 + 1][y1]--;
        rug[x1][y2 + 1]--;
        rug[x2 + 1][y2 + 1]++;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            rug2[i][j] = rug2[i - 1][j] + rug2[i][j - 1] - rug2[i - 1][j - 1] + rug[i][j];
            cout << rug2[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}