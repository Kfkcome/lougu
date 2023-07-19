#include <bits/stdc++.h>
using namespace std;
int a[101][101];
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int j = 0; j < m; j++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if (x - 2 >= 0)
            a[x - 2][y] = 1;
        for (int i = y - 1; i <= y + 1; i++)
        {
            if (x - 1 >= 0 && i >= 0 && i < n)
                a[x - 1][i] = 1;
        }
        for (int i = y - 2; i <= y + 2; i++)
        {
            if (i >= 0 && i < n)
            {
                a[x][i] = 1;
            }
        }
        for (int i = y - 1; i <= y + 1; i++)
        {
            if (x + 1 < n && i >= 0 && i < n)
                a[x + 1][i] = 1;
        }
        if (x + 2 < n)
            a[x + 2][y] = 1;
    }
    for (int i = 0; i < k; i++)
    {
        int o, p;
        cin >> o >> p;
        o--;
        p--;
        for (int j = o - 2; j <= o + 2; j++)
        {
            for (int z = p - 2; z <= p + 2; z++)
            {
                if (j >= 0 && j < n && z >= 0 && z < n)
                {
                    a[j][z] = 1;
                }
            }
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //cout<<a[i][j]<<' ';
            if (a[i][j] == 0)
                count++;
        }
        //cout<<endl;
    }
    cout << count;
}