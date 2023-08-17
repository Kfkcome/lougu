#include<bits/stdc++.h>
using namespace std;
double w0,w;
double m;
int main()
{
    cin>>w0>>w>>m;
    double l=0,r=10;       
    while (r-l>1e-4)
    {
        double mid=(l+r)/2;
        double sum=0;
        if(pow(1.0/(1.0+mid),m)>=1-w0/w*mid){
            r=mid;
        }
        else l=mid;
    }
    printf("%.1lf",l*100);
}