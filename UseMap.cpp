#include <bits/stdc++.h>
using namespace std;
struct equal
{
    int id;
    int val;
    const bool operator=(struct equal a)
    {
        if (a.id == id && a.val == val)
            return true;
        return false;
    }
};
map<struct equal, int> m;
const bool operator<(struct equal a, struct equal b)
{
    return a.id < b.id;
}

int main()
{
    struct equal e, e1, e2;
    e.id = 1;
    e.val = 10;
    e1.id = 1;
    e.val = 11;
    m[e] = 10;
    m[e1] = 11;
    cout << m[e] << endl;
}