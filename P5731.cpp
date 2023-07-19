#include <bits/stdc++.h>
using namespace std;
int a[10][10];
int main()
{
    int n;
    int n1;
    int num = 1;
    cin >> n;
    n1 = n;
    int x = 0;
    while (n > 0)
    {
        for (int j = x; j < n + x; j++)
        {
            a[x][j] = num;
            num++;
        }

        if (num > n1 * n1)
            break;
        for (int j = x + 1; j < n + x; j++)
        {
            a[j][x + n - 1] = num;
            num++;
        }
        if (num > n1* n1)
            break;
        for (int j = x + n - 2; j >= x; j--)
        {
            a[x + n - 1][j] = num;
            num++;
        }
        if (num > n1 * n1)
            break;
        for (int j = x + n - 2; j > x; j--)
        {
            a[j][x] = num;
            num++;
        }
        if (num > n1 * n1)
            break;
        n = n - 2;
        x++;
    }
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            if (a[i][j] >= 10)
            {
                cout << ' ' << a[i][j];
            }
            else
                cout << "  " << a[i][j];
        }
        cout << endl;
    }
    return 0;
}