#include<bits/stdc++.h>
using namespace std;
int L,N,K;
int pol[100000];
int main()
{
    cin>>L>>N>>K;
    int maxn=0;
    for(int i=0;i<N;i++)
    {
        cin>>pol[i];
        maxn=max(maxn,pol[i]-pol[i-1]);
    }
    int l=1,r=maxn;
    while (l<r)
    {
        int mid=(l+r)/2;
        list<int> ls;
        int sum=0;//增加路标数量
        ls.push_back(pol[0]);
        for(int i=1;i<N;i++)
        {
            ls.push_back(pol[i]);
            list<int>::iterator it=ls.end();
            int a=*(--it),b=*(--it);
            if(a-b>mid){
                int x=(a-b)/mid;
                if((a-b)%mid==0)x--;
                it++;
                for(int j=1;j<=x;j++){
                    ls.insert(it,b+j*mid);
                }
                sum+=x;
            }
        }
        if(sum<=K){
            r=mid;
        }
        else {
            l=mid+1;
        }
    }
    cout<<l;
}