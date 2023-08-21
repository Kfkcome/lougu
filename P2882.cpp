#include <bits/stdc++.h>
using namespace std;
int n;
bool cow[5001];
int revert[5001];
bool check(int *x) // 检测是否有0
{
    for (int i = 1; i <= n; i++)
    {
        x[i] += x[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        if ((cow[i] && x[i] % 2 == 1) || (!cow[i] && x[i] % 2 == 0))
        {
            return false;
        }
    }
    return true;
}
int main()
{
    cin >> n;
    char temp;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        if (temp == 'B')
        {
            cow[i] = 0;
        }
        else
            cow[i] = 1;
    }
    int minK = n, minM = 1 << 30;
    for (int i = n; i >= 1; i--)
    {
        memset(revert, 0, sizeof(revert));
        int m = 0;
        bool flag;
        int bsum=0;
        // 检测全部变为1可不可行
        for (int j = 1; j <= n - i + 1; j++)
        {
            bsum+=revert[j];
            if ((bsum%2==1&&cow[j])||(bsum%2==0&&!cow[j]))
            {
                revert[j]++;
                bsum++;
                revert[j + i]--;
                m++;
            }
        }
        flag = check(revert);
        if (flag && minM > m)
        {
            minM = m;
            minK = i;
        }
    }
    cout << minK << ' ' << minM;
}