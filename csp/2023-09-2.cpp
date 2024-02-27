#include <bits/stdc++.h>
using namespace std;
int n, m;
double op1[100001];
double op2[100001];
struct inputdata
{
    int i, j, x, y;
};
struct inputdata indata[100001];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int type;
        double k;
        cin >> type >> k;
        if (type == 1)
        {
            op1[i] = k;
        }
        else
            op2[i] = k;
    }
    op1[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (op1[i] == 0)
        {
            op1[i] = op1[i - 1];
        }
        else 
            op1[i] = op1[i - 1] * op1[i];
        if (op2[i] == 0)
        {
            op2[i] = op2[i - 1];
        }
        else
            op2[i] += op2[i - 1];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> indata[i].i >> indata[i].j >> indata[i].x >> indata[i].y;
    }
    for (int i = 1; i <= m; i++)
    {
        int l = indata[i].i, r = indata[i].j;
        double x = indata[i].x, y = indata[i].y;
        double angle = op2[r] - op2[l - 1];
        double b = op1[r] / op1[l - 1];
        double temp = x;
        x = x * cos(angle) - y * sin(angle);
        y = temp * sin(angle) + y * cos(angle);
        x = x * b;
        y = y * b;
        printf("%f %f\n", x, y);
    }
    return 0;
}