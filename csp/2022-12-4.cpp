#include <bits/stdc++.h>
using namespace std;
int n, p[3001], a[3001];
struct worker
{
    int id; // 自己的id
    int a;  // 请假时间
    int p;  // 上级
} w[3001];

vector<struct worker> child[3001];  // 保存所有子节点（包括子节点的子节点）
vector<struct worker> child1[3001]; // 保存第一层子节点
void getChild(int i, int j)         // 父节点是i 子节点是j  要把j的所有子节点都填入到i的child数组中
{
    if (child1[j].size() == 1)
    {
        child[i].push_back(child1[j][0]);
        return;
    }
    for (auto item : child1[j])
    {
        if (item.id == j)
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
        int anx = 0; // 求和
        for (int j = 0; j < child[i].size(); j++)
        {
            int l, r, mini = 1e9;
            if (j != 0)
            {
                mini = min(abs(child[i][j].a - child[i][j - 1].a), mini);
            }
            if ((j + 1) != child[i].size())
            {
                mini = min(abs(child[i][j].a - child[i][j + 1].a), mini);
            }
            anx += mini * mini;
        }
        cout << anx << endl;
    }
    return 0;
}
