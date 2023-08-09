#include <bits/stdc++.h>
using namespace std;
double a, b, c, d;
int check(double x)
{
    double f = a * x * x * x + b * x * x + c * x + d;
    if (f > 0)
        return 1;
    else if (f < 0)
        return -1;
    return 0;
}
int main()
{
    cin >> a >> b >> c >> d;
    for (int i = -100; i < 100; i++)
    {
        int x1 = check(i); // 符号判断变量
        int x2 = check(i + 1);
        if (x1 == 0)
        {
            printf("%.2lf ", (double)i);
            continue;
        }
        if (x1 * x2 < 0)
        {
            double l = i;
            double r = i + 1;
            while ((r - l) >= 0.001)
            {
                double mid = (l + r) / 2;
                int midSbol = check(mid);
                if (midSbol * x1 < 0)
                {
                    r = mid;
                    x2 = midSbol;
                }
                else
                {
                    l = mid;
                    x1 = midSbol;
                }
            }
            printf("%.2lf ", r);
        }
    }
    return 0;
}