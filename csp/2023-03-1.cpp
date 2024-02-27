#include <bits/stdc++.h>
using namespace std;
int n, a, b;
bool checkin(int x, int y)
{
    if (x > 0 && y > 0 && x < a && y < b)
    {
        return true;
    }
    return false;
}
int main(int argc, char const *argv[])
{
    cin >> n >> a >> b;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2, x3, y3, x4, y4; // 左下，右上，左上，右下
        cin >> x1 >> y1 >> x2 >> y2;
        x3 = x1;
        y3 = y2;
        x4 = x2;
        y4 = y1;
        if (checkin(x1, y1))
        {
            sum += abs(x1 - min(a, x2)) * abs(y1 - min(b, y2));
        }
        else if (checkin(x2, y2))
        {
            sum += abs(x2 - max(0, x1)) * abs(y2 - max(0, y1));
        }
        else if (checkin(x3, y3))
        {
            sum += abs(x3 - min(a, x4)) * abs(y3 - max(y4, 0));
        }
        else if (checkin(x4, y4))
        {
            sum += abs(x4 - max(x3, 0)) * abs(y4 - min(b, y3));
        }
    }
    cout << sum;
    return 0;
}
