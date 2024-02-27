#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
struct solid
{
    int c, t;
};
struct solid s[100001];
bool cmp(struct solid s1, struct solid s2)
{
    return s1.t > s2.t;
}
bool check(int time)
{
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i].t > time)
            sum += (s[i].t - time) * (s[i].c);
    }
    if (sum <= m)
    {
        return true;
    }
    return false;
}
int main()
{
    cin >> n >> m >> k;
    int r = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i].t >> s[i].c;
        r = max(s[i].t, r);
    }
    int l = k;
    int res = 0;
    while (l <= r)
    {
        long long mid = (r + l) / 2;
        if (check(mid))
        {
            res = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << res;
    return 0;
}