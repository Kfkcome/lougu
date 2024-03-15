#include <bits/stdc++.h>
using namespace std;
int n, a[500001], p[10001];
int main()
{
    cin >> n;
    int max_a = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i]; // 输入数据
        max_a = max(max_a, a[i]);
    }
    // 从a更新p 如果a[i+1]>a[i]
    // 那么p[a[i+1]]-1到p[a[i]]这个区间内都可以增加一个非零段
    // 不用判断是不是区间是不是减少
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i + 1] < a[i])
        {
            p[a[i + 1]]++;
            p[a[i]]--;
        }
        if (a[i + 1] > a[i])
        {
            
        }
        if (i == n - 2) // 特判倒数第二个
        {
            if (a[i + 1] > a[i])
            {
                p[a[i + 1]]--;
                p[a[i]]++;
            }
        }
    }
    int max_p = 0;
    for (int i = 0; i < max_a + 1; i++)
    {
        if (i > 0)
            p[i] += p[i - 1];
        max_p = max(max_p, p[i]);
    }
    cout << max_p;
    return 0;
}