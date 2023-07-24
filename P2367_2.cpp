#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

const int INF = 0x3f3f3f3f, MAXN = 5000005;
int n, q, l, r, val, a[MAXN], diff[MAXN];
int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= q; i++) {
        scanf("%d%d%d", &l, &r, &val);
        diff[l] += val; diff[r + 1] -= val;//差分数组
    }
    int Min = INF, tmp = 0;
    for (int i = 1; i <= n; i++) {
        tmp += diff[i];//查询这一个位置的修改值
        if (a[i] + tmp < Min) Min = a[i] + tmp;
    }
    printf("%d\n", Min);
    return 0;
}