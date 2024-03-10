#include <bits/stdc++.h>
using namespace std;
int m;
int move_step[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
struct line // 表明这是一个y=x+b的直线
{
    int x1, y1; // 起始坐标
    int x2, y2; // 重点坐标
    int k;      // 斜率
    int b;      // y=kx+b
    double a;   // 反射率
};
struct light
{
    int x, y, d;
    double I;
    int t;
};
int num_line;
unordered_map<int, struct line> lines;
vector<int> delete_lines;
int getLength(struct light t, struct line l, int type /*横向的是1 纵向的是0*/)
{
    // 如果是横向的
    if (type == 1)
    {
        int x_temp = (t.y - l.b) / l.k;
        return abs(t.x - x_temp);
    }
    // 如果是纵向的
    if (type == 0)
    {
        int y_temp = t.x * l.k + l.b;
        return abs(t.y - y_temp);
    }
}
bool checkToLine(struct line l, struct light t)
{
    if (l.k == 1)
    {
        if ((t.d == 1 || t.d == 2) && (t.y - l.k * t.x) < l.b)
            return true;
        else if ((t.d == 0 || t.d == 3) && (t.y - l.k * t.x) > l.b)
            return true;
    }
    else if (l.k == -1)
    {
        if ((t.d == 0 || t.d == 1) && (t.y - l.k * t.x) < l.b)
            return true;
        else if ((t.d == 2 || t.d == 3) && (t.y - l.k * t.x) > l.b)
            return true;
    }
    return false;
}
void solve(struct light t)
{
    // 寻找下一个将要接触的曲线，并且算出下一个接触的点
    while (t.t > 0)
    {
        int min_length = 1e9;
        int min_k = -1;
        for (auto item : lines)
        {
            if ((t.d == 0 || t.d == 2) && (t.y < max(item.second.y1, item.second.y2) && t.y > min(item.second.y1, item.second.y2)) && checkToLine(item.second, t))
            {
                int length = getLength(t, item.second, 1);
                if (min_k == -1 || length < min_length)
                {
                    min_k = item.first;
                    min_length = length;
                }
            }
            if ((t.d == 1 || t.d == 3) && (t.x < max(item.second.x1, item.second.x2) && t.x > min(item.second.x1, item.second.x2)) && checkToLine(item.second, t))
            {
                int length = getLength(t, item.second, 0);
                if (min_k == -1 || length < min_length)
                {
                    min_k = item.first;
                    min_length = length;
                }
            }
        }

        if (min_k == -1) // 如果不再有镜子挡在前面
        {
            t.x += t.t * move_step[t.d][0];
            t.y += t.t * move_step[t.d][1];
            t.t = 0;
            break;
        }
        // 如果时间t到不了镜子前
        else if (min_length >= t.t)
        {
            t.x += t.t * move_step[t.d][0];
            t.y += t.t * move_step[t.d][1];
            t.t = 0;
            break;
        }
        else // 如果可以到镜子上
        {
            struct line l = lines[min_k];
            if (t.d == 0 || t.d == 2)
            {
                t.t -= min_length;
                t.x = (t.y - l.b) / l.k;
                if (t.d == 0)
                    t.d = l.k > 0 ? 1 : 3;
                else if (t.d == 2)
                    t.d = l.k > 0 ? 3 : 1;
            }
            else if (t.d == 1 || t.d == 3)
            {
                t.t -= min_length;
                t.y = t.x * l.k + l.b;
                if (t.d == 1)
                    t.d = l.k > 0 ? 0 : 2;
                else if (t.d == 3)
                    t.d = l.k > 0 ? 2 : 0;
            }
            t.I = t.I * l.a;
        }
        if (t.I < 1)
        {
            cout << "0 0 0" << endl;
            return;
        }
    }
    cout << t.x << ' ' << t.y << ' ' << (int)t.I << endl;
}
int main()
{
    // freopen("1.txt", "r", stdin);
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            struct line temp;
            cin >> temp.x1 >> temp.y1 >> temp.x2 >> temp.y2 >> temp.a;
            if ((temp.x1 < temp.x2 && temp.y1 < temp.y2) || (temp.x1 > temp.x2 && temp.y1 > temp.y2))
                temp.k = 1;
            else
                temp.k = -1;
            temp.b = temp.y1 - temp.k * temp.x1;
            lines[i] = temp;
        }
        else if (type == 2)
        {
            int k;
            cin >> k;
            lines.erase(k);
        }
        else if (type == 3)
        {
            struct light temp;
            cin >> temp.x >> temp.y >> temp.d >> temp.I >> temp.t;
            solve(temp);
        }
    }

    return 0;
}