#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin>>N;
    int **s=new int *[N];
    for(int i=0;i<N;i++)
    {
        s[i]=new int [4];
        cin>>s[i][0]>>s[i][1]>>s[i][2];
        s[i][3]=s[i][0]+s[i][1]+s[i][2];
    }
    int count=0;
    for(int i=0;i<N;i++)
    {
        for(int j=i+1;j<N;j++){
            if(s[i][3]-s[j][3]<=10&&s[i][3]-s[j][3]>=-10)
            {
                bool flag=true;
                for(int k=0;k<3;k++)
                {
                    if(s[i][k]-s[j][k]>5||s[i][k]-s[j][k]<-5){
                        flag=false;
                    }
                }
                if(flag){
                    count++;
                }
            }
        }
    }
    cout<<count;
}