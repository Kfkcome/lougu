#include <bits/stdc++.h>
using namespace std;
int n, m;
// 计算节点
struct compute_node
{
    int id;
    int l;           // 位于编号为l的可用区中
    vector<int> app; // 节点中的计算应用
} node[1001];
// 计算区/可用区
struct compute_part
{
    int id;                                   // 编号
    unordered_set<int> nodein;                // 计算节点
    map<int, unordered_set<int>> app_to_node; // 通过app的编号id找到计算节点的集合
} part[1001];
unordered_map<int, unordered_set<int>> app_to_allnode; /// 如果没有节点亲和性 从全局里面找应用亲和性
unordered_map<int, unordered_set<int>> app_to_part;    //
unordered_set<int> all_compute_node;
bool cmp(struct compute_node a, struct compute_node b)
{
    if (a.app.size() == b.app.size())
    {
        return a.id < b.id;
    }
    return a.app.size() < b.app.size();
}

int main()
{
    // freopen("1.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> node[i].l;
        node[i].id = i;
        part[node[i].l].nodein.insert(i);
        all_compute_node.insert(i);
    }
    int g;
    cin >> g;
    for (int i = 1; i <= g; i++)
    {
        int f, a, na, pa, paa, paar;
        cin >> f >> a >> na >> pa >> paa >> paar;
        for (int j = 1; j <= f; j++)
        {
            unordered_set<int> alloc;      // 分配的节点
            unordered_set<int> alloc_part; // 分配的区的编号
            unordered_set<int> have_app;   // 包含paa这个应用的节点
            if (na != 0)                   // 如果有可用区亲和性
            {
                alloc = part[na].nodein;
                alloc_part.insert(na);
                if (alloc.empty())
                {
                    cout << 0 << ' ';
                    continue;
                }
                have_app = part[na].app_to_node[paa];
            }
            else // 如果没有可用区亲和性
            {
                alloc = all_compute_node;
                have_app = app_to_allnode[paa];
            }
            if (pa != 0) // 如果有应用亲和性 得在同一个区才行
            {
                unordered_set<int> hava_app_part = app_to_part[pa]; // 包含pa的可用区的集合
                if (hava_app_part.empty())
                {
                    cout << 0 << ' ';
                    continue;
                }
                if (!alloc_part.empty()) // 说明有可用区亲和性
                {
                    for (auto item : alloc_part)
                    {
                        if (hava_app_part.count(item) == 0)
                            alloc_part.erase(item);
                    }
                    if (alloc_part.empty())
                    {
                        cout << 0 << ' ';
                        continue;
                    }
                }
                else // 说明没有可用区亲和性
                {
                    alloc_part = hava_app_part;
                    have_app.clear();
                    alloc.clear();
                    for (auto item : alloc_part)
                    {
                        alloc.insert(part[item].nodein.begin(), part[item].nodein.end());
                        have_app.insert(part[item].app_to_node[paa].begin(), part[item].app_to_node[paa].end());
                    }
                }
            }
            if (paa != 0) // 如果应用反亲和性
            {
                unordered_set<int> temp = alloc;
                for (auto item : have_app)
                {
                    temp.erase(item);
                }
                if (temp.empty() && paar == 1) // 如果要强制满足 但是又为空
                {
                    cout << 0 << ' ';
                    continue;
                }
                if (!temp.empty())
                    alloc = temp;
            }

            struct compute_node min_node;
            min_node.id = 0;
            for (auto item : alloc)
            {
                if (min_node.id == 0 || cmp(node[item], min_node))
                {
                    min_node = node[item];
                }
            }
            node[min_node.id].app.push_back(a);
            app_to_allnode[a].insert(min_node.id);
            app_to_part[a].insert(min_node.l);
            part[min_node.l].app_to_node[a].insert(min_node.id);
            cout << min_node.id << ' ';
        }
        cout << endl;
    }
    return 0;
}