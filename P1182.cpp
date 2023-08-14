#include<bits/stdc++.h>
using namespace std;
int N,M;
int a[100001];
bool check(int x){
    int cur=0,ans=1;
    for(int i=1;i<=N;i++){
        if(cur+a[i]>x){
            cur=a[i];
            ans++;
        }
        else cur+=a[i];
    }
    return ans<=M;
}
int main()
{
    cin>>N>>M;
    int maxn=0;
    int l=0,r=0;
    for(int i=1;i<=N;i++)
    {
        cin>>a[i];
        l=max(l,a[i]);
        r+=a[i];
    }
    while(l<r)
    {
        int mid=(l+r)/2;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    cout<<l;
}