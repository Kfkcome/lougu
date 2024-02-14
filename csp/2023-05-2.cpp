#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, d;
int q[10001][21], v[10001][21], w[10001], K[10001][21];
ll res1[10001];
int main()
{
    cin >> n >> d;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < d; j++)
        {
            cin >> q[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < d; j++)
        {
            cin >> K[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < d; j++)
        {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    // 计算QxK的逆
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ll temp = 0;
            for (int k = 0; k < d; k++)
            {
                temp += q[i][k] * K[j][k];
            }
            res1[j] = temp * w[i];
        }
        for (int j = 0; j < d; j++)
        {
            ll temp = 0;
            for (int k = 0; k < n; k++)
            {
                temp += res1[k] * v[k][j];
            }
            cout << temp << ' ';
        }
        cout << endl;
    }
    return 0;
}
