#include<bits/stdc++.h>
using namespace std;
int n;
int a[200001];
int dp[2];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int maxi=-1<<20;
    for(int i=1;i<=n;i++)
    {
        dp[i%2]=max(dp[(i-1)%2]+a[i],a[i]);
        maxi=max(dp[i%2],maxi);
    }
    cout<<maxi;
    
}