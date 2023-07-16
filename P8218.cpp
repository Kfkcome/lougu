#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int *a=new int [n+1];
    for(int i=1;i<=n;i++)
    {
        int temp;
        cin>>temp;
        a[i]=i==1?temp:
        temp+a[i-1];
    }
    a[0]=0;
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int l,r;
        cin>>l>>r;
        cout<<a[r]-a[l-1]<<endl;
    }
}