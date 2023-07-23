#include <bits/stdc++.h>
using namespace std;
struct stone
{
    long long w; // 重量
    long long v; // 价值
};
bool compare(struct stone s1, struct stone s2)
{
    return s1.w < s2.w;
}
int main()
{
    long long n, m, s;
    cin >> n >> m >> s;
    struct stone rock[200001];
    struct stone rock_list[200001];
    for (int i = 1; i <= n; i++)
    {
        cin >> rock[i].w >> rock[i].v;
        rock_list[i].w = rock[i].w;
        rock_list[i].v = rock[i].v;
    }
    long *l = new long[m], *r = new long[m];
    for (int i = 0; i < m; i++)
    {
        cin >> l[i] >> r[i];
    }
    sort(rock_list + 1, rock_list + n, compare);
    long mini = 0x3f3f3f3f3f3f3f3f;
    int left = 0, right = n, mid = (right + left) / 2;
    while (left <= right)
    {
        // 使用前缀和
        struct stone *rock_temp = new struct stone[n + 1];
        long *num = new long[n + 1];
        num[0] = 0;
        rock_temp[0].v = 0;
        rock_temp[0].w = 0;
        for (int i = 1; i <= n; i++)
        {
            if (rock[i].w >= rock_list[mid].w + 1)
            {
                rock_temp[i].v = rock[i].v + rock_temp[i - 1].v;
                num[i] = num[i - 1] + 1;
            }
            else
            {
                rock_temp[i].v = rock_temp[i - 1].v;
                num[i] = num[i - 1];
            }
        }
        long long y = 0;
        for (int i = 0; i < m; i++)
        {
            long l1 = l[i];
            long r1 = r[i];
            y += (num[r1] - num[l1 - 1]) * (rock_temp[r1].v - rock_temp[l1 - 1].v);
        }
        // 这是未使用前缀和的过程
        //  long long y = 0;
        //  for (int j = 0; j < m; j++)
        //  {
        //      long l1 = l[j];
        //      long r1 = r[j];
        //      long num = 0;
        //      long long sum = 0;
        //      for (int k = l1; k <= r1; k++)
        //      {
        //          if (rock[k].w >= rock_list[mid].w + 1)
        //          {
        //              num++;
        //              sum += rock[k].v;
        //          }
        //      }
        //      y += sum * num;
        //  }
        if (llabs(y - s) < mini)
        {
            mini = llabs(y - s);
        }
        if (y < s)
        {
            right = mid - 1;
        }
        else if (y == s)
        {
            break;
        }
        else if (y > s)
        {
            left = mid + 1;
        }
        mid = (left + right) / 2;
    }
    cout << mini;
}
