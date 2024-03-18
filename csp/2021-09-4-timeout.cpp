#include <iostream>
using namespace std;
int n, k;
double p[17];
int getp[17];
double expect; // 期望
bool check_card()
{
    for (int i = 0; i < n; i++)
    {
        if (!getp[i])
        {
            return false;
        }
    }
    return true;
}
bool check_redeem(int coin_num) // 检查是否可以完全兑换完
{
    int unget_card = 0;
    for (int i = 0; i < n; i++)
    {
        if (!getp[i])
        {
            unget_card++;
        }
    }
    if (coin_num >= unget_card * k)
    {
        return true;
    }
    return false;
}
void dfs(double sump, int coin_num, int get_num)
{
    if (check_card() || check_redeem(coin_num))
    {
        expect += sump * (double)get_num;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (getp[i]) // 已经得到了i卡片的话
        {
            coin_num++;
        }
        getp[i]++;
        dfs(sump * p[i], coin_num, get_num + 1);
        getp[i]--;
        if (getp[i]) // 已经得到了i卡片的话
        {
            coin_num--;
        }
    }
}
int main()
{
    // cin >> n >> k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        // cin >> p[i];
        scanf("%lf", &p[i]);
    }
    dfs(1, 0, 0);

    // cout << expect << endl;
    printf("%.10lf\n", expect);
    return 0;
}
