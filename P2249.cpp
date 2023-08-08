#include <bits/stdc++.h>
using namespace std;
int num[1000000];
int n, m;
int binSearch(int x){
    int l=0,r=n-1;
    while(l<r){
        int mid=(l+r)/2;
        if(num[mid]>=x)r=mid;
        else l=mid+1;
    }
    if(num[r]!=x)return -1;
    return r+1;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        cout<<binSearch(t)<<' ';
    }
}