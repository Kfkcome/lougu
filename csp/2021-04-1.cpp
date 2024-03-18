#include <bits/stdc++.h>
using namespace std;
int n, m, L;
int h[257];
int main()
{
    cin >> n >> m >> L;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int temp;
            cin >> temp;
            h[temp]++;
        }
    }
    for (int i = 0; i < L; i++)
    {
        cout << h[i] << ' ';
    }
    return 0;
}