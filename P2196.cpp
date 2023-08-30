#include<bits/stdc++.h>
using namespace std;
int N;
int num[21];
bool links[21][21];
int dp[21];
int main()
{
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        cin>>num[i];
    }
    for(int i=1;i<=N-1;i++)
    {
        for(int j=2;j<=N-i;j++)
        {
            cin>>links[i][j];
            links[j][i]=links[i][j];
        }
    }
    for(int i=1;i<=N;i++){
        int maxi=1;
        for(int j=1;j<=N;j++){
            if(dp[j]>dp[maxi]&&links[j][i]==1){
                maxi=j;
            }
        }
        dp[i]=num[i]+dp[maxi];
    }
    int maxi=0;
    for(int i=1;i<=N;i++)
    {
        maxi=max(maxi,dp[i]);
    }
    cout<<maxi;
    return 0;
}