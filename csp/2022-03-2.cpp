#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int q[400001]; // 用差分进行区间操作
struct trip_plan
{
    int t, c;
} t[100001];
int main()
{
    cin >> n >> m >> k;
    int maxq = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> t[i].t >> t[i].c;
        maxq = max(maxq, t[i].t);
    }
    // 计算差分
    for (int i = 0; i < n; i++)
    {
        q[t[i].t + 1] -= 1;
        q[max(0, t[i].t - t[i].c + 1)] += 1;
    }
    // 计算前缀和 恢复数组的原本意义
    for (int i = 1; i <= maxq + 1; i++)
    {
        q[i] += q[i - 1];
    }
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        cout << q[temp + k] << endl;
    }
    return 0;
}