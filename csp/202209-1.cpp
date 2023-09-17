#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[21], c[22],temp[21];
int main()
{
    cin >> n >> m;
    c[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        c[i] = c[i - 1] * a[i];
    }
    for(int i=1;i<=n;i++)
    {
        temp[i]=m%c[i];
    }
    for(int i=1;i<=n;i++)
    {
        cout<<(temp[i]-temp[i-1])/c[i-1]<<' ';
    }
    return 0;
}