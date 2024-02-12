#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, sum_x = 0, sum_y = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        sum_x += a;
        sum_y += b;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << sum_x + a << " " << sum_y + b << endl;
    }
    return 0;
}
