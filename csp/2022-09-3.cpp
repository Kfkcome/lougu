#include <bits/stdc++.h>
using namespace std;
int n;
struct dayget
{
    int u;
    int day; // 到达的一天
};
struct places
{
    int id;     // 地方的id
    int day;    // 风险的开始日期
    int length; // 风险的长度
};
unordered_map<int, unordered_map<int, vector<dayget>>> arrive; // arrive[i][j]第i天收到j地到的用户的集合
unordered_map<int, vector<places>> place_time;                 // place_time[i] id为i的地方的风险时间片段的集合
unordered_map<int, vector<places>> place_time2;                // place_time[i] id为i的地方的风险时间片段的集合
unordered_set<int> risks[1010];                                // 存储每天的风险用户
bool searchIsDanger(int d1, int d, vector<places> dage)
{
    for (int i = 0; i < dage.size(); i++)
    {
        if (dage[i].day <= d1 && dage[i].day + dage[i].length - 1 >= d)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    // freopen("1.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int r, m;
        cin >> r >> m;
        for (int j = 0; j < r; j++)
        {
            int p;
            cin >> p;
            struct places t = {p, i, 7};
            place_time[p].push_back(t);
        }
        for (int j = 0; j < m; j++)
        {
            int d, u, r1;
            cin >> d >> u >> r1;
            struct dayget t = {u, d};
            if (d < i - 6) // 如果收到收到消息的是7天之前的就不要了
                continue;
            arrive[i][r1].push_back(t);
        }
    }
    // 合并一下区间
    for (auto item : place_time)
    {
        struct places temp;
        temp.length = -1; // 标记为还没初始化
        for (auto p : item.second)
        {
            if (temp.length != -1 && p.day >= temp.day && p.day <= temp.day + temp.length)
            {
                int end1 = p.day + p.length - 1;
                int end2 = temp.day + temp.length - 1;
                temp.length += end1 - end2;
            }
            else
            {
                if (temp.length != -1)
                    place_time2[item.first].push_back(temp);
                temp = p;
            }
        }
        if (temp.length != -1)
            place_time2[item.first].push_back(temp);
    }

    for (int d = 0; d < n; d++)
    {
        for (int i = max(0, d - 6); i <= d; i++)
        {
            for (auto c : arrive[i]) // 分析第i天到访的所有地方
            {
                int r = c.first;
                for (auto user : c.second) // 到访r地的所有的人 然后判断是不是该设定为风险人员
                {
                    int d1 = user.day;
                    if (d1 >= d - 6 && searchIsDanger(d1, d, place_time2[r]))
                    {
                        risks[d].insert(user.u);
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << ' ';
        vector<int> risk1(risks[i].begin(), risks[i].end());
        sort(risk1.begin(), risk1.end());
        for (auto item : risk1)
        {
            cout << item << ' ';
        }
        cout << endl;
    }
}