#include <bits/stdc++.h>
using namespace std;
int count1[2000001];
int main()
{
    int n;
    cin >> n;
    double *a = new double[n];
    int *t = new int[n];
    int max1 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> t[i];
        max1 = max((int)(a[i] * t[i]), max1);
    }
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i <= t[j]; i++)
        {
            count1[(int)(a[j] * i)]++;
        }
    }
    for (int i = 1;i<=max1 ;i++)
    {
        if (count1[i] % 2 == 1)
        {
            cout << i;
            break;
        }
    }
    return 0;
}