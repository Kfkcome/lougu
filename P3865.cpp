#include <iostream>
using namespace std;
int N, M;
int lg[100001];
long f[100001][20];
int main()
{
    int i = 0, j;
    int l = 1, r = 1, a, s;
    scanf("%d%d", &N, &M);
    lg[0] = -1;
    for (i = 1; i <= N; i++)
    {
        scanf("%d", &a);
        lg[i] = lg[i >> 1] + 1;
        f[i][0] = a;
    }

    for (j = 1; j <= lg[N]; j++)
    {
        for (i = 1; i <= N - (1 << j) + 1; i++)
        {
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }
    for (i = 0; i < M; i++)
    {
        scanf("%d%d", &l, &r);
        s = lg[r - l + 1];
        printf("%d\n", max(f[l][s], f[r - (1 << s) + 1][s]));
    }
    return 0;
}