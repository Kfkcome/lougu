#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[200],i=0;
    while (n!=1)
    {
        a[i]=n;
        if(n%2==0){
            n=n/2;
        }
        else {
            n=(n*3+1);
        }
        i++;
    }
    a[i]=1;
    for(int j=i;j>=0;j--){
        cout<<a[j]<<' ';
    }
    return 0;
}