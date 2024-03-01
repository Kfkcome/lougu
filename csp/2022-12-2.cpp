#include <bits/stdc++.h>
using namespace std;
int n, m;
int p[10001], t[10001];
vector<int> c[10001]; // 对应i课程的后置课程
int min_start[101], max_start[101];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> p[i];
        c[p[i]].push_back(i);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> t[i];
    }
    int maxTime = -1;
    for (int i = 1; i <= m; i++)
    {
        if (p[i] == 0)
        {
            min_start[i] = 1;
        }
        else
        {
            min_start[i] = min_start[p[i]] + t[p[i]];
        }
        maxTime = max(maxTime, min_start[i] + t[i] - 1);
    }
    for (int i = 1; i <= m; i++)
    {
        cout << min_start[i] << ' ';
    }
    if (maxTime <= n)
    {
        for (int i = m; i > 0; i--)
        {
            if (c[i].empty())
            {
                max_start[i] = n - t[i] + 1;
            }
            else
            {
                int max_time = c[i][0];
                for (int j = 0; j < c[i].size(); j++)
                {
                    if (max_start[c[i][j]] < max_start[max_time])
                    {
                        max_time = c[i][j];
                    }
                }
                max_start[i] = max_start[max_time] - t[i];
            }
        }
        cout << endl;
        for (int i = 1; i <= m; i++)
        {
            cout << max_start[i] << ' ';
        }
    }
    return 0;
}