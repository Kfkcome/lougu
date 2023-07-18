#include<bits/stdc++.h>
using namespace std;
int num[10];
void update(string m){
    for(int i=0;i<m.length();i++){
        num[m[i]-'0']++;
    }
}
int main()
{
    string M,N;
    cin>>M>>N;
    N=to_string(stoi(N)+1);
    do
    {
        update(M);
        int a=stoi(M);
        a++;
        M=to_string(a);
    }while(N!=M);
    for(int i=0;i<10;i++){
        cout<<num[i]<<' ';
    }
}