#include <bits/stdc++.h>
using namespace std;
int n, k, type_num;
int x[20];
bool check(int sum)
{
    for (int i = 2; i < sum; i++)
    {
        if (sum % i == 0)
        {
            return false;
        }
    }
    return true;
}
void dfs(int sum, int i, int j)
{
    if (i == k)
    {
        if (check(sum))
            type_num++;
        return;
    }
    for (int k = j + 1; k <= n; k++)
    {
        dfs(sum + x[k], i + 1, k);
    }
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    dfs(0, 0, 0);
    cout << type_num;
    return 0;
}