#include<bits/stdc++.h>
using namespace std;
struct node 
{
    int x1,y1,x2,y2;
};
struct node p[1001];//矩形信息
int book[3030];//离散化
int m[10001][10001];//差分矩阵
int main()
{
    int N,pol=-1;
    for(int i=0;i<N;i++){
        cin>>p[i].x1>>p[i].y1>>p[i].x2>>p[i].y2;
        book[++pol]=p[i].x1;
        book[++pol]=p[i].y1;
        book[++pol]=p[i].x2;
        book[++pol]=p[i].y2;
    }
    sort(book,book+pol);//排序
    int uni=unique(book,book+pol)-book;//去重
    for(int i=0;i<N;i++)
    {
        p[i].x1=upper_bound(book,book+uni,p[i].x1)-book;
        p[i].y1=upper_bound(book,book+uni,p[i].y1)-book;
        p[i].x2=upper_bound(book,book+uni,p[i].x2)-book;
        p[i].y2=upper_bound(book,book+uni,p[i].y2)-book;
    }//二分索引
    for(int i=0;i<N;i++)
    {
        m[p[i].x1][p[i].y1]++;
        m[p[i].x2+1][p[i].y1]--;
        m[p[i].x1][p[i].y2+1]--;
        m[p[i].x2+1][p[i].y2]++;
    }
    for(int i=0;i<N;i++)
    {
        
    }
    return 0;
}