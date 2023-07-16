#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int *a=new int [n];
    int *b=new int [n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        int count=0;
        for(int j=0;j<i;j++){
            if(a[i]>a[j])
            {
                count++;
            }
        }
        b[i]=count;
    }
    for(int i=0;i<n;i++)
    {
        cout<<b[i]<<' ';
    }
    return 0;
}