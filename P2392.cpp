#include <bits/stdc++.h>
using namespace std;
int s[4];
int a[21];
int dp[1250];
int main()
{

    for (int i = 0; i < 4; i++)
    {
        cin >> s[i];
    }
    int sum_t = 0;
    for (int i = 0; i < 4; i++)
    {
        int sum = 0;
        memset(dp, 0, sizeof(dp));
        for (int j = 1; j <= s[i]; j++)
        {
            cin >> a[j];
            sum += a[j];
        }
        int t = sum / 2;
        for (int k = 1; k <= s[i]; k++)
        {
            for (int j = t; j >= a[k]; j--)

            {
                if (j >= a[k])
                {
                    dp[j] = max(dp[j], dp[j - a[k]] + a[k]);
                }
            }
        }
        sum_t += max(dp[t], sum - dp[t]);
    }
    cout << sum_t;
}