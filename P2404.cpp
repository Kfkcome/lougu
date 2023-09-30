#include <bits/stdc++.h>
using namespace std;
int n;
list<int> temp;
void show(list<int> temp)
{
    list<int>::iterator it = temp.begin();
    for (; it != temp.end(); it++)
    {
        if (it != temp.begin())
        {
            cout << '+';
        }
        cout << *it;
    }
    cout << endl;
}
void dfs(int lastone, int x, int level)
{
    if (x == 0)
    {
        show(temp);
        return;
    }
    for (int i = lastone; i <= n - level + 1; i++)
    {
        if (i < n)
        {
            temp.push_back(i);
            dfs(i, x - i, level + 1);
            temp.pop_back();
        }
    }
}
int main()
{
    cin >> n;
    dfs(1, n, 1);
    return 0;
}