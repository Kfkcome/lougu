#include <bits/stdc++.h>
using namespace std;
int n;
struct cheese
{
    int x, y;
};
double path[16][16];
struct cheese c[16];
int main()
{
    for (int i = 0; i < n; i++)
    {
        cin >> c[i].x >> c[i].y;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            double x1=c[i].x,x2=c[j].x;
            double y1=c[i].y,y2=c[j].y;
            path[i][j]=sqrt()
        }
    }
    return 0;
}