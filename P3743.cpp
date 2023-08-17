#include<bits/stdc++.h>
using namespace std;
int n,p;
struct device{
    int a,b;
};
struct device d[100000];
bool check(double x){
    
}
int main()
{
    cin>>n>>p;
    int sum=0,powersum=0;
    for(int i=0;i<n;i++){
        cin>>d[i].a>>d[i].b;
        sum+=d[i].a;
        powersum+=d[i].b;
    }
    if(sum<=p)
    {
        cout<<-1;
        return 0;
    }
    double l=0.0001,r=(powersum+p)/sum;
    while (r-l>1e-4)
    {
        double mid=(r+l)/2;
        
    }
    

    
    
}