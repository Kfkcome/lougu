#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, p, q;

struct Point
{
    Point() {}

    Point(int _x, int _y, int _id)
    {
        x = _x;
        y = _y;
        id = _id;
    }

    int x, y;
    int id;
} pt[100010];

const bool operator<(const Point &a, const Point &b)
{
    if (a.x != b.x)
        return a.x < b.x;
    else
        return a.y < b.y;
}

map<int, int> setid[4];
vector<set<Point> *> st;

void set_insert(int type, int x, Point pnt)
{
    if (setid[type][x] == 0)
    {
        st.push_back(new set<Point>());
        setid[type][x] = st.size() - 1;
    }

    st[setid[type][x]]->insert(pnt);
}

void set_delete(int type, int x, Point pnt)
{
    st[setid[type][x]]->erase(pnt);
}

int find_dir[4][2] = {{0, 4}, {6, 2}, {7, 3}, {5, 1}};
int dir[8][2] = {{0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}};
int find_res[8][2]; // id, k

void set_find(int type, int x, Point pnt)
{
    int id = setid[type][x];

    if (id == 0)
        return;

    set<Point>::iterator it_upper = st[id]->upper_bound(pnt);
    set<Point>::iterator it_lower = st[id]->lower_bound(pnt);

    if (it_lower != st[id]->begin())
    {
        it_lower--;
        find_res[find_dir[type][0]][0] = it_lower->id;
        find_res[find_dir[type][0]][1] = max(abs(it_lower->x - pnt.x), abs(it_lower->y - pnt.y));
    }

    if (it_upper != st[id]->end())
    {
        find_res[find_dir[type][1]][0] = it_upper->id;
        find_res[find_dir[type][1]][1] = max(abs(it_upper->x - pnt.x), abs(it_upper->y - pnt.y));
    }
}

void insert_point(Point pnt)
{
    int x = pnt.x, y = pnt.y;
    set_insert(0, x, pnt);
    set_insert(1, y, pnt);
    set_insert(2, x - y, pnt);
    set_insert(3, x + y, pnt);
}

void delete_point(Point pnt)
{
    int x = pnt.x, y = pnt.y;
    set_delete(0, x, pnt);
    set_delete(1, y, pnt);
    set_delete(2, x - y, pnt);
    set_delete(3, x + y, pnt);
}

void find_point(int x, int y)
{
    for (int i = 0; i < 8; i++)
        find_res[i][0] = find_res[i][1] = -1;

    Point pnt = Point(x, y, 0);
    set_find(0, x, pnt);
    set_find(1, y, pnt);
    set_find(2, x - y, pnt);
    set_find(3, x + y, pnt);
}

void solve(int x, int y, int t)
{
    find_point(x, y);

    int limit = min(min(x - 1, n - x), min(y - 1, m - y));
    int k = limit + 1;

    for (int i = 0; i < 8; i++)
    {
        if (find_res[i][1] != -1 && find_res[i][1] <= limit)
            k = min(k, find_res[i][1]);
    }

    if (k == limit + 1)
        return;

    for (int i = 0; i < 8; i++)
        if (find_res[i][1] == k)
        {
            int id = find_res[i][0];
            delete_point(pt[id]);
            pt[id].x = x + dir[(i + t) % 8][0] * k;
            pt[id].y = y + dir[(i + t) % 8][1] * k;
        }

    for (int i = 0; i < 8; i++)
        if (find_res[i][1] == k)
        {
            int id = find_res[i][0];
            insert_point(pt[id]);
        }
}

int main()
{
    cin >> n >> m >> p >> q;
    st.push_back(new set<Point>()); // occupy index 0

    for (int i = 1; i <= p; i++)
    {
        int x, y;
        cin >> x >> y;
        pt[i] = Point(x, y, i);
        insert_point(pt[i]);
    }

    for (int i = 1; i <= q; i++)
    {
        int x, y, t;
        cin >> x >> y >> t;

        solve(x, y, t);
    }

    ll ans = 0;
    for (int i = 1; i <= p; i++)
        ans = ((ll)ans) ^ ((ll)i * (ll)pt[i].x + (ll)pt[i].y);
    cout << ans << endl;

    return 0;
}
