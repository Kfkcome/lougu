#include <bits/stdc++.h>
using namespace std;
int n, L, S;
struct point
{
    int x, y;
} p[1001];
map<int, map<int, int>> bigp;
int smap[52][52];
bool check(int x, int y)
{
    if (x + S > L || y + S > L) // 如果超出了界限
    {
        return false;
    }
    for (int i = 0; i <= S; i++)
    {
        for (int j = 0; j <= S; j++)
        {
            if ((smap[i][j] == 1 && bigp[x + i][y + j] != 1) || (smap[i][j] == 0 && bigp[x + i][y + j] == 1)) // 如果这个地方有树
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    // freopen("1.txt", "r", stdin);
    cin >> n >> L >> S;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].x >> p[i].y;
        bigp[p[i].x][p[i].y] = 1;
    }
    for (int i = S; i >= 0; i--)
    {
        for (int j = 0; j <= S; j++)
        {
            cin >> smap[i][j];
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (check(p[i].x, p[i].y))
        {
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}