#include <iostream>

using namespace std;
typedef long long ll;
const int INF=1e6+5;

int n,x;
int a[50];
int s[50];
int sum;
int minn=INF;
void dfs(int i){
    if(sum<x)
        return;
    minn=min(sum,minn);
    for(int j=i;j<=n;j++){
        sum-=a[j];
        dfs(j+1);
        sum+=a[j];
    }
}

int main()
{
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+ a[i];
    }
    sum=s[n];
    dfs(1);
    cout<<minn;


    return 0;
}