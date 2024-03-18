#include <iostream>
#include <cstring>
using namespace std;
int n, k;
double p[17];
double m[100][1 << 16]; // 存储的值是对应状态的期望
bool check_card(int get_num)
{
    int t = 1;
    for (int i = 0; i < n; i++)
    {
        if (!(get_num & t))
        {
            return false;
        }
        t *= 2;
    }
    return true;
}
int binary_to_num(int get_num) // 将二进制转换为十进制
{
    int t = 1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if ((get_num & t))
        {
            sum++;
        }
        t *= 2;
    }
    return sum;
}
bool check_redeem(int coin_num, int get_num) // 检查是否可以完全兑换完
{
    int unget_card = n - binary_to_num(get_num);
    if (coin_num >= unget_card * k)
    {
        return true;
    }
    return false;
}

double dfs(int coin_num, int num, int state /*是card的二进制*/)
{
    if (m[coin_num][state])
    {
        return m[coin_num][state];
    }
    if (check_card(state) || check_redeem(coin_num, state))
    {
        m[coin_num][state] = num;
        return m[coin_num][state];
    }
    int t = 1;
    double s = 0;
    for (int i = 0; i < n; i++)
    {
        if ((state & t)) // 如果已将得到了这个卡片
        {
            s += p[i] * dfs(coin_num + 1, num + 1, state);
        }
        else // 如果还没有得到这个卡片
        {
            s += p[i] * dfs(coin_num, num + 1, (state | t));
        }
        t *= 2;
    }

    return m[coin_num][state] = s;
}
int main()
{
    cin >> n >> k;
    // scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        // scanf("%lf", &p[i]);
    }
    // memset(m, -1, sizeof(m));
    // cout << dfs(0, 0, 0);
    printf("%.10lf\n", dfs(0, 0, 0));
    return 0;
}
