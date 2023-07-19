#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int minn=999999999;
    for(int i=m-1;i<n;i++){
        int sum=0;
        for(int j=0;j<m;j++){
            sum+=a[i-j];
        }
        minn=min(minn,sum);
    }
    cout<<minn;
}
