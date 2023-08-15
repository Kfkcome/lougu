#include<bits/stdc++.h>
using namespace std;
int w0,w;
double m;
int main()
{
    cin>>w0>>w>>m;
    double p=(w*m)/w0;
    double l=0,r=3;
    while (r-l>1e-9)
    {
        double mid=(l+r)/2;
        double temp=1;
        double sum=0;
        for(int i=0;i<m;i++){
            sum+=(mid+1)*temp*(1/m);
            temp=(mid+1)*temp;
        }
        if(sum-p<1e-9){
            l=mid;
        }
        else r=mid;
    }
    printf("%.1lf",r*100);
}