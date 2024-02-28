#include <bits/stdc++.h>
using namespace std;
int n, m;
struct dn
{
    int dn;
    map<int, int> value;
};
struct dn user[2501];
void solveBase(vector<int> &t, string temp)
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
    for (int i = 0; i < n; i++)
    {
        if (op && user[i].value.find(id) != user[i].value.end() && user[i].value[id] == val)
        {
            t.push_back(i);
        }
        else if (!op && user[i].value.find(id) != user[i].value.end() && user[i].value[id] != val)
        {
            t.push_back(i);
        }
    }
}
void solveEasy(vector<int> &t, string temp)
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
    int top = 0;
    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i] == '(' || temp[i] == ')')
        {
            position[top++] = i;
        }
    }
    vector<int> t1;
    solveBase(t1, string(temp.begin() + position[0] + 1, temp.begin() + position[1]));
    vector<int> t2;
    solveBase(t2, string(temp.begin() + position[2] + 1, temp.begin() + position[3]));
    if (logic == 0)
    {
        for (auto item : t1)
        {
            for (auto item2 : t2)
            {
                if (item == item2)
                {
                    t.push_back(item);
                    break;
                }
            }
        }
    }
    if (logic == 1)
    {
        t.insert(t.end(), t1.begin(), t1.end());
        t.insert(t.end(), t2.begin(), t2.end());
    }
}
void solveExpr()
{
    
}
int main()
{
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
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        vector<int> ans;
        string temp;
        cin >> temp;
        solveEasy(ans, temp);
        for (auto item : ans)
        {
            cout << user[item].dn << ' ';
        }
        cout << endl;
    }
    return 0;
}