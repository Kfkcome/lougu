#include <bits/stdc++.h>
using namespace std;
int n, q;
struct betw
{
    int id;
    vector<int> l; // 一个int保存16位ip //从高位开始保存
    vector<int> r;
};

const bool compareIP(vector<int> a, vector<int> b)
{
    int i = 0;
    for (i = 0; i < min(a.size(), b.size()); i++)
    {
        if (a[i] > b[i])
        {
            return 1;
        }
        else if (a[i] < b[i])
        {
            return 0;
        }
    }
    if (a.size() == b.size())
        return 2; // 两个相等
    else if (a.size() > b.size())
        return 1; // a大于b
    else if (a.size() < b.size())
        return 0; // a小于b
}
// 用来判断a在b的什么位置
// 1左边  2 左边有交集 3中间  4右边有交集  5 右边  6两个区间相等
int compareRange(struct betw a, struct betw b)
{
    if (compareIP(a.r, b.l) == 0)
    {
        return 1;
    }
    else if (compareIP(a.r, b.l) == 2 || ((compareIP(a.r, b.l) == 1 || compareIP(a.r, b.l) == 2) && compareIP(a.l, b.l) == 0 && compareIP(a.r, b.r) == 0))
    {
        return 2;
    }
    else if (compareIP(a.r, b.r) == 0 && compareIP(a.l, b.l) == 1)
    {
        return 3;
    }
    else if (compareIP(a.r, b.r) == 2 || (compareIP(a.r, b.r) == 1 && (compareIP(a.l, b.l) == 1 || compareIP(a.l, b.l) == 2) && compareIP(a.l, b.r) == 0))
    {
        return 4;
    }
    else if (compareIP(a.l, b.r) == 1)
    {
        return 5;
    }
    else if (compareIP(a.l, b.l) == 2 && compareIP(a.r, b.r) == 2)
        return 6;
}
vector<struct betw> user;
int top;
int hexToDec(string a)
{
    int result = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] >= '0' && a[i] <= '9')
        {
            result += a[i] - '0';
        }
        else if (a[i] >= 'a' && a[i] <= 'f')
        {
            result += a[i] - 'a' + 10;
        }
        result *= 16;
    }
    return result;
}
struct betw convertString(string l, string r, int id)
{
    int lastpos = -1; // 记录上一个冒号的位置
    struct betw res;
    int top = 0; // 记录当前的位数
    for (int i = 0; i < l.size(); i++)
    {
        if (l[i] == ':')
        {
            res.l.push_back(hexToDec(string(l.begin() + lastpos + 1, l.begin() + 1)));
        }
    }
    for (int i = 0; i < r.size(); i++)
    {
        if (r[i] == ':')
        {
            res.r.push_back(hexToDec(string(r.begin() + lastpos + 1, r.begin() + 1)));
        }
    }
    res.id = id;
    return res;
}
bool check(struct betw t) // 检查是否可以占用
{
    bool flag = true;
    int insertTo = -1;
    // 怎么保证区间之间有交集
    for (int i = 0; i <= user.size(); i++) // 循环遍历每一个范围查看是不是有冲突
    {
        int kind = compareRange(t, user[i]);

        if (user[i].id == t.id) // 如果是同一个用户 只要不是全部分配了就可以分配
        {
            if (kind == 6) // 如果已经全部被分配了
            {
                flag = false;
            }
            else if (kind >= 2 && kind <= 5)
            {
                insertTo = i;
            }
        }
        else
        {
            if (kind != 1 || kind != 5)
            {
                flag = false;
            }
        }
    }
    if (!flag)
        return false;
    compareRange(t, user[insertTo]);
}
int main()
{
    int type;
    cin >> n >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> type;
        if (type == 1)
        {
            int id;
            string l, r;
            cin >> id >> l >> r;
            struct betw t = convertString(l, r, id);
            if (check(t))
            {
            }
            else
            {
            }
        }
        else if (type == 2)
        {
        }
        else if (type == 3)
        {
        }
    }
    return 0;
}
