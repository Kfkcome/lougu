#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int devote[200001];
int work[200001];
int main()
{
    // freopen("1.txt", "r", stdin);
    cin >> n >> m >> q;
    for (int i = 0; i < q; i++)
    {
        int kind;
        cin >> kind;
        if (kind == 1)
        {
            int l, r, x;
            cin >> l >> r >> x;
            for (int i = l; i <= r; i++)
            {
                devote[i] = x;
            }
        }
        else if (kind == 2)
        {
            int x, w;
            cin >> x >> w;
            for (int i = 1; i <= n; i++)
            {
                if (devote[i] == x)
                {
                    devote[i] = w;
                }
            }
        }
        else if (kind == 3)
        {
            int x, y;
            cin >> x >> y;
            for (int i = 1; i <= n; i++)
            {
                if (devote[i] == x)
                {
                    devote[i] = y;
                }
                else if (devote[i] == y)
                {
                    devote[i] = x;
                }
            }
        }
        else if (kind == 4)
        {
            int w;
            cin >> w;
            int sum = 0;
            for (int i = 1; i <= n; i++)
            {
                if (devote[i] == w)
                    sum++;
            }
            cout << sum << endl;
        }
        else if (kind == 5)
        {
            int maxi = -1;
            for (int i = 1; i <= n; i++)
            {
                work[devote[i]]++;
                if (devote[i] != 0 && ((maxi == -1) || work[devote[i]] > work[maxi]))
                {
                    maxi = devote[i];
                }
            }
            if (maxi == -1)
                cout << 0 << endl;
            else
                cout << maxi << endl;
            memset(work, 0, n);
        }
    }

    return 0;
}