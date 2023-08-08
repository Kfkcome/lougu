#include<bits/stdc++.h>
using namespace std;
int t[100000];
int n;
int k;
bool check(int mid)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=t[i]/mid;
    }
    if(sum<k){
        return 0;
    }
    return 1;
}
int main()
{
    cin>>n>>k;
    int minit=-1<<19;
    for(int i=0;i<n;i++)
    {
        cin>>t[i];
        minit=max(minit,t[i]);
    }
    int l=0,r=minit;
    while (l<r)
    {
        int mid = (r+l+1)/2;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    cout<<l;
}