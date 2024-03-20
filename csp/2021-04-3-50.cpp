#include <bits/stdc++.h>
using namespace std;
struct ip
{
    int state = 0; // 状态 0未分配 1待分配 2占用 3过期
    // int addr;      // 地址
    string user; // 占用者
    long long timeout = 0;
};
struct DHCP
{
    long long N, Tdef, Tmax, Tmin;
    struct ip pool[10010];
    unordered_map<string, int> user_to_ip;
    string H;
} d;
map<string, int> string_to_type;
struct message
{
    long long t;
    string sender;
    string receiver;
    int type; // 0 DIS 1 OFR 2 REQ 3 ACK 4 NAK
    int ip;
    long long time_out; // 过期时刻
};
bool checkRecieve(struct message m)
{
    if (m.receiver != d.H && m.receiver != "*")
    {
        if (m.type != 3)
        {
            return false;
        }
    }
    if (m.type != 1 && m.type != 3)
    {
        return false;
    }
    if ((m.receiver == "*" && m.type != 1) || (m.receiver == d.H && m.type == 1))
    {
        return false;
    }
    return true;
}
void update(int t)
{
    for (int i = 1; i <= d.N; i++)
    {
        if (d.pool[i].state == 1 && d.pool[i].timeout <= t && d.pool[i].timeout)
        {
            d.pool[i].state = 0;
            d.user_to_ip.erase(d.pool[i].user);
            d.pool[i].timeout = 0;
            d.pool[i].user.clear();
        }
        if (d.pool[i].state == 2 && d.pool[i].timeout <= t && d.pool[i].timeout)
        {
            d.pool[i].state = 3;
            d.pool[i].timeout = 0;
        }
    }
}
// int get_ip_by_user(string name)
// {
//     for (int i = 1; i < d.N; i++)
//         if (d.pool[i].user == name)
//             return i;
//     return 0;
// }
void deal_dis(struct message m)
{
    int ip_addr = -1;
    if (d.user_to_ip.count(m.sender) && d.pool[d.user_to_ip[m.sender]].user == m.sender)
    // if (int temp = get_ip_by_user(m.sender))
    {
        // ip_addr = temp;
        ip_addr=d.user_to_ip[m.sender];
    }
    else
    {
        for (int i = 1; i <= d.N; i++)
        {
            if (d.pool[i].state == 0)
            {
                ip_addr = i;
                break;
            }
        }
        if (ip_addr == -1) // 如果没有找到未分配的ip地址
        {
            for (int i = 1; i <= d.N; i++)
            {
                if (d.pool[i].state == 3)
                {
                    ip_addr = i;
                    break;
                }
            }
        }
        if (ip_addr == -1) // 如果连过期的也没有
        {
            return;
        }
    }
    d.pool[ip_addr].state = 1;
    d.user_to_ip.erase(d.pool[ip_addr].user); // 清楚上一个用户的痕迹
    d.pool[ip_addr].user = m.sender;
    d.user_to_ip[m.sender] = ip_addr;
    if (m.time_out == 0) // 如果过期时刻为0
    {
        d.pool[ip_addr].timeout = m.t + d.Tdef;
    }
    else
    {
        long long timeout = max(d.Tmin + m.t, m.time_out);
        timeout = min(d.Tmax + m.t, timeout);
        d.pool[ip_addr].timeout = timeout;
    }
    cout << d.H << ' ' << m.sender << ' ' << "OFR" << ' ' << ip_addr << ' ' << d.pool[ip_addr].timeout << endl;
}
void deal_req(struct message m)
{
    if (m.receiver != d.H)
    {
        int addr = d.user_to_ip[m.sender];
        // int addr = get_ip_by_user(m.sender);
        if (addr != 0 && d.pool[addr].state == 1)
        {
            d.user_to_ip.erase(m.sender);
            d.pool[addr].user.clear();
            d.pool[addr].timeout = 0;
            d.pool[addr].state = 0;
            return;
        }
        // for (int i = 1; i <= d.N; i++)
        // {
        //     if (d.pool[i].user == m.sender && d.pool[i].state == 1)
        //     {
        //         d.pool[i].state = 0;
        //         d.pool[i].user.clear();
        //         d.pool[i].timeout = 0;
        //     }
        // }
        // return;
    }
    if (m.ip <= 0 || m.ip > d.N || d.pool[m.ip].user != m.sender)
    {
        cout << d.H << ' ' << m.sender << ' ' << "NAK" << ' ' << m.ip << ' ' << 0 << endl;
        return;
    }

    d.pool[m.ip].state = 2;
    if (m.time_out == 0)
    {
        d.pool[m.ip].timeout = m.t + d.Tdef;
    }
    else
    {
        long long timeout = max(d.Tmin + m.t, m.time_out);
        timeout = min(d.Tmax + m.t, timeout);
        d.pool[m.ip].timeout = timeout;
    }

    d.user_to_ip.erase(d.pool[m.ip].user);
    d.user_to_ip[m.sender] = m.ip;
    d.pool[m.ip].user = m.sender;

    cout << d.H << ' ' << m.sender << ' ' << "ACK" << ' ' << m.ip << ' ' << d.pool[m.ip].timeout << endl;
}
int main()
{
    // freopen("1.txt", "r", stdin);
    cin >> d.N >> d.Tdef >> d.Tmax >> d.Tmin >> d.H;
    int n;
    cin >> n;
    string_to_type["DIS"] = 1, string_to_type["OFR"] = 2, string_to_type["REQ"] = 3;
    string_to_type["ACK"] = 4, string_to_type["NAK"] = 5;
    for (int i = 0; i < n; i++)
    {
        struct message temp;
        string type;
        cin >> temp.t >> temp.sender >> temp.receiver >> type >> temp.ip >> temp.time_out;
        temp.type = string_to_type[type];
        update(temp.t);
        if (!checkRecieve(temp))
        {
            continue;
        }
        if (temp.type == 1)
        {
            deal_dis(temp);
        }
        if (temp.type == 3)
        {
            deal_req(temp);
        }
    }
    return 0;
}
