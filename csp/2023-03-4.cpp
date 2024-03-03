#include <bits/stdc++.h>
using namespace std;
int n, q;
struct range
{
    unsigned long long l, r;
    int id;
} user[20001];
int top;
unsigned long long hexToDec(string a) // 十六进制字符串转整形
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
unsigned long long convertString(string t)
{
    int last = 0;
    int result = 0;
    for (int i = 0; i < n / 16; i++)
    {
        result *= 65536;
        result += hexToDec(string(t.begin() + i * 5, t.begin() + i * 5 + 4));
    }
    return result;
}
bool allocate(struct range t)
{
    struct range temp = t;
    for (int i = 0; i < top; i++)
    {
        if (user[i].id == t.id)
        {
            // 如果两个有交集
            if (!(user[i].l > t.r) && !(user[i].r < t.l))
            {
                if (t.l >= user[i].l && t.r <= user[i].r) // 如果全部已经被分配了
                {
                    return 0;
                }
                else
                {
                    // 减去他们交集的地方
                    if (t.l >= user[i].l && t.l <= user[i].r)
                    {
                        t.l = user[i].r + 1;
                    }
                    if (t.r >= user[i].l && t.r <= user[i].r)
                    {
                        t.r = user[i].l - 1;
                    }
                }
            }
        }
        else
        {
            // 如果两个有交集
            if (!(user[i].l > t.r) && !(user[i].r < t.l))
            {
                return 0;
            }
        }
    }
    // 如果循环下来整个已经被减去
    // 那么久无法插入，说明全部被都被占用了。
    if (t.r < t.l)
    {
        return 0;
    }
    else
    {
        user[top++] = temp;
        return 1;
    }
}
int searchIp(long long ip) // 如果没有找到则返回0
{
    for (int i = 0; i < top; i++)
    {
        if (user[i].l <= ip && user[i].r >= ip)
        {
            return user[i].id;
        }
    }
    return 0;
}
int searchAll(struct range t)
{
    t.id = -1;
    for (int i = 0; i < top; i++)
    {
        // 如果两个有交集
        if (!(user[i].l > t.r) && !(user[i].r < t.l))
        {
            if (t.id != user[i].id && t.id != -1)
            {
                return 0;
            }
            else
            {
                t.id = user[i].id;
                // 减去他们交集的地方
                if (t.l >= user[i].l && t.l <= user[i].r)
                {
                    t.l = user[i].r + 1;
                }
                if (t.r >= user[i].l && t.r <= user[i].r)
                {
                    t.r = user[i].l - 1;
                }
            }
        }
    }
    if (t.l > t.r)
        return t.id;
    else
        return 0;
}
int main()
{
    cin >> n >> q;
    for (int i = 0; i < q; i++)
    {
        int temp;
        cin >> temp;
        if (temp == 1)
        {
            struct range u;
            string l, r;
            cin >> u.id >> l >> r;
            u.l = convertString(l);
            u.r = convertString(r);
            if (allocate(u))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else if (temp == 2)
        {
            unsigned long long s; // 注意要字符串转换
            string ss;
            cin >> ss;
            s = convertString(ss);
            cout << searchIp(s) << endl;
        }
        else if (temp == 3)
        {
            string l, r;
            cin >> l >> r;
            struct range u;
            u.l = convertString(l);
            u.r = convertString(r);
            cout << searchAll(u) << endl;
        }
    }
    return 0;
}
