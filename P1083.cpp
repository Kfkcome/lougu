#include <bits/stdc++.h>
using namespace std;
int n, m;
long long r[1000001];
long long r1[1000001];
struct rent
{
    unsigned long long d, s, t;
};
struct rent l[1000001];
bool check(int x)
{
    long long r2[1000001];
    memset(r2, 0, sizeof(r2));
    for (int i = 1; i <= n; i++)
    {
        r2[i] = r[i] - r[i - 1];
    }
    for (int i = 1; i <= x; i++)
    {
        r2[l[i].s] -= l[i].d;
        r2[l[i].t + 1] += l[i].d;
    }
    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        r2[i] = r2[i] + r2[i - 1];
        if (r2[i] < 0)
        {
            flag = true;
            break;
        }
    }
    return flag;
}
int binSearch()
{
    int left = 1, right = m;
    while (left < right)
    {
        int mid = (left + right) / 2;

        if (check(mid))
        {
            right = mid;
        }
        else
            left = mid + 1;
    }
    return left;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> r[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> l[i].d >> l[i].s >> l[i].t;
    }
    for (int i = 1; i <= n; i++)
    {
        r1[i] = r[i] - r[i - 1];
    }
    for (int i = 1; i <= m; i++)
    {
        r1[l[i].s] -= l[i].d;
        r1[l[i].t + 1] += l[i].d;
    }
    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        r1[i] = r1[i] + r1[i - 1];
        if (r1[i] < 0)
        {
            cout << -1 << endl;
            flag = true;
            break;
        }
    }
    if (flag)
    {
        cout << binSearch();
    }
    else
        cout << 0;
    return 0;
}