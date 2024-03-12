#include <bits/stdc++.h>
using namespace std;
int n, x;
int a[201];
int main()
{
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > x)
        {
            sum += (i - 1) * (x - a[i - 1]);
            break;
        }
        else
        {
            sum += (i - 1) * (a[i] - a[i - 1]);
        }
        if (i == n)
        {
            sum += i * (x - a[i]);
        }
    }
    cout << sum;
    return 0;
}