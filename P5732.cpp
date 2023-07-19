#include<bits/stdc++.h>
using namespace std;
int a[21][21];
int main()
{
    int n;
    cin>>n;
    a[1][1]=1;
    cout<<a[1][1]<<endl;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            a[i][j]=a[i-1][j]+a[i-1][j-1];
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
}