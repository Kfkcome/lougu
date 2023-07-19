#include<bits/stdc++.h>
using namespace std;
//使用前缀和来求解 减少时间复杂度变成O(n)
int main(){
    int n,m;
    cin>>n>>m;
    int *a=new int [n+1];
    a[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]=a[i-1]+a[i];
    }
    int mini=1<<30;
    for(int i=m;i<=n;i++){
        mini=min(mini,a[i]-a[i-m]);
    }
    cout<<mini;
}