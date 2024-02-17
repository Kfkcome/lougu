#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct point
{
    int x, y;
    int id;
    point(int x, int y, int id) : x(x), y(y), id(id) {}
    point() {}

} peo[100001];
// 结构体符号重载
const bool operator<(struct point a, struct point b)
{
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}
int d[8][2] = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};
map<int, int> mp[4]; // 存储位置和对应  //0行  1列 2斜线 3反斜线
vector<set<point>> points;
int n, m, p, q;
int resDis[8];           // 存储离的最近的哪些点的距离
struct point miniDis[8]; // 存储离的最近的哪些点
int len = 0;             // 存储离的最近的哪些点的长度
int getDistance(int u, int v, int x1, int y1)
{
    int tempd = 0;
    if (x1 == u)
    {
        tempd = abs(y1 - v);
    }
    else if (y1 == v)
    {
        tempd = abs(x1 - u);
    }
    else if (abs(x1 - u) == abs(y1 - v))
    {
        tempd = abs(x1 - u);
    }
    return tempd;
}
void insert_set(int type, int key, struct point people)
{
    if (mp[type].find(key) == mp[type].end() || mp[type][key] == 0)
    {
        set<point> temp;
        temp.insert(people);
        int id = points.size();
        points.push_back(temp);
        mp[type][key] = id;
    }
    else
    {
        int pos = mp[type][key];
        points[pos].insert(people);
    }
}
void delete_set(int type, int key, struct point people)
{
    int pos = mp[type][key];
    points[pos].erase(people);
}
void insert_mp(struct point people) // 要将 people 插入到行、列、斜线和反斜线的set中
{
    insert_set(0, people.y, people);
    insert_set(1, people.x, people);
    insert_set(2, people.y - people.x, people);
    insert_set(3, people.y + people.x, people);
}
void delete_mp(struct point people)
{
    delete_set(0, people.y, people);
    delete_set(1, people.x, people);
    delete_set(2, people.y - people.x, people);
    delete_set(3, people.y + people.x, people);
}
void searchSet(int type, int key, struct point p1)
{
    int pos = mp[type][key];
    if (pos == 0)
        return;
    // 因为一个set代表一个方向，一个方向上的最多有两个点距离最近
    set<point>::iterator l = points[pos].lower_bound(p1);
    set<point>::iterator r = points[pos].upper_bound(p1);
    if (r != points[pos].end() && l != points[pos].begin()) // 如果左右都有数据则取最近的那一个
    {
        l--;
        int r_dis = getDistance(p1.x, p1.y, r->x, r->y);
        int l_dis = getDistance(p1.x, p1.y, l->x, l->y);
        if (r_dis > l_dis)
        {
            miniDis[len++] = *l;
            resDis[len - 1] = l_dis;
        }
        else if (r_dis < l_dis)
        {
            miniDis[len++] = *r;
            resDis[len - 1] = r_dis;
        }
        else // 如果两个距离一样
        {
            miniDis[len++] = *r;
            resDis[len - 1] = r_dis;
            miniDis[len++] = *l;
            resDis[len - 1] = l_dis;
        }
    }
    else if (l != points[pos].begin())
    {
        l--;
        int l_dis = getDistance(p1.x, p1.y, l->x, l->y);
        miniDis[len++] = *l;
        resDis[len - 1] = l_dis;
    }
    else if (r != points[pos].end())
    {
        int r_dis = getDistance(p1.x, p1.y, r->x, r->y);
        miniDis[len++] = *r;
        resDis[len - 1] = r_dis;
    }
}

void changePoint(int k, struct point p1, int u, int v, int t)
{
    int direct;
    int x = p1.x, y = p1.y;
    int pos = p1.id;
    for (direct = 0; direct < 8; direct++)
    {
        if (x == u + k * d[direct][0] && y == v + k * d[direct][1])
        {
            break;
        }
    }
    peo[pos].x = u + k * d[(direct + t) % 8][0];
    peo[pos].y = v + k * d[(direct + t) % 8][1];
}
void solve(int u, int v, int t)
{
    int toBoard = min(min(u - 1, n - u), min(v - 1, m - v));
    int toPeo = -1; // 离人最近的距离
    len = 0;
    // 二分查找离阴阳龙最近的人的位置
    // 将离得最近的那些人的指针放在一个数组中
    struct point temp = point(u, v, 0);
    searchSet(0, v, temp);
    searchSet(1, u, temp);
    searchSet(2, v - u, temp);
    searchSet(3, v + u, temp);

    for (int i = 0; i < len; i++)
    {
        if (toPeo == -1 || resDis[i] < toPeo)
        {
            toPeo = resDis[i];
        }
    }
    if (toPeo > toBoard)
    {
        return;
    }

    for (int i = 0; i < len; i++)
    {
        if (resDis[i] == toPeo)
        {
            delete_mp(peo[miniDis[i].id]);
            changePoint(toPeo, miniDis[i], u, v, t);
        }
    }
    for (int i = 0; i < len; i++)
    {
        if (resDis[i] == toPeo)
        {
            insert_mp(peo[miniDis[i].id]);
        }
    }
    len = 0;
}
int main()
{
    cin >> n >> m >> p >> q;
    points.push_back(set<point>());
    for (int i = 1; i <= p; i++)
    {
        cin >> peo[i].x >> peo[i].y;
        peo[i].id = i;
        insert_mp(peo[i]);
    }
    int u, v, t;
    for (int i = 1; i <= q; i++)
    {
        cin >> u >> v >> t;
        solve(u, v, t);
    }
    ll sum = 0;
    for (int i = 1; i <= p; i++)
    {
        //        cout<<peo[i].x<<' '<<peo[i].y<<endl;
        sum = ((ll)sum) ^ ((ll)i * (ll)peo[i].x + (ll)peo[i].y);
    }
    cout << sum;
    return 0;
}
