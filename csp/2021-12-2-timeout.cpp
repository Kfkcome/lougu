#include <bits/stdc++.h>
using namespace std;
int n, N;
int a[100001];
int f[100000001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> N;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int top = 1;
    int r = N / (n + 1);
    long long sum = 0;
    for (int i = 0; i < N; ++i)
    {
        if (i < a[top])
        {
            f[i] = top - 1;
        }
        else
        {
            f[i] = top;
            if (top < n)
                top++;
            else
            {
                sum += abs(i / r - top);
                continue;
            }
        }
        sum += abs(i / r - f[i]);
    }
    cout << sum;
    return 0;
}