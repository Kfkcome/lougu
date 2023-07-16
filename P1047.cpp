#include<bits/stdc++.h>
using namespace std;
int tree[10000];
int main(){
    int l,m;
    cin>>l>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        for(int j=u;j<=v;j++)
        {
            tree[j]=1;
        }
    }
    int count=0;
    for(int i=0;i<=l;i++)
    {
        if(tree[i]==0){
            count++;
        }
    }
    cout<<count;
}