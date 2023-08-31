#include <bits/stdc++.h>
using namespace std;
int R, C;
int dp[101][101];
int height[101][101];
struct node
{
    int i, j, weight;
};
int get(int i, int j)
{
    int maxi = 0;
    if (height[i][j] > height[i][j - 1]&&j-1>=1)
    {
        maxi = max(maxi, dp[i][j - 1]);
    }
     if (height[i][j] > height[i - 1][j]&&i-1>=1)
    {
        maxi = max(maxi, dp[i - 1][j]);
    }
     if (height[i][j] > height[i + 1][j]&&(i+1<=R))
    {
        maxi = max(maxi, dp[i + 1][j]);
    }
     if (height[i][j] > height[i][j + 1]&&(j+1<=C))
    {
        maxi = max(maxi, dp[i][j + 1]);
    }
    return maxi;
}
struct node a[10002];
int l;
bool cmp(struct node a, struct node b)
{
    return a.weight > b.weight;
}
int main()
{
    cin >> R >> C;
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            cin >> height[i][j];
            a[l].i = i;
            a[l].j = j;
            a[l].weight = height[i][j];
            l++;
        }
    }
    sort(a, a + l, cmp);
    while (l > 0)
    {
        l--;
        int i=a[l].i,j=a[l].j;
        dp[i][j]=get(i,j)+1;
    }

    int maxdp = 0;
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            maxdp = max(maxdp, dp[i][j]);
        }
    }
    cout << maxdp;
    return 0;
}