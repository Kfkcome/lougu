#include<bits/stdc++.h>
using namespace std;
int n;
double p;
struct device{
    double a,b;
};
struct device d[100000];
bool check(double x){
    double sum=0;
    for(int i=0;i<n;i++){
        if(d[i].a*x<=d[i].b){//若设备已有的能量大于使用时间需要的能量
			continue;//忽略该设备
		}
        sum+=d[i].a*x-d[i].b;
    }
    if(p*x>=sum)return true;
    return false;

}
int main()
{
    cin>>n>>p;
    double sum=0,powersum=0;
    for(int i=0;i<n;i++){
        cin>>d[i].a>>d[i].b;
        sum+=d[i].a;
        powersum+=d[i].b;
    }
    if(sum<=p)
    {
        cout<<-1.000000000;
        return 0;
    }
    double l=0,r=1e10;
    while (r-l>1e-4)
    {
        double mid=(r+l)/2;
        if(check(mid))l=mid;
        else r=mid;
    }
    cout<<r;
    return 0;
}