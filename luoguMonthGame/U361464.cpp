#include <bits/stdc++.h>
using namespace std;
struct values
{
    long pol, value;
};
int grid[501], n, k, max_kind;
int length = 1;
unsigned value[501];
unsigned long long max_value;
struct values v[501];
bool inList[501];
bool inGrid[501];
bool cmp(struct values a, struct values b)
{
    return a.value >= b.value;
}
bool check()
{
    int last = 0;
    for (int i = 1; i <= n; i++)
    {
        if (inList[grid[i]])
        {
            if (grid[i] < last)
            {
                return false;
            }
            last = grid[i];
        }
    }
    return true;
}
bool dfs(int num, int pol, unsigned long long count)
{
    if (num == k)
    {
        if (check())
        {
            max_value = count;
            return true;
        }
        else
            return false;
    }
    if (pol >= length)
    {
        return false;
    }
    if (inGrid[v[pol].pol])
    {
        inList[v[pol].pol] = true;
        if (dfs(num + 1, pol + 1, count + v[pol].value))
            return true;
        inList[v[pol].pol] = false;
    }
    if (dfs(num, pol + 1, count))
    {
        return true;
    }
    return false;
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> grid[i];
        inGrid[grid[i]] = true;
        max_kind = max(max_kind, grid[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> value[i];
        if (inGrid[i])
        {
            v[length].pol = i;
            v[length].value = value[i];
            length++;
        }
    }
    sort(v + 1, v + length + 1, cmp);
    if (dfs(0, 1, 0))
    {
        cout << max_value;
    }
    else
        cout << -1;
    return 0;
}