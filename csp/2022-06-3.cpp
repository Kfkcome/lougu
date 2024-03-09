#include <bits/stdc++.h>
using namespace std;
int n, m, q;
struct roler
{
    string name;
    unordered_map<string, int> op;
    bool op_all;
    unordered_map<string, int> src_kind;
    bool src_kind_all;
    unordered_map<string, int> src_name;
    bool src_name_all;
} r[501];
unordered_map<string, int> name_to_roler;

struct roler_user
{
    string name;
    vector<string> user;
    vector<string> group;
} con[501];
struct behave
{
    string user_name;
    vector<string> group;
    string operat;
    string src_kind;
    string src_name;
} un[5001];
unordered_map<string, unordered_set<int>> user_to_roler;
unordered_map<string, unordered_set<int>> group_to_roler;
// 检查这个角色有没有权限
bool check_roler(const struct behave &t, const int &id)
{
    // 检查该角色的操作清单，如果该角色的操作清单中不包含该操作，
    // 且该角色的操作清单中也不包含字符串 *，那么不能执行该操作；
    if (!r[id].op_all && r[id].op[t.operat] != 1)
        return false;

    // 检查该角色的资源种类清单，如果该角色的资源种类清单中不包含该资源的种类，
    // 且该角色的资源种类清单中也不包含字符串 *，那么不能执行该操作；
    if (!r[id].src_kind_all && r[id].src_kind[t.src_kind] != 1)
        return false;

    // 检查该角色的资源名称清单，如果该角色的资源名称清单中不包含该资源的名称，
    // 且该角色的资源名称清单不是空数组，那么不能执行该操作；
    if (!r[id].src_name.empty() && r[id].src_name[t.src_name] != 1)
        return false;

    return true;
}
bool check_all(const struct behave &t,const unordered_set<int> &s)
{
    for (auto item : s)
    {
        if (check_roler(t, item))
        {
            return true;
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("1.txt", "r", stdin);
    cin >> n >> m >> q;
    // 输入n个角色
    for (int i = 0; i < n; ++i)
    {
        string name;
        cin >> r[i].name;
        name_to_roler[r[i].name] = i;
        int nv;
        cin >> nv;
        for (int j = 0; j < nv; ++j)
        {
            string ops;
            cin >> ops;
            if (ops == "*")
                r[i].op_all = true;
            r[i].op[ops] = 1;
        }
        int no;
        cin >> no;
        for (int j = 0; j < no; ++j)
        {
            string type; // 资源种类
            cin >> type;
            if (type == "*")
                r[i].src_kind_all = true;
            r[i].src_kind[type] = 1;
        }
        int nn;
        cin >> nn;
        for (int j = 0; j < nn; ++j)
        {
            string name; // 资源名字
            cin >> name;
            r[i].src_name[name] = 1;
        }
    }
    // 输入m个角色关联
    for (int i = 0; i < m; ++i)
    {
        int ns;
        cin >> con[i].name >> ns;
        for (int j = 0; j < ns; ++j)
        {
            string type, name;
            cin >> type >> name;
            if (type == "u")
            {
                con[i].user.push_back(name);
                if (name_to_roler.count(con[i].name)) // 如果有这个角色才加入
                    user_to_roler[name].insert(name_to_roler[con[i].name]);
            }
            if (type == "g")
            {
                con[i].group.push_back(name);
                if (name_to_roler.count(con[i].name)) // 如果有这个角色才加入
                    group_to_roler[name].insert(name_to_roler[con[i].name]);
            }
        }
    }

    // 输入q个待授权的操作
    for (int i = 0; i < q; ++i)
    {
        string name;
        int ng;
        cin >> name >> ng;
        un[i].user_name = name;
        for (int j = 0; j < ng; ++j)
        {
            string groupname;
            cin >> groupname;
            un[i].group.push_back(groupname);
        }
        string opera;
        string srckind, srcname;
        cin >> opera;
        cin >> srckind >> srcname;
        un[i].operat = opera;
        un[i].src_kind = srckind;
        un[i].src_name = srcname;
    }

    for (int i = 0; i < q; ++i)
    {
        bool flag = false;
        unordered_set<int> all_roler; // 防止重复判断
        unordered_set<int> temp1 = user_to_roler[un[i].user_name];
        all_roler.insert(temp1.begin(), temp1.end());
        for (int j = 0; j < un[i].group.size(); ++j)
        {
            unordered_set<int> temp = group_to_roler[un[i].group[j]];
            all_roler.insert(temp.begin(), temp.end());
        }
        if (check_all(un[i], all_roler))
        {
            flag = true;
        }

        if (flag)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}