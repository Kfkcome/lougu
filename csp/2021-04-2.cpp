#include <bits/stdc++.h>
using namespace std;
int n, L, r, t;
int a[601][601];
int sum[601][601]; // 二维前缀和数组
int main()
{
    cin >> n >> L >> r >> t;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + a[i][j];
        }
    }
    int num = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int iaddr = min(n, i + r), jaddr = min(n, j + r), isubr = max(0, i - r - 1), jsubr = max(0, j - r - 1);
            int matrix_sum = sum[iaddr][jaddr] - sum[isubr][jaddr] - sum[iaddr][jsubr] + sum[isubr][jsubr];
            int matrix_num = (iaddr - isubr ) * (jaddr - jsubr );
            if (matrix_sum / (double)matrix_num <= t)
                num++;
        }
    }
    cout << num;
    return 0;
}