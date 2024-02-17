#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, p, q;
ll x[100001], y[100001];
ll dis[100001];
ll getDistance(ll u, ll v, ll x1, ll y1)
{
    ll tempd = 0;
    if (x1 == u)
    {
        tempd = abs(y1 - v);
    }
    else if (y1 == v)
    {
        tempd = abs(x1 - u);
    }
    else if (abs(x1 - u) == abs(y1 - u))
    {
        tempd = abs(x1 - u);
    }
    return tempd;
}
void change(ll u, ll v, ll t, int i)
{
    ll x1 = x[i];
    ll y1 = y[i];
    if (x1 == u && y1 > v) // 正上方
    {
        x[i] -= y1 - v;
    }
    else if (x1 == u && y1 < v) // 正下方
    {
        x[i] += v - y1;
    }
    else if (y1 == v && x1 < u) // 左面
    {
        y[i] -= u - x1;
    }
    else if (y1 == v && x1 > u) // 右面
    {
        y[i] += x1 - u;
    }
    else if (x1 < u && y1 > v) // 左上角
    {
        y[i] = v;
    }
    else if (x1 < u && y1 < v) // 左下角
    {
        x[i] = u;
    }
    else if (x1 > u && y1 < v) // 右下角
    {
        y[i] = v;
    }
    else if (x1 > u && y1 > v) // 右上角
    {
        x[i] = u;
    }
}
int main()
{
    cin >> n >> m >> p >> q;
    for (int i = 1; i <= p; i++)
    {
        cin >> x[i] >> y[i];
    }
    ll u, v, t, toBoard, mind;
    for (int i = 1; i <= q; i++)
    {
        cin >> u >> v >> t;
        toBoard = min(min(u - 1, n - u), min(v - 1, m - v)); // 获取离边最近的距离
        mind = -1;
        for (int j = 1; j <= p; j++)
        {

            if (abs(x[j] - u) != abs(y[j] - u) && x[j] != u && y[j] != v)
            {
                continue;
            }
            if (x[j] == u && y[j] == v)
            {
                continue;
            }
            dis[j] = getDistance(u, v, x[j], y[j]);
            if (mind == -1 || mind > dis[j])
            {
                mind = dis[j];
            }
        }
        if (toBoard < mind)
        {
            continue;
        }
        for (int j = 1; j <= p; j++)
        {
            if (dis[j] == mind)
            {
                // 逆时针旋转t次
                for (int z = 0; z < t; z++)
                    change(u, v, t, j);
            }
        }
    }
    ll sum = 0;
    for (int i = 1; i <= p; i++)
    {
        // cout<<x[i]<<' '<<y[i]<<endl;
        sum = sum ^ (i * x[i] + y[i]);
    }
    cout << sum;
    return 0;
}
