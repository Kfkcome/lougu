#include <bits/stdc++.h>
using namespace std;
long m, n, sum,uni;
int s[100000], t[100000];
int binSearch(int x)
{
    int l = 0, r = uni-1;
    while (l < r)
    {
        int mid = (r + l) / 2;
        if (x - t[mid] <= 0)
        {
            r = mid;
        }
        else
            l = mid + 1;
    }
    return l;
}
int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        cin >> t[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    sort(t, t + m);
    uni=unique(t,t+m)-t;
    for (int i = 0; i < n; i++)
    {
        int temp = binSearch(s[i]);

        int split1 = abs(s[i] - t[temp]);

        int split2 = abs(temp - 1 >= 0 ? s[i] - t[temp - 1] : 1 << 30);
        sum += min(split1, split2);
    }
    cout << sum;
    return 0;
}