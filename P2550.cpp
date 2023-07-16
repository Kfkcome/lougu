#include<bits/stdc++.h>
using namespace std;
int s[34];
int checkPower(int *a){
    int count=0;
    for(int i=0;i<7;i++)
    {
        if(s[a[i]]==1){count++;}
    }
    return count;
}
int main(){
    int n;
    int num[8];//中奖张数,中奖号码
    for(int i=0;i<8;i++)
    {
        num[i]=0;
    }
    cin>>n;
    int **a=new int *[n+1];//小明买的彩票
    int temp;
    for(int i=0;i<7;i++)
    {
        cin>>temp;
        s[temp]=1;
    }
    for(int i=0;i<n;i++)
    {
        a[i]=new int [8];
        for(int j=0;j<7;j++){
            cin>>a[i][j];
        }
        num[7-checkPower(a[i])]++;
    }
    for (int i = 0; i < 7; i++)
    {
        cout<<num[i]<<' ';
    }
    return 0;
}