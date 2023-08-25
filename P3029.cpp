#include<bits/stdc++.h>
using namespace std;
int N;
struct cow{
    int x,id;
};
struct cow c[50001];
set<int>s;
map<int,int>kind;
int len[50001];
bool cmp(struct cow c1,struct cow c2){
    return c1.x<c2.x;
}
int main()
{
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        cin>>c[i].x>>c[i].id;
        s.insert(c[i].id);
    }
    int k=s.size();
    sort(c+1,c+N+1,cmp);
    int l=1,r=2;
    int ans=1<<30;
    kind[c[l].id]=1;
    for(r=2;r<=N;r++)
    {
        if(kind.find(c[r].id)==kind.end()){
            kind[c[r].id]=1;
        }
        else kind[c[r].id]++;
        int tol=kind.size();
        while(true){
            kind[c[l].id]--;
            if(kind[c[l].id]==0){
                kind[c[l].id]++;
                //if(l!=1)l--;
                break;
            }
            l++;
        }
        if(tol==k){
            ans=min(ans,c[r].x-c[l].x);
        }
    }
    cout<<ans;
}