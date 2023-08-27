#include <bits/stdc++.h>
using namespace std;
int n, m;
struct point
{
    int l, r, v;
};
struct point a[200001];
long b[200001];
int l;
int s[200001];
int get(int x)
{
    if (s[x] == x)
    {
        return x;
    }
    else
        return s[x] = get(s[x]);
}
void unit(int x, int y)
{
    if (get(x) != get(y))
        s[get(x)] = s[get(y)];
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].l >> a[i].r;
        a[i].l--;
        string temp;
        cin >> temp;
        if (temp == "odd")
        {
            a[i].v = 1;
        }
        else
            a[i].v = 0;
        b[++l] = a[i].l;
        b[++l] = a[i].r;
    }
    sort(b + 1, b + 1 + l);
    l = unique(b + 1, b + 1 + l) - b - 1;
    for (int i = 1; i <= 2 * l ; i++)
    {
        s[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        a[i].l = lower_bound(b + 1, b + l + 1, a[i].l) - b;
        a[i].r = lower_bound(b + 1, b + l + 1, a[i].r) - b;
        if (a[i].v == 1)
        {
            if (get(a[i].l) == get(a[i].r))
            {
                cout << i - 1;
                return 0;
            }
            else
            {
                unit(a[i].l + l, a[i].r);
                unit(a[i].l, a[i].r + l);
            }
        }
        else
        {
            if (get(a[i].l) == get(a[i].r + l))
            {
                cout << i - 1;
                return 0;
            }
            else
            {
                unit(a[i].l, a[i].r);
                unit(a[i].r + l, a[i].l+l);
            }
        }
    }
    cout << m;
    return 0;
}
