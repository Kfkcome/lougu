#include <bits/stdc++.h>
using namespace std;
int n, top;
long long a[100001];
long long q[100001];
int siz[100001];
map<long long, long long> mp;
int main()
{
    int pos;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    set<long long> se(a, a + n);
    if (se.size() != n)
    {
        for (int i = 0; i < n; i++)
        {
            int pos = lower_bound(q + 1, q + top + 1, a[i]) - q; // 查找当前成员应该放在那一组
            while (q[pos + 1] == a[i] && pos < top)
                pos++; // 一直找到相等的最后一个
            if (pos > top || q[pos] != a[i])
                siz[++top] = 1, q[top] = a[i] + 1; // 无法更新，重开一个组
            else
                siz[pos]++, q[pos]++; // 对当前组更新
        }
        int ans = -1;
        for (int i = 1; i < top; i++)
        {
            if (ans == -1 || siz[i] < ans)
            {
                ans = siz[i];
            }
        }
        cout << ans;
        return 0;
    }
    int mini_num = n;
    int long_temp = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] - a[i - 1] == 1)
        {
            long_temp++;
        }
        else
        {
            if (long_temp < mini_num)
            {
                mini_num = long_temp;
            }
            long_temp = 1;
        }
    }
    if (long_temp < mini_num)
    {
        mini_num = long_temp;
    }
    cout << mini_num;
    return 0;
}
