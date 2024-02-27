#include <bits/stdc++.h>
using namespace std;
int n, a, b, sum;
bool checkin(int x, int y)
{
    if (x <= a && y <= b)
        return true;
    return false;
}
int main()
{
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2, m = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        int xlen = min(x2, a) - max(x1, 0);
        int ylen = min(y2, b) - max(0, y1);
        if (xlen > 0 && ylen > 0)
        {
            sum += xlen * ylen;
        }
    }
    cout << sum;
    return 0;
}