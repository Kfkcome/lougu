#include <bits/stdc++.h>
using namespace std;
string n;
int k;
int main()
{
    cin >> n >> k;
    int len = n.length();
    for (int i = 0; i < len; i++)
    {
        if (n[i] > n[i + 1])
        {
            n.erase(i, 1);
            k--;
            i = -1;
            len--;
        }
        if (k == 0)
            break;
    }
    len = n.length();
    for (int i = 0; i < len; i++)
    {
        if (n[i] != '0')
        {
            break;
        }
        else
        {
            n.erase(i, 1);
            i=-1;
        }
    }
    if (n.length() == 0)
    {
        cout << 0;
        return 0;
    }
    cout << n;
    return 0;
}