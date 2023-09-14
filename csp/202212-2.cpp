#include <bits/stdc++.h>
using namespace std;
int n, m;
int pre[366], t[366], s[366], last[366];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> pre[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> t[i];
    }
    for (int i = 1; i <= m; i++)
    {
        if (last[pre[i]] != 0)
        {
            if (t[last[pre[i]]] < t[i])
            {
                last[pre[i]] = i;
            }
        }
        else
            last[pre[i]] = i;
    }
    bool second_line = true;
    for (int i = 1; i <= m; i++)
    {
        if (!pre[i])
        {
            s[i] = 1;
        }
        else
        {
            s[i] = s[pre[i]] + t[pre[i]];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << s[i] << ' ';
        if (s[i] + t[i] - 1 > n)
        {
            second_line = false;
        }
    }
    if (!second_line)
    {
        return 0;
    }
    cout << endl;
    for (int i = m; i > 0; i--)
    {
        if (last[i] != 0) // 它不依赖与任何一个项目但是有项目依赖于它
        {
            int min_time = 99999;
            for (int j = i + 1; j <= m; j++)
            {
                if (pre[j] == i)
                    min_time = min(min_time, s[j]);
            }
            s[i] = min_time - t[i];
        }
        else
        {
            s[i] = n - t[i] + 1;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << s[i] << ' ';
    }
    return 0;
}