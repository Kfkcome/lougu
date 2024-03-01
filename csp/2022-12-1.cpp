#include <bits/stdc++.h>
using namespace std;
int n;
double p, sum;
int main()
{
    scanf("%d%lf", &n, &p);
    double temp = p + 1;
    p = 1;
    for (int i = 0; i <= n; i++)
    {
        int in;
        scanf("%d", &in);
        sum += in * p;
        p = p / temp;
    }
    printf("%f", sum);
}