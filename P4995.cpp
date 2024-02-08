#include <bits/stdc++.h>
using namespace std;
int n, h[301];
long sum;
bool used[301];
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    sort(h, h + n, cmp);
    int last = 0;
    used[0] = true;
    sum += h[0] * h[0];
    for (int j = 0; j < n; j++)
    {
        int maxdiffindex = -1;
        for (int i = 0; i < n; i++)
        {
            if (!used[i] && (maxdiffindex == -1 || abs(h[last] - h[i]) > abs(h[last] - h[maxdiffindex])))
            {
                maxdiffindex = i;
            }
        }
        if (maxdiffindex == -1)
        {
            break;
        }
        used[maxdiffindex] = true;
        sum += (h[last] - h[maxdiffindex]) * (h[last] - h[maxdiffindex]);
        last = maxdiffindex;
    }
    cout << sum << endl;
    return 0;
}
