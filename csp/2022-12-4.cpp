#include <bits/stdc++.h>
using namespace std;
int n, p[3001], a[3001];
struct worker
{
    int id; // 自己的id
    int a;  // 请假时间
    int p;  // 上级
} w[3001];

vector<struct worker> child[3001]; // 使用有序集合进行二分
int getMin(int i, struct worker t) // 从i的子节点中（包括i）找距离t最近的节点
{
    if (child[i].size() == 1) // 如果是叶子节点
    {
        return abs(child[i][0].a - t.a);
    }
    int mini = -1;
    for (auto item : child[i])
    {
        if (item.id != t.id)
        {
            int dis;
            if (item.id != i) /// 如果不是他本身
                dis = getMin(item.id, t);
            else
                dis = abs(item.a - t.a);
            if (dis < mini || mini == -1)
            {
                mini = dis;
            }
        }
    }
    if (mini == -1)
        mini = 0;
    return mini;
}
int main()
{
    cin >> n;
    for (int i = 2; i <= n; i++) // 编号为1的是公司的唯一老板
    {
        cin >> w[i].p;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i].a;
        w[i].id = i;
        child[i].push_back(w[i]);      // 自己是自己的员工
        child[w[i].p].push_back(w[i]); // 自己是上级的员工
    }
    for (int i = 1; i <= n; i++)
    {
        int anx = 0;               // 求和
        for (auto item : child[i]) // 获取每一项
        {
            int min1 = getMin(i, item);
            anx += min1 * min1;
        }
        cout << anx << endl;
    }
    return 0;
}
