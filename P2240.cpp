#include <bits/stdc++.h>
using namespace std;
int N, T;
float sum;
struct coin
{
    int m, v;
    float value;
};
struct coin all[101];
bool cmp(struct coin a, struct coin b)
{
    return a.value > b.value;
}
int main()
{
    cin >> N >> T;
    for (int i = 0; i < N; i++)
    {
        cin >> all[i].m >> all[i].v;
        all[i].value = all[i].v / (all[i].m * 1.0);
    }
    sort(all, all + N, cmp);
    int i = 0;
    while (T > 0)
    {
        if (all[i].m > T)
        {
            sum += T * all[i].value;
            T = 0;
        }
        else
        {

            sum += all[i].v;
            T = T - all[i].m;
        }
        i++;
        if (i >= N)
        {
            break;
        }
    }
    printf("%.2f", sum);
    return 0;
}