#include <bits/stdc++.h>
using namespace std;
long L, N, M;
long s[50002];
int main()
{
    cin >> L >> N >> M;
    long maxl = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> s[i];
        maxl = max(s[i] - s[i - 1], maxl);
    }
    s[N + 1] = L;
    maxl=max(s[N+1]-s[N],maxl);
    long l = 1, r = maxl;
    while (l < r)
    {
        list<long> ls;
        long mid = (l + r + 1) >> 1;
        int sum = 0;
        for (int i = 0; i <= N + 1; i++)
        {
            ls.push_back(s[i]);
            list<long>::iterator it = ls.end();
            if (ls.size()>1&& *(--it) - *(--it) < mid)
            {
                ls.pop_back();
                sum++;
            }
        }
        if (sum <= M)
        {
            l = mid;
        }
        else
            r = mid - 1;
    }
    cout << l;
}