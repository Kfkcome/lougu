#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<int,int> m;
    int a=1;
    int key=5;
    m[key]=a;
    m[1]=0;
    map<int,int>::iterator it=m.find(9);
    cout<<it->first<<' '<<it->second<<endl;
    return 0;
}