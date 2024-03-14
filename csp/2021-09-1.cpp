#include <bits/stdc++.h>
using namespace std;
int n, sum_min, sum_max;
int b[101];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    // 计算最大的情况
    for (int i = 0; i < n; i++)
    {
        sum_max += b[i];
    }
    sum_min += b[0];
    for (int i = 1; i < n; i++)
    {
        if (b[i] != b[i - 1])
        {
            sum_min += b[i];
        }
    }
    cout << sum_max << endl;
    cout << sum_min << endl;
    return 0;
}