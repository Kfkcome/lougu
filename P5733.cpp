#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    cin >> a;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] >= 'a' && a[i] <= 'z')
        {
            cout << (char)(a[i] - 'a' + 'A');
        }
        else
            cout << a[i];
    }
    return 0;
}