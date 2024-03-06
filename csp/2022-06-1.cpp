#include <bits/stdc++.h>
using namespace std;
int n, sum;
double ave, d;
int a[1001];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    ave = (double)sum / (double)n;
    for (int i = 0; i < n; i++)
    {
        d += ((double)a[i] - ave) * ((double)a[i] - ave);
    }
    d = d / (double)n;
    for (int i = 0; i < n; i++)
    {
        double temp = (a[i] - ave) / (sqrt(d));
        printf("%f\n", temp);
    }
    return 0;
}