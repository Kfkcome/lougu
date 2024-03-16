#include <bits/stdc++.h>
using namespace std;
int n, a[500001], p[10001];
// 定义p[i]是不超过i的非零段的个数
// 那么p[i]-p[i-1]的含义是在i-1为0的基础上增加i为0后非零段的个数的增加
int main()
{
    cin >> n;
    int max_a = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i]; // 输入数据
        max_a = max(max_a, a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > a[i - 1])//如果前一个大于后一个
        {
            p[a[i - 1] + 1]++;
            p[a[i] + 1]--;
        }
    }
    int max_p = 0;
    for (int i = 1; i <= max_a + 1; i++)
    {
        p[i] += p[i - 1];
        max_p = max(max_p, p[i]);
    }
    cout << max_p;
    return 0;
}