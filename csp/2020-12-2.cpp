#include <bits/stdc++.h>
using namespace std;
int m;
int theta[100001]; // 存储对应阈值 对应的正确的数量
struct stu
{
    int y;
    int r;
} s[100001];
bool cmp(struct stu a, struct stu b)
{
    return a.y < b.y;
}
int main()
{
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> s[i].y >> s[i].r;
    }
    sort(s + 1, s + m + 1, cmp);
    for (int i = 1; i <= m; i++)
    {
        if (s[i].r == 0)
        {
            int j = i;
            while (j <= m && s[i].y == s[j].y) // 向后找到第一个不等于他的
                j++;
            theta[j]++;
            theta[m + 1]--;
        }
        else
        {
            int j = i + 1;
            while (j <= m && s[i].y == s[j].y) // 向后找到第一个不等于他的
                j++;
            theta[j]--;
            theta[1]++;
        }
    }
    int max = -1;
    for (int i = 1; i <= m; i++)
    {
        theta[i] += theta[i - 1];
        if (max == -1 || theta[i] >= theta[max]) // 如果相同则找到最大的
        {
            max = i;
        }
    }
    cout << s[max].y;
    return 0;
}