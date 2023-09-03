#include<bits/stdc++.h>
using namespace std;
int n,x;
struct people{
    int lose,win,use;
};
struct people p[1001];
long dp[1001][1001];
int main()
{
    cin>>n>>x;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i].lose>>p[i].win>>p[i].use;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            if(j>=p[i].use){
                dp[i][j]=max(dp[i-1][j-p[i].use]+p[i].win,dp[i-1][j]+p[i].lose);
            }
            else dp[i][j]=dp[i-1][j]+p[i].lose;
        }
    }
    cout<<dp[n][x]*5;
    return 0;
}