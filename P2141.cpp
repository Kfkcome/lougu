#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = a[i];
        for (int j = 0; j < n; j++)
        {
            if (j == i)
                continue;
            for (int k = j + 1; k < n; k++)
            {
                if (k == i)
                    continue;
                if (a[j] + a[k] == temp)
                {
                    count++;
                    goto re;
                }
            }
        }
    re:
        continue;
    }
    cout << count;
}