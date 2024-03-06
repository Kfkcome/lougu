#include <bits/stdc++.h>
using namespace std;
int n, x;
int a[31];
int mini = 1e9;
int s;
void dfs(int i, int sum)
{
    if (sum < x)
        return;
    mini = min(mini, sum);
    if (i == n)
        return;
    dfs(i + 1, sum - a[i]);
    dfs(i + 1, sum);
}
int main()
{
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    dfs(0, s);
    cout << mini;
    return 0;
}