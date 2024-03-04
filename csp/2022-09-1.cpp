#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[21];
int c[21];
int b[21];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    c[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        c[i] = c[i - 1] * a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        b[i] = m % (c[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << (b[i] - b[i - 1]) / c[i - 1] << ' ';
    }
    return 0;
}