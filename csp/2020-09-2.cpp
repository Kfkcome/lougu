#include <bits/stdc++.h>
using namespace std;
int n, k, t, xl, yd, xr, yu;
int stay, stayk;
int x[21][1001];
int y[21][1001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k >> t >> xl >> yd >> xr >> yu;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= t; j++)
        {
            int a, b;
            cin >> a >> b;
            x[i][j] = a;
            y[i][j] = b;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        bool times = 0;
        int long_times = 0;
        int max_long_times = -1;
        for (int j = 1; j <= t; j++)
        {
            if (x[i][j] >= xl && x[i][j] <= xr && y[i][j] >= yd && y[i][j] <= yu)
            {
                times = true;
                long_times++;
            }
            else
            {
                max_long_times = max(max_long_times, long_times);
                long_times = 0;
            }
        }
        max_long_times = max(max_long_times, long_times);
        if (times)
            stay++;
        if (max_long_times >= k)
            stayk++;
    }
    cout << stay << endl;
    cout << stayk << endl;
    return 0;
}