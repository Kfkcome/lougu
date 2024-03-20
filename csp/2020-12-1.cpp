#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int w, s;
        cin >> w >> s;
        sum += w * s;
    }
    cout << max(0, sum);
    return 0;
}