#include <bits/stdc++.h>
using namespace std;
int n;
long a[100001];
long x, sum;
int main()
{
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] + a[i - 1] > x)
        {
            int s = a[i] + a[i - 1];
            sum += a[i] + a[i - 1] - x;
            if (a[i] < s - x)
            {
                a[i] = 0;
                a[i - 1] = a[i - 1] - (s - x - a[i]);
            }
            else
            {
                a[i] -= s - x;
            }
        }
    }
    cout << sum;
    return 0;
}