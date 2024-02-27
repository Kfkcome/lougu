#include <bits/stdc++.h>
using namespace std;
int n, m;
double k[100001], o[100001];
double k1[100001], o1[100001];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        if (temp == 1)
        {
            cin >> k1[i];
        }
        else
        {
            cin >> o1[i];
        }
    }
    k[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (k1[i] != 0)
            k[i] = k1[i] * k[i - 1];
        else
        {
            k[i] = k[i - 1];
        }
        o[i] = o1[i] + o[i - 1];
    }
    for (int z = 1; z <= m; z++)
    {
        int i, j;
        double x, y;
        cin >> i >> j >> x >> y;
        x *= k[j] / k[i - 1];
        y *= k[j] / k[i - 1];
        double temp = x, temp_o = o[j] - o[i - 1];
        x = cos(temp_o) * x - sin(temp_o) * y;
        y = sin(temp_o) * temp + cos(temp_o) * y;
        printf("%f %f\n", x, y);
    }
    return 0;
}