#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    set<int>s;
    int *a=new int [n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++){
            s.insert(a[i]+a[j]);
        }
    }
    int  count=0;
    for(int i=0;i<n;i++){
        set<int>::iterator it=s.find(a[i]);
        if(it!=s.end())
        {
            count++;
        }
    }
    cout<<count;
}