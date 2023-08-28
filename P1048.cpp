#include<bits/stdc++.h>
using namespace std;
int T,M;
struct medicine{
    int t,v;
};
struct medicine m [101];
int dp[101][1001];
int main()
{
    cin>>T>>M;
    for(int i=1;i<=M;i++){
        cin>>m[i].t>>m[i].v;
    }
    for(int i=1;i<=M;i++){
        for(int j=1;j<=T;j++){
            if(j>=m[i].t)
                dp[i][j]=max(dp[i-1][j-m[i].t]+m[i].v,dp[i-1][j]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[M][T];
}