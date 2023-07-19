#include<bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
    string s[201];
    cin>>s[0];
    for(int i=1;i<s[0].length();i++){
        cin>>s[i];
    }
    int N=s[0].length();
    int k=0;
    int t=0;//当前记录的数 先记录0
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++){
            if(s[i][j]==t+'0'){
                a[k]++;
            }
            else {
                k++;
                a[k]++;
                t=!t;
            }
        }
    }
    cout<<N<<' ';
    for(int i=0;i<=k;i++){
        cout<<a[i]<<' ';
    }
}