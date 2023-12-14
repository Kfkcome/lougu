#include <bits/stdc++.h>
using namespace std;
int n;
struct game
{
    int a;
    int b;
    int l;
};
bool cmp2(struct game g1, struct game g2)
{
    return g1.b < g2.b;
}
struct game g[1000001];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> g[i].a >> g[i].b;
        g[i].l = g[i].b - g[i].a;
    }
    sort(g, g + n, cmp2);

    int last_end = 0; // 最开始结束的时间
    int last_start = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (g[i].a == last_start && last_end > g[i].b)
        {
            last_end = g[i].b;
            continue;
        }
        if (g[i].a >= last_end)
        {
            last_start = g[i].a;
            last_end = g[i].b;
            sum++;
        }
    }
    cout << sum;
    return 0;
}