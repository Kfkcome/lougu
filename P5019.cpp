#include <bits/stdc++.h>
using namespace std;
int n, d[100001], days;
int getTime(int l,int r,int k)
{
    int mini=l;
    if(l==r)
    {
        return d[l]-k;
    }
    if(l>r)
    {
        return 0;
    }  
    for(int i=l;i<=r;i++)
    {
        if(d[mini]>d[i])
        {
            mini=i;
        }
    }
    int temp=getTime(l,mini-1,d[mini])+getTime(mini+1,r,d[mini])+d[mini]-k;
    return temp;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    int time=getTime(1,n,0);
    cout<<time;
    return 0;
}