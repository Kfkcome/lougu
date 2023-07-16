#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[100];
    int temp,i=0;
    cin>>temp;
    while (temp!=0)
    {
        a[i]=temp;
        i++;
        cin>>temp;
    }
    for(int j=i-1;j>=0;j--)
    {
        cout<<a[j]<<' ';
    }
    return 0;
}