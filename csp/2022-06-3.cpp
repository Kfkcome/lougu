#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int main()
{
    freopen("1.txt", "r", stdin);
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        int nv;
        cin >> nv;
        for (int j = 0; j < nv; j++)
        {
            string ops;
            cin >> ops;
        }
        int no;
        cin >> no;
        for (int j = 0; j < no; j++)
        {
            string type; // 资源种类
            cin >> type;
        }
        int nn;
        cin >> nn;
        for (int j = 0; j < nn; j++)
        {
            string name; // 资源名字
            cin >> name;
        }
    }
    for (int i = 0; i < m; i++)
    {
        string name; // 角色名称
        int ns;
        cin >> name >> ns;
        for (int j = 0; j < ns; j++)
        {
            string type, name;
            cin >> type >> name;
        }
    }
    for (int i = 0; i < q; i++)
    {
        string name;
        int ng;
        cin >> name >> ng;
        for (int j = 0; j < ng; j++)
        {
            string groupname;
            cin >> groupname;
        }
        string opera;
        int srckind, srcname;
        cin >> opera;
        cin >> srckind >> srcname;
    }
    return 0;
}