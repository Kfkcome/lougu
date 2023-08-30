#include<bits/stdc++.h>
using namespace std;
int N;
int num[300];
bool links[300][300];
int dp[200];
int pre[300];
int main()
{
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        cin>>num[i];
    }
    for(int i=1;i<=N-1;i++)
    {
        for(int j=i+1;j<=N;j++)
        {
            cin>>links[i][j];
            links[j][i]=links[i][j];
        }
    }
    for(int i=0;i<=N;i++){
        pre[i]=i;
    }
    for(int i=1;i<=N;i++){
        int maxi=i;
        for(int j=1;j<=N;j++){
            if(dp[j]>dp[maxi]&&links[j][i]==1){
                maxi=j;
            }
        }
        dp[i]=num[i]+dp[maxi];
        pre[i]=maxi;
    }
    int maxi=0;
    for(int i=1;i<=N;i++)
    {
        if(dp[i]>dp[maxi]){
            maxi=i;
        }
    }
    int i=maxi;
    int *way=new int [N+1];
    int l=0;
    way[l++]=maxi;
    while (pre[i]!=i)
    {
        way[l++]=pre[i];
        i=pre[i];
    }
    for(int i=l-1;i>=0;i--){
        cout<<way[i]<<' ';
    }
    cout<<endl<<dp[maxi];
    return 0;
}