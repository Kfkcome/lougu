#include<bits/stdc++.h>
using namespace std;
struct ship{
    long long a;
    long long b;
};
struct ship s[20002];
int main()
{
    int n;
    int length=0;
    cin>>n;
    long a1[20001],b1[20001];
    for(int i=0;i<n;i++)
    {
        cin>>a1[i];
        cin>>b1[i];
    }
    sort(a1,a1+n-1);
    sort(b1,b1+n-1);
    for(int i=0;i<n;i++)
    {
        long long a,b;
        a=a1[i];
        b=b1[i];
        bool flag=false;
        for(int j=0;j<length;j++)
        {
            if(b<s[j].a||a>s[j].b){
                continue;
            }
            else {
                s[j].a=min(a,s[j].a);
                s[j].b=max(b,s[j].b);
                flag=true;
                break;
            }
        }
        if(!flag){
            s[length].a=a;
            s[length].b=b;
            length++;
        }
    }
    long long  num=0;
    for(int i=0;i<length;i++){
        num+=s[i].b-s[i].a;
    }
    cout<<num;
}
