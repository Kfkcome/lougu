#include<bits/stdc++.h>
using namespace std;
int m[1002][1002];
int main()
{
    int N,M,C;
    cin>>N>>M>>C;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
           cin>>m[i][j];
           m[i][j]=m[i][j]+m[i-1][j]+m[i][j-1]-m[i-1][j-1];//构建前缀和数组
        }
    }
    int value=m[1+C-1][1+C-1]-m[1+C-1][1-1]-m[1-1][1+C-1]+m[1-1][1-1];//初始化
    int x=1,y=1;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {   
            if(i+C-1<=N&&j+C-1<=M&&value<(m[i+C-1][j+C-1]-m[i+C-1][j-1]-m[i-1][j+C-1]+m[i-1][j-1])){
                x=i;
                y=j;
                value=m[i+C-1][j+C-1]-m[i+C-1][j-1]-m[i-1][j+C-1]+m[i-1][j-1];
            }
        }
    }
    cout<<x<<' '<<y;
}