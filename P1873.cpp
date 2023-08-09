#include<bits/stdc++.h>
using namespace std;
int N,M;
int tree[1000000];
bool check(int x){
    long sum=0;
    for(int i=0;i<N;i++)
    {
        sum+=tree[i]-x>0?tree[i]-x:0;
    }
    if(sum-M>=0){
        return 1;
    }
     return 0;
}
int main()
{
    cin>>N>>M;
    int maxn=-1;
    for(int i=0;i<N;i++)
    {
        cin>>tree[i];
        maxn=max(maxn,tree[i]);
    }
    int l=1,r=maxn;
    while(l<r){
        int mid=(r+l+1)/2;
        if(check(mid)){
            l=mid;
        }else r=mid-1;
    }
    cout<<l;
}