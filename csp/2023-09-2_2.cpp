#include <bits/stdc++.h>
using namespace std;
int n, m;
struct myop
{
    bool a;
    int end;
    double op1;
    double op2;
};
struct myop op[100001];
int main()
{
    int type;
    bool change = false;
    double tempm, k;
    cin >> n >> m;
    op[0] = {true, 0, 1, 0};
    for (int i = 1; i <= n; i++)
    {
        cin >> type;
        if (type == 2)
        {
            op[i].a = true;
            cin >> tempm;
            op[i].op2 = tempm;
            if (i != 1 && op[i - 1].a)
            {
                op[i].op2 += op[i - 1].op2;
            }
        }
        else
        {
            op[i].a = false;
            cin >> k;
            op[i].op1 = k;
            if (i != 1 && !op[i - 1].a)
            {
                op[i].op1 *= op[i - 1].op1;
            }
        }
    }
    op[n].end = n;
    for (int i = n - 1; i >= 1; i--)
    {
        if (op[i].a == op[i + 1].a)
        {
            op[i].end = op[i + 1].end;
        }
        else
        {
            op[i].end = i;
        }
    }
    int l, r;
    double x, y;
    double tempop1, tempop2;
    for (int i = 1; i <= m; i++)
    {

        cin >> l >> r >> x >> y;
        tempop1 = 1;
        tempop2 = 0;
        for (int j = l; j <= r; j++)
        {
            if (!op[j].a)
            {
                if (!op[j - 1].a)
                {
                    if (op[j].end <= r)
                    {
                        tempop1 *= (op[op[j].end].op1 / op[j - 1].op1);
                    }
                    else
                    {
                        tempop1 *= (op[r].op1 / op[j - 1].op1);
                        break;
                    }
                }
                else if (op[j - 1].a)
                {
                    if (op[j].end <= r)
                    {
                        tempop1 *= (op[op[j].end].op1);
                    }
                    else
                    {
                        tempop1 *= (op[r].op1);
                        break;
                    }
                }
            }
            else if (op[j].a)
            {
                if (op[j - 1].a)
                {
                    if (op[j].end <= r)
                        tempop2 += (op[op[j].end].op2 - op[j - 1].op2);
                    else
                    {
                        tempop2 += (op[r].op2 - op[j - 1].op2);
                        break;
                    }
                }
                else if (!op[j - 1].a)
                {
                    if (op[j].end <= r)
                        tempop2 += (op[op[j].end].op2);
                    else
                    {
                        tempop2 += (op[r].op2);
                        break;
                    }
                }
            }
            j = op[j].end;
        }

        double tempx = x;
        x = x * cos(tempop2) - y * sin(tempop2);
        y = tempx * sin(tempop2) + y * cos(tempop2);
        x = x * tempop1;
        y = y * tempop1;
        printf("%f %f\n", x, y);
    }

    return 0;
}