#include <bits/stdc++.h>
using namespace std;
struct ip
{
    int time_out = 0;
    int state = 0;
    string u = "";
};
struct dchp
{
    int N, Tdef, Tmax, Tmin;
    string H;
    struct ip pool[10010];
} d;
struct message
{
    string sender, reciver, type;
    int ip;
    int t;
    int time_out;
};
void update(int t)
{
    for (int i = 1; i < d.N; i++)
    {
        if (d.pool[i].time_out && d.pool[i].time_out <= t)
        {
            if (d.pool[i].state == 1)
            {
                d.pool[i].state = 0;
                d.pool[i].u.clear();
                d.pool[i].time_out = 0;
            }
            if (d.pool[i].state == 2)
            {
                d.pool[i].state = 3;
                d.pool[i].time_out = 0;
            }
        }
    }
}
bool check_reciver(struct message m)
{
    if (!(m.reciver == d.H || m.reciver == "*"))
    {
        if (m.type != "REQ")
        {
            return false;
        }
    }
    if (!(m.type == "DIS" || m.type == "REQ"))
    {
        return false;
    }
    if ((m.reciver == "*" && m.type != "DIS") || (m.reciver == d.H && m.type == "DIS"))
        return false;
    return true;
}
int get_ip_by_user(string name)
{
    for (int i = 1; i <= d.N; i++)
        if (d.pool[i].u == name)
            return i;
    return 0;
}
int get_ip_by_state(int state)
{
    for (int i = 1; i <= d.N; i++)
        if (d.pool[i].state == state)
            return i;
    return 0;
}
void deal_discover(struct message m)
{
    int addr = get_ip_by_user(m.sender);
    if (!addr)
        addr = get_ip_by_state(0);
    if (!addr)
        addr = get_ip_by_state(3);
    if (!addr)
        return;
    d.pool[addr].state = 1;
    d.pool[addr].u = m.sender;
    if (!m.time_out)
        d.pool[addr].time_out = m.t + d.Tdef;
    else
    {
        int time_out = min(m.time_out - m.t, d.Tmax);
        time_out = max(time_out, d.Tmin);
        d.pool[addr].time_out = m.t + time_out;
    }
    cout << d.H << ' ' << m.sender << ' ' << "OFR" << ' ' << addr << ' ' << d.pool[addr].time_out << endl;
}
void deal_request(struct message m)
{
    if (m.reciver != d.H)
    {
        for (int i = 1; i <= d.N; i++)
            if (d.pool[i].state == 1 && d.pool[i].u == m.sender)
            {
                d.pool[i].state = 0;
                d.pool[i].u.clear();
                d.pool[i].time_out = 0;
            }
        return;
    }
    if (!(m.ip > 0 && m.ip <= d.N && d.pool[m.ip].u == m.sender))
    {
        cout << d.H << ' ' << m.sender << ' ' << "NAK" << ' ' << m.ip << ' ' << 0 << endl;
        return;
    }
    d.pool[m.ip].state = 2;
    d.pool[m.ip].u = m.sender;
    if (!m.time_out)
        d.pool[m.ip].time_out = m.t + d.Tdef;
    else
    {
        int time_out = min(m.time_out - m.t, d.Tmax);
        time_out = max(time_out, d.Tmin);
        d.pool[m.ip].time_out = m.t + time_out;
    }
    cout << d.H << ' ' << m.sender << ' ' << "ACK" << ' ' << m.ip << ' ' << d.pool[m.ip].time_out << endl;
}
int main()
{
    // freopen("1.txt", "r", stdin);
    cin >> d.N >> d.Tdef >> d.Tmax >> d.Tmin >> d.H;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        struct message m;
        cin >> m.t >> m.sender >> m.reciver >> m.type >> m.ip >> m.time_out;
        update(m.t);
        if (!check_reciver(m))
            continue;
        if (m.type == "DIS")
            deal_discover(m);
        else if (m.type == "REQ")
            deal_request(m);
    }
    return 0;
}
