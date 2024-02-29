#include <bits/stdc++.h>
using namespace std;
int n, m;
struct dn
{
    int dn;
    unordered_map<int, int> value;
};
unordered_map<int, unordered_map<int, unordered_set<int>>> artt; // 第一个int 是属性  第二个int是属性值 第三个int是对应user的dn
unordered_map<int, unordered_set<int>> args;
struct dn user[2501];
void solveBase(unordered_set<int> &t, string temp)
{
    // 寻找操作operator,并且分解出属性和值
    int id, val, op; // 如果op是1 则符号是：如果op是0 则符号是~
    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i] == ':' || temp[i] == '~')
        {
            if (temp[i] == ':')
                op = 1;
            else
                op = 0;
            id = stoi(string(temp.begin(), temp.begin() + i));
            val = stoi(string(temp.begin() + i + 1, temp.end()));
            break;
        }
    }
    if (op)
    {
        t.insert(artt[id][val].begin(), artt[id][val].end());
    }
    else
    {
        t.insert(args[id].begin(), args[id].end()); // 先把所有有这个属性的dn加入
        for (auto item : artt[id][val])
            t.erase(item); // 然后清楚和这个值相等的dn
    }
}
void solveExpr(unordered_set<int> &t, string temp)
{
    int logic; // 如果是 &与 则为0  如果是 |或 则为1
    if (temp[0] == '&')
        logic = 0;
    else if (temp[0] == '|')
        logic = 1;
    else // 如果不是easy式子 则是原子式
    {
        solveBase(t, temp);
        return;
    }
    int position[4]; // 记录四个括号符号的位置
    position[0] = 1;
    int pos = 0;
    // 匹配括号的位置
    for (int i = 2; i < temp.size(); i++)
    {
        if (temp[i] == '(')
        {
            pos++;
        }
        if (temp[i] == ')')
        {
            if (pos != 0)
            {
                pos--;
            }
            else
            {
                position[1] = i;
                position[2] = i + 1;
                position[3] = temp.size() - 1;
                break;
            }
        }
    }
    unordered_set<int> t1;
    solveExpr(t1, string(temp.begin() + position[0] + 1, temp.begin() + position[1]));
    unordered_set<int> t2;
    solveExpr(t2, string(temp.begin() + position[2] + 1, temp.begin() + position[3]));
    if (logic == 0)
    {
        for (auto item : t2)
        {
            if (t1.find(item)!=t1.end())
                t.insert(item);
        }
    }
    if (logic == 1)
    {
        t.insert(t1.begin(), t1.end());
        t.insert(t2.begin(), t2.end());
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> user[i].dn;
        int num;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            int id, val;
            cin >> id >> val;
            user[i].value[id] = val;
            args[id].insert(user[i].dn);
            artt[id][val].insert(user[i].dn);
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        unordered_set<int> ans;
        string temp;
        cin >> temp;
        solveExpr(ans, temp);
        vector<int> ans1(ans.begin(), ans.end());
        sort(ans1.begin(), ans1.end());
        for (auto item : ans1)
            cout << item << ' ';
        cout << endl;
    }
    return 0;
}