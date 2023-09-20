#include <bits/stdc++.h>
using namespace std;
int n;
struct food
{
    int s, b;
};
long mini_sb = 1 << 29;
struct food f[11];
void dfs(int i, long s, long b)
{
    if (i != 0)
        mini_sb = min(mini_sb, abs(s - b));
    for (int k = i + 1; k <= n; k++)
    {
        dfs(k, s * f[k].s, b + f[k].b);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i].s >> f[i].b;
    }
    dfs(0, 1, 0);
    cout << mini_sb;
    return 0;
}