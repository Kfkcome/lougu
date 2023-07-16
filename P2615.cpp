#include<bits/stdc++.h>
using namespace std;
int N;
int a[40][40];
int main()
{
    cin>>N;
    int x1,y1;
    a[0][N/2]=1;
    x1=0;y1=N/2;
    for(int i=2;i<=N*N;i++){
        if(x1==0&&y1!=N-1){
            a[N-1][y1+1]=i;
            x1=N-1;
            y1=y1+1;
        }
        else if(x1!=0&&y1==N-1)
        {
            a[x1-1][0]=i;
            x1=x1-1;
            y1=0;
        }
        else if (x1==0&&y1==N-1)
        {
            a[x1+1][y1]=i;
            x1=x1+1;
        }
        else if (x1!=0&&y1!=N-1)
        {
            if(a[x1-1][y1+1]==0){
                a[x1-1][y1+1]=i;
                x1=x1-1;
                y1=y1+1;
            }
            else {
                a[x1+1][y1]=i;
                x1=x1+1;
            }
        }
        //cout<<i<<' '<<x1<<' '<<y1<<endl;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}