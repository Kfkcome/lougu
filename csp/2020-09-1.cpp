#include <bits/stdc++.h>
using namespace std;
int x[201], y[201];
int n, X, Y;
int m[4];
int d[4];
bool check(int j, int key)
{
    for (int i = 1; i < j; i++)
    {
        if (m[i] == key)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    cin >> n >> X >> Y;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }
    for (int j = 1; j <= 3; j++)
    {
        d[j] = 1e9;
        for (int i = 1; i <= n; i++)
        {
            int dis = (X - x[i]) * (X - x[i]) + (Y - y[i]) * (Y - y[i]);
            if (dis < d[j] && check(j, i))
            {
                d[j] = dis;
                m[j] = i;
            }
        }
        cout << m[j] << endl;
    }
    return 0;
}