#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string temp;
        cin>>temp;
        if(temp!="AC"){
            cout<<i<<' ';
        }
    }
    return 0;
}