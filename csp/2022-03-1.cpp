#include <bits/stdc++.h>
using namespace std;
bool initial[100001];
int main()
{
    int n, k;
    cin >> n >> k;
    int sum = 0;
    initial[0] = true;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        if (!initial[y])
            sum++;
        initial[x] = true;
    }
    cout << sum;
    return 0;
}