#include <bits/stdc++.h>
using namespace std;
int n;
struct line
{
    int l;
    int r;
};
long dp[20001][2];
struct line lines[20001];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> lines[i].l >> lines[i].r;
    }
    dp[1][0]=lines[1].r+lines[1].r-lines[1].l-1;
    dp[1][1]=lines[1].r-1;
    for (int i = 2; i <= n; i++)
    {
        int l=lines[i-1].l;
        int r=lines[i-1].r;
        dp[i][0]=1+min(dp[i-1][0]+abs(l-lines[i].r)+lines[i].r-lines[i].l,dp[i-1][1]+abs(r-lines[i].r)+lines[i].r-lines[i].l);
        dp[i][1]=1+min(dp[i-1][0]+abs(l-lines[i].l)+lines[i].r-lines[i].l,dp[i-1][1]+abs(r-lines[i].l)+lines[i].r-lines[i].l);
    }
    cout << dp[n][1]+n-lines[n].r;
    return 0;
}