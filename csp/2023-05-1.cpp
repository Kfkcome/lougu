#include <bits/stdc++.h>
using namespace std;
int n;
string step[101][8];
int times[101];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 8; j++)
            cin >> step[i][j];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            bool flag = true;
            for (int k = 0; k < 8; k++)
            {
                if (step[i][k] != step[j][k])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                times[i]++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << times[i] << endl;
    }
    return 0;
}