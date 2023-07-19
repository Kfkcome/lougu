#include <bits/stdc++.h>
using namespace std;
char a[11][11];
char b[11][11];
int way[10];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> b[i][j];
        }
    } // 输入数据
    // 遍历搜索转换方法
    // 转90度

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (b[i][j] != a[n - 1 - j][i]) // 转90度就是列变成行，列=n-1-行
            {
                way[1] = 1; // 标记此方法不能用
            }
            if (b[i][j] != a[n - 1 - i][n-1-j])
            {
                way[2] = 1;
            }
            if (b[i][j] != a[j][n-1-i])
            {
                way[3] = 1;
            }
            if (b[i][j] != a[i][n - 1 - j])
            {
                way[4] = 1;
            }
            if (
                b[i][j] != a[j][i])
            {
                way[5] = 1;
            }
            if (b[i][j] != a[n - 1 - i][j])
            {
                way[6] = 1;
            }
            if (b[i][j] != a[n - 1 - j][n-1-i])
            {
                way[7] = 1;
            }
            if (b[i][j] != a[i][j])
            {
                way[8] = 1;
            }
        }
    }
    for (int i = 1; i <= 8; i++)
    {
        if (way[i] == 0)
        {
            if (i <= 4)
            {
                cout << i;
            }
            else if (i == 5 || i == 6 || i == 7)
            {
                cout << 5;
            }
            else if (i == 8)
            {
                cout << 6;
            }
            return 0;
        }
    }
    cout << 7;
    return 0;
}