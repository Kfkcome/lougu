#include <bits/stdc++.h>
using namespace std;
int n, m;
struct goods
{
    int v, p;
    int q_num;
    bool top;
    int q[3]; // 价格、重要程度、附件的数目
};
struct goods g[61];
int dp[32001];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int v, p, q;
        cin >> v >> p >> q;
        if (!q)
        {
            g[i].v = v;
            g[i].p = p;
            g[i].q_num = 0;
            g[i].top = true;
        }
        else
        {
            g[i].v = v;
            g[i].p = p;
            g[i].q_num = 0;
            g[i].top = false;
            g[q].q[g[q].q_num] = i;
            g[q].q_num++;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (!g[i].top)
            {
                continue;
            }
            if (j >= g[i].v)
            {
                dp[j] = max(dp[j], dp[j-g[i].v]+g[i].v*g[i].p);
            }
            if(g[i].q_num>=1&&j>=g[g[i].q[0]].v+g[i].v){
                dp[j]=max(dp[j],dp[g[g[i].q[0]].v+g[i].v])
            }
        }
    }
    return 0;
}