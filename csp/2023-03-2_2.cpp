#include <bits/stdc++.h>
using namespace std;
int c[100001]; // 差分数组 i代表天数 c[i]真实的值代表减到i天需要的资源数
// 求出c后再转化为前缀和数组
int csum[100001];

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int maxt = 0;
    for (int i = 0; i < n; i++)
    {
        int t, c_temp;
        cin >> t >> c_temp;
        maxt = max(maxt, c_temp);
        // 让0-t的区间内增加c
        c[0] += c_temp;
        c[t + 1] -= c_temp;
    }
    for (int i = 1; i <= maxt + 1; i++)
    {
        c[i] += c[i - 1]; // 求前缀和
    }
    int minday=1e9;
    for (int i = maxt + 1; i >= 1; i++)
    {
        if (i <= k)
        {
            cout << k;
            return 0;
        }
        
    }
    return 0;
}