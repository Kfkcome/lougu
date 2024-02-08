#include <bits/stdc++.h>
using namespace std;
int w, n;
int p[30001];
bool cmp(int a, int b)
{
    return a < b;
}
int main()
{
    int temp = 0;
    cin >> w >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    sort(p, p + n);
    int l = 0, r = n - 1;
    while (l <= r)
    {
        if (p[l] + p[r] <= w)
        {
            l++;
            r--;
            temp++;
        }
        else
        {
            r--;
            temp++;
        }
    }
    cout << temp;
    return 0;
}
