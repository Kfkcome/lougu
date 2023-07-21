#include <bits/stdc++.h>
using namespace std;
int a[121][121];
int main()
{
    int n;
    cin >> n;
    int maxn = -1 << 30;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + a[i][j];
        }
    }
    for (int x1 = 0; x1 <= n; x1++)
    {
        for (int y1 = 0;  y1 <= n;  y1++)
        {
            for(int x2=0;x2<x1;x2++)
            {
                for(int y2=0;y2<y1;y2++){
                    int sum=a[x1][y1]-a[x1][y2]-a[x2][y1]+a[x2][y2];
                    maxn=max(maxn,sum);
                }
            }
        }
    }
    cout << maxn;
}