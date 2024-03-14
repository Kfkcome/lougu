#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int disk[10001];
int disk_belong[2][10001];
int main()
{
    // freopen("1.txt", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        int type;
        cin >> type;
        if (type == 0) // 写入操作
        {
            int id, l, r, x;
            cin >> id >> l >> r >> x;
            bool flag = true;
            for (int j = l; j <= r; j++)
            {
                if (disk_belong[1][j] != 0 && disk_belong[1][j] != id)
                {
                    if (j == l)
                        cout << -1 << endl;
                    else
                        cout << j - 1 << endl;
                    flag = false;
                    break;
                }
                disk[j] = x;
                disk_belong[1][j] = id;
            }
            if (flag)
            {
                cout << r << endl;
            }
        }
        if (type == 1)
        {
            int id, l, r;
            cin >> id >> l >> r;
            bool flag = true;
            for (int j = l; j <= r; j++)
            {
                if (disk_belong[1][j] != id)
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
            {
                cout << "FAIL" << endl;
            }
            else
            {
                for (int j = l; j <= r; j++)
                {
                    disk_belong[0][j] = disk_belong[1][j];
                    disk_belong[1][j] = 0;
                }
                cout << "OK" << endl;
            }
        }
        if (type == 2)
        {
            int id, l, r;
            cin >> id >> l >> r;
            bool flag = true;
            for (int j = l; j <= r; j++)
            {
                if (disk_belong[1][j] != 0 || disk_belong[0][j] != id)
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
            {
                cout << "FAIL" << endl;
            }
            else
            {
                for (int j = l; j <= r; j++)
                {
                    disk_belong[1][j] = id;
                    disk_belong[0][j] = 0;
                }
                cout << "OK" << endl;
            }
        }
        if (type == 3)
        {
            int p;
            cin >> p;
            if (disk_belong[1][p] == 0)
            {
                cout << "0 0" << endl;
            }
            else
            {
                cout << disk_belong[1][p] << ' ' << disk[p]<< endl;
            }
        }
    }
    return 0;
}