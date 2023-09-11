#include<bits/stdc++.h>
using namespace std;
int v,n;
int w[31];
int dp[31][200001];
int main()
{
    cin>>v>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=v;j++)
        {
            if(j>=w[i]){
                dp[i][j]=max(dp[i-1][j-w[i]]+w[i],dp[i-1][j]);
            }
            else dp[i][j]=dp[i-1][j];
        }
    }
    cout<<v-dp[n][v];
    return 0;
}