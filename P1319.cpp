#include<bits/stdc++.h>
using namespace std;
int a[201][201];
int main()
{
    int N;
    cin>>N;
    int num=0;
    int x=0,y=0;
    int t=0;
    while(num!=N*N)
    {
        int temp;
        cin>>temp;
        for(int i=0;i<temp;i++)
        {
            a[x][y]=t;
            y++;
            if(y==N){
                x++;
                y=0;
            }
            num++;
        }
        t=!t;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }
}