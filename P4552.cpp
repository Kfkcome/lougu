#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[100001];
long long b[100001];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        b[i]=a[i]-a[i-1];
    }
    long long sumf=0,sumz=0;
    for(int i=2;i<=n;i++){
        if(b[i]>0){
            sumf+=b[i];
        }
        else sumz-=b[i];
    }
    long long p=max(sumf,sumz);
    long long k=p-min(sumf,sumz)+1;
    cout<<p<<endl<<k;
    return 0;
}