#include <bits/stdc++.h>
using namespace std;
int n;
struct worker
{
    int id;      // 自己的id
    long long a; // 请假时间
    int p;       // 上级
} w[300001];

vector<struct worker> child[300001];  // 保存所有子节点（包括子节点的子节点）
vector<struct worker> child1[300001]; // 保存第一层子节点
void getChild(int i, int j)           // 父节点是i 子节点是j  要把j的所有子节点都填入到i的child数组中
{
    if (child1[j].size() == 1)
    {
        child[i].push_back(child1[j][0]);
        return;
    }
    for (auto item : child1[j])
    {
        if (item.id == j) // 因为此数组中包括本节点，防止无限递归所以使用了特殊处理此节点
        {
            child[i].push_back(item);
        }
        else
            getChild(i, item.id);
    }
}
bool cmp(struct worker a, struct worker b)
{
    return a.a < b.a;
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
        child1[i].push_back(w[i]);      // 自己是自己的员工
        child1[w[i].p].push_back(w[i]); // 自己是上级的员工
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto item : child1[i])
        {
            if (item.id == i)
            {
                child[i].push_back(item);
            }
            else
                getChild(i, item.id);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        sort(child[i].begin(), child[i].end(), cmp);
    }

    for (int i = 1; i <= n; i++)
    {
        long long anx = 0; // 求和
        for (int j = 0; j < child[i].size(); j++)
        {
            long long mini = 1e9 + 1;
            if (j != 0)
            {
                mini = min(abs(child[i][j].a - child[i][j - 1].a), mini);
            }
            if ((j + 1) != child[i].size())
            {
                mini = min(abs(child[i][j].a - child[i][j + 1].a), mini);
            }
            if (mini != 1e9 + 1) // 有可能没有其他子节点了，所以就是加0 而不是（1e9)的平方
                anx += mini * mini;
        }
        cout << anx << endl;
    }
    return 0;
}
