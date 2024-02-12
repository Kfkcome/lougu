#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll mod = 1e9 + 7;
int n, m;
vector<ll> num;
struct item // 多项式的项
{
    map<int, int> mp;
    ll coefficient;
    item(ll coefficient, map<int, int> mp) : coefficient(coefficient), mp(mp) {}
};
struct formula
{
    vector<item> items; // 多项式
    formula(vector<item> items) : items(items) {}
};
int charToInt(string c)
{
    ll res = 0;
    ll flag = 1;
    for (int i = 0; i < c.size(); i++)
    {
        if (c[i] == '-')
            flag = -1;
        else
            res = res * 10 + c[i] - '0';
    }
    return res * flag;
}
stack<formula> op;
formula add(formula a, formula b)
{
    for (int i = 0; i < a.items.size(); i++)
    {
        for (int j = 0; j < b.items.size(); j++)
        {
            if (a.items[i].mp == b.items[j].mp)
            {
                a.items[i].coefficient += b.items[j].coefficient;
                b.items.erase(b.items.begin() + j);
                j--;
            }
        }
    }
    for (int i = 0; i < b.items.size(); i++)
    {
        a.items.push_back(b.items[i]);
    }
    return formula(a.items);
}
formula sub(formula a, formula b)
{
    for (int i = 0; i < a.items.size(); i++)
    {
        a.items[i].coefficient *= -1;
    }
    return add(a, b);
}
formula mul(formula a, formula b)
{
    formula res(vector<item>{});
    for (int i = 0; i < a.items.size(); i++)
    {
        for (int j = 0; j < b.items.size(); j++)
        {
            item temp = a.items[i];
            temp.coefficient *= b.items[j].coefficient;
            for (auto it : b.items[j].mp)
            {
                temp.mp[it.first] += it.second;
            }
            res = add(res, formula(vector<item>{temp}));
        }
    }
    return res;
}
formula derivate(formula a, int x)
{
    vector<item> res;
    for (int i = 0; i < a.items.size(); i++)
    {
        if (a.items[i].mp.find(x) != a.items[i].mp.end() && a.items[i].mp[x] != 0)
        {
            item temp = a.items[i];
            temp.coefficient *= temp.mp[x];
            temp.mp[x]--;
            if (temp.mp[x] == 0)
            {
                temp.mp.erase(x);
            }
            res.push_back(temp);
        }
    }
    return formula(res);
}
int getRes(formula a, vector<ll> num)
{
    ll res = 0;
    for (int i = 0; i < a.items.size(); i++)
    {
        ll temp = a.items[i].coefficient;
        for (auto it : a.items[i].mp)
        {
            ll temp2 = 1;
            for (int k = 0; k < it.second; k++)
            {
                temp2 = (temp2 * num[it.first]) % mod;
            }
            temp = (temp * temp2) % mod;
        }
        res = (res + temp) % mod;
    }
    return res;
}
int main()
{
    cin >> n >> m;
    getchar();
    string f;
    getline(cin, f);
    stringstream ss(f);
    string temp;
    while (ss >> temp)
    {
        if (temp.size() == 1 && (temp[0] == '+' || temp[0] == '-' || temp[0] == '*'))
        {
            formula a = op.top();
            op.pop();
            formula b = op.top();
            op.pop();
            if (temp[0] == '+')
            {
                formula c = add(a, b);
                op.push(c);
            }
            else if (temp[0] == '-')
            {
                formula c = sub(a, b);
                op.push(c);
            }
            else if (temp[0] == '*')
            {
                formula c = mul(a, b);
                op.push(c);
            }
        }
        else
        {
            if (temp[0] == 'x')
            {
                int cofficient = temp[1] - '0';
                map<int, int> mp;
                mp[cofficient] = 1;
                item it(1, mp);
                formula f(vector<item>{it});
                op.push(f);
            }
            else
            {
                int cofficient = charToInt(temp);
                map<int, int> mp;
                item it(cofficient, mp);
                formula f(vector<item>{it});
                op.push(f);
            }
        }
    }
    formula full = op.top();

    for (int i = 0; i < m; i++)
    {
        int id;
        cin >> id;
        formula temp = derivate(full, id);
        ll value;
        num.push_back(0);
        for (int j = 1; j <= n; j++)
        {
            cin >> value;
            num.push_back(value);
        }
        ll result = getRes(temp, num) % mod;
        if (result < 0)
        {
            result += mod;
        }
        num.clear();
        cout << result << endl;
    }
}