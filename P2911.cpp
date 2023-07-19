#include<bits/stdc++.h>
using namespace std;
int count1[90];
int main()
{
    int s1,s2,s3;
    cin>>s1>>s2>>s3;
    int max=0;
    int maxi=0;
    for(int i=1;i<=s1;i++)
    {
        for(int j=1;j<=s2;j++)
        {
            for (int k = 1; k <= s3; k++)
            {
                count1[i+j+k]++;
                if(count1[i+j+k]>max){
                    maxi=i+j+k;
                    max=count1[i+j+k];
                }
                else if(count1[i+j+k]==max){
                    if((i+j+k)<maxi){
                        maxi=i+j+k;
                    }
                }
            }
            
        }
    }
    cout<<maxi;
}