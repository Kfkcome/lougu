#include <bits/stdc++.h>
using namespace std;
int n, x;
int a[31];
int sum;
int dp[100000];
int main()
{
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = sum - x; j >= 1; j--)
        {
            if (j >= a[i])
                dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
        }
    }
    cout << sum - dp[sum - x];
    return 0;
}