#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
int main()
{
    cout << mod << endl;

    long long a = -10000000000;
    long long temp=a%mod;
    if(temp<0){
        cout<<temp+mod;
    }
}