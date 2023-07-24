#include <bits/stdc++.h>
using namespace std;
int a[5000002];
int b[5000002];
int main()
{
    long n, p, x, y, z;
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i]=a[i]-a[i-1];//这里出错了这样构建的差分数组是不对的
        //导致我一直找不到bug 吐了
        //所以还是重新建一个数组为好
    }
    for (int i = 0; i < p; i++)
    {
        cin >> x >> y >> z;
        b[y + 1] -= z;
        b[x] += z;
    }
    int mini = 100;
    for (int i = 1; i <= n; i++)
    {
        a[i]=a[i-1]+b[i];//这里也容易出错如果不更新a[i]则会导致后续结果出错
        mini = min(a[i], mini);
    }
    cout << mini;
}