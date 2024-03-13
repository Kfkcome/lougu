#include <bits/stdc++.h>
using namespace std;
int n, N;
int a[100001];
int main()
{
    cin >> n >> N;
    int maxa = -1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxa = max(a[i], maxa);
    }
    int r = N / (n + 1);
    int f = 0;
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        // 判断g和f谁先变
        // f是遇到元素才变 g是隔r个数就变的
        f = i - 1;
        int length = a[i] - a[i - 1];
        int gl = a[i - 1] / r;
        int gr = (a[i] - 1) / r; // 不包括右端点，因为右端点f的值已经变化了
        if (gr == gl)            // 如果这个区间g的值没有变化
        {
            sum += abs(f - gl) * length;
        }
        else // 如果g有变化那么再分区间
        {
            int left = a[i - 1]; // 不断更新区间的左端点 知道超过f不变的区间
            while (left < a[i])
            {
                int length = min(a[i], (gl + 1) * r) - left;
                sum += abs(f - gl) * length;
                // 更新状态
                left = (gl + 1) * r;
                gl++;
            }
        }
    }
    if (maxa < N) // 遍历超出了a的数，此时f恒等于n g还是原来的变化规律
    {
        int f = n;
        int left = a[n];
        int gl = left / r;
        while (left <= N)
        {
            int length = min(N, (gl + 1) * r) - left;
            sum += abs(f - gl) * length;
            // TODO：更新状态
            left = (gl + 1) * r;
            gl++;
        }
    }
    cout << sum;
    return 0;
}