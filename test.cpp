#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
struct Point
{
    int x, y, id;
    Point(int x, int y, int id) : x(x), y(y), id(id) {}
    Point() {}
} test2[20];
const bool operator<(struct Point a, struct Point b)
{
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}
int len = 9;
int main()
{
    string temp = "x1234";
    string temp2 = string(temp.begin() + 1, temp.end());
    set<Point> st;
    st.insert(Point(1, 2, 3));
    st.insert(Point(1, 3, 4));
    st.insert(Point(1, 5, 6));
    st.insert(Point(1, 4, 5));
    test2[len++] = Point(1, 2, 3);
    for (auto it : st)
    {
        cout << it.x << ' ' << it.y << ' ' << endl;
    }
    st.erase(Point(1, 4, 5));

    for (auto it : st)
    {
        cout << it.x << ' ' << it.y << ' ' << endl;
    }
    cout << temp2;

    cout << "_______________________" << endl;
    string a = "hallo";
    cout << string(a.begin(), a.begin() + 1);
}