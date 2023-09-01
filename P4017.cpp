#include<bits/stdc++.h>
using namespace std;
int n,m;
bool kind[5002][5002];
long long dp[5001];
struct species{
    int a,//可以吃的生物数量
    b;//能吃它的物种数量
};
queue<int>q;
struct species s[5001];
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        kind[a][b]=1;
        s[a].b++;
        s[b].a++;
    }
    for(int i=1;i<=n;i++){
        if(s[i].a==0){
            q.push(i);
            dp[i]++;
        }
    }
    while(!q.empty()){
        int k=q.front();
        q.pop();
        for(int i=1;i<=n;i++)
        {
            if(kind[k][i]){
                s[i].a--;
                dp[i]=(dp[i]+dp[k])%80112002;
                if(s[i].a==0){
                    q.push(i);
                }
            }
        }
    }
    long long maxi=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i].b==0)
        {
            maxi=(dp[i]+maxi)%80112002;
        }
    }
    cout<<maxi%80112002;
    return 0;    
}