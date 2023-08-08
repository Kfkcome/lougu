#include<bits/stdc++.h>
using namespace std;
int m[502][502];
int main()
{
    int R,C;
    for(int i=1;i<=R;i++)
    {
        for(int j=1;j<=C;j++)
        {
            cin>>m[i][j];
            m[i][j]=m[i][j]+m[i][j-1]+m[i-1][j]-m[i-1][j-1];
        }
    }
}