#include <bits/stdc++.h>
using namespace std;
int n, sum;
struct solve
{
    int i, j;
};
struct solve s[100];
void show()
{
    for (int i = 1; i <= n; i++)
    {
        cout << s[i].i << ' ';
    }
    cout << endl;
}
void dfs(int x)
{
    if (x > n)
    {
        if (sum < 3)
            show();
        sum++;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        bool flag = true;
        for (int j = 1; j < x; j++)
        {
            if (i == s[j].i || i - x == s[j].i - s[j].j || i + x == s[j].i + s[j].j)
            {
                flag = false;
                break;
            }
            if (j == x - 1 && s[j].i - 1 <= i && s[j].i + 1 >= i)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            s[x].i = i;
            s[x].j = x;
            dfs(x + 1);
        }
    }
}
int main()
{
    cin >> n;
    dfs(1);
    cout << sum;
    return 0;
}