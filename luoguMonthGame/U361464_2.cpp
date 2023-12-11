#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[501], num[501], r[501], l[501];
long b[501];
long long dp[501][501];
int main()
{
    memset(r, 501, sizeof(r));
    memset(l, 0, sizeof(l));
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        num[a[i]]++;
        r[a[i]] = min(r[a[i]], i);
        l[a[i]] = max(l[a[i]], i);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    
    for (int i = 1; i <= k; i++)
    {
        for(int j=i)
    }
    return 0;
}