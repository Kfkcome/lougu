#include <bits/stdc++.h>
using namespace std;
int n, q;
struct ip
{
    int id;
    int num[32]; // 低位在前 高位在后
};
const bool operator<(struct ip a, struct ip b) // 重载小于号以遍排序和二分搜索 按从小到大排序
{
    for (int i = 31; i >= 0; i++)
    {
        if (a.num[i] > b.num[i])
        {
            return false;
        }
        else if (a.num[i] < b.num[i])
        {
            return true;
        }
    }
    return true; // 如果两个是等于也按小于算
}
set<ip> addr; // 所以被分配后的地址的集合
// 如果前一个ip 的id与后一个ip 的id 相等那么则说明这个区间是属于这个id的
// 反之则这个区间不属于任何一个id的
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
struct ip convertString(string temp)
{
    int lastpos = -1; // 记录上一个冒号的位置
    struct ip res;
    int top = 0; // 记录当前的位数
    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i] == ':')
        {
            res.num[top++] = hexToDec(string(temp.begin() + lastpos + 1, temp.begin() + 1));
        }
    }
    return res;
}
bool checkIp(struct ip t1, struct ip t2)
{
    set<ip>::iterator r1 = addr.upper_bound(t1); // 第一个大于他的
    set<ip>::iterator l1 = addr.lower_bound(t1); // 第一个大于等于他的
    l1--;                                        // 第一个小于他的
    set<ip>::iterator r2 = addr.upper_bound(t2); // 第一个大于他的
    set<ip>::iterator l2 = addr.lower_bound(t2); // 第一个大于等于他的
    l2--;

    // 如果全部没有被分配
    if (r1->id != l1->id && r2->id != l2->id)
    {
        return true;
    }
    // 如果一部分分配给了本人

    // 如果全部分配给了本人
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
            string l, r;
            int id;
            cin >> id >> l >> r;
            struct ip t1 = convertString(l);
            t1.id = id;
            struct ip t2 = convertString(r);
            t2.id = id;
            // 检查是不是有冲突应该
            addr.insert(t1);
            addr.insert(t2);
        }
        else if (temp == 2)
        {
        }
        else if (temp == 3)
        {
        }
    }
    return 0;
}