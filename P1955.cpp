#include <bits/stdc++.h>
using namespace std;
int pre[1000007], book[1000007 * 3];
struct node
{
    int a, b, e;
};
struct node ne[1000001];
int find(int x)
{
    if (pre[x] != x)
        return pre[x] = find(pre[x]);
    return x;
} // 并查集查询
void join(int x, int y)
{
    pre[find(y)] = find(x);
} // 并查集融合
inline void first(int kkk)
{
    for (int i = 0; i <= kkk; i++)
        pre[i] = i;
} // 初 始 化
bool cmp(node a, node b)
{
    return a.e > b.e;
}
int main()
{
    int t;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        memset(book,0,sizeof(book));
        memset(ne,0,sizeof(ne));
        memset(pre,0,sizeof(pre));
        int n, pol = -1;
        cin >> n;
        bool flag = false;
        for (int i = 1; i <= n; i++)
        {
            int a, b, e;
            cin >> ne[i].a >> ne[i].b >> ne[i].e;
            book[++pol] = ne[i].a;
            book[++pol] = ne[i].b;
        }
        sort(book, book + pol + 1);
        int uni = unique(book, book + pol + 1) - book;
        first(uni); // 初始化pre数组
        for (int i = 1; i <= n; i++)
        {
            ne[i].a = lower_bound(book, book + uni, ne[i].a) - book;
            ne[i].b = lower_bound(book, book + uni, ne[i].b) - book;
        }
        sort(ne + 1, ne + 1 + n, cmp);
        for (int i = 1; i <= n; i++)
        {
            int p1 = find(ne[i].a);
            int p2 = find(ne[i].b);
            if (ne[i].e) // 如果相等的话，就让两者合并入一个集合，如果在同一个集合中也不影响
            {
                pre[p1]=p2;
            }
            else
            { // 如果不相等的话判断是不是在一个集合中如果是则不满足条件
                if (p1 == p2)
                {
                    flag = true;
                    break;
                }
            }
        }
        if (flag)
        {
            cout << "NO" << endl;
        }
        else
            cout << "YES" << endl;
    }
    return 0;
}