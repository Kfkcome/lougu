// #include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>


using namespace std;
static unsigned long next1 = 1;
int N, S, P, T;
double dt;
struct neuron
{
    // unordered_map<int, double> I;
    // double I[2010];
    double v, u, a, b, c, d;
    int t;           // 表示neuron所处的时间
} nes[2001];         // 神经元
int out_times[2001]; // 发生脉冲的次数
int mod = 0;
double I[1005][1005];
struct link
{
    double w;
    int D;
    int t = -1;
};

// 突触 注意第一个索引有可能大于等于N
// 如果大于等于N则为脉冲源
// unordered_map<int, vector<struct link>> m;
vector<struct link> m[2001];

double r[2001]; // 脉冲源
/* RAND_MAX assumed to be 32767 */
inline int myrand(void)
{
    next1 = next1 * 1103515245 + 12345;
    return ((unsigned)(next1 / 65536) % 32768);
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    // cin >> N >> S >> P >> T;
    // cin >> dt;
    scanf("%d %d %d %d", &N, &S, &P, &T);
    scanf("%lf", &dt);
    int sum = 0;
    while (sum < N)
    {
        int rn;
        double v, u, a, b, c, d;
        // cin >> rn >> v >> u >> a >> b >> c >> d;
        scanf("%d %lf %lf %lf %lf %lf %lf", &rn, &v, &u, &a, &b, &c, &d);
        for (register int i = 0; i < rn; i++)
        {
            nes[sum + i].a = a, nes[sum + i].b = b, nes[sum + i].c = c, nes[sum + i].d = d;
            nes[sum + i].v = v, nes[sum + i].u = u;
        }
        sum += rn;
    }
    for (register int i = 0; i < P; i++)
    {
        // cin >> r[i];
        scanf("%lf", &r[i]);
    }
    for (register int i = 0; i < S; i++)
    {
        struct link temp;
        int s;
        // cin >> s >> temp.t >> temp.w >> temp.D;
        scanf("%d %d %lf %d", &s, &temp.t, &temp.w, &temp.D);
        m[s].push_back(temp);
        mod = max(mod, temp.D + 1);
        // m[s][temp.t] = temp;
    }
    int t = 0;

    while (t < T)
    {
        t++;
        int t_tmp = t % mod;
        for (register int i = 0; i < P; i++) // 遍历脉冲源
        {
            // vector<struct link> temp = m[i + N];
            int rand = myrand();
            if (rand < r[i])
            {
                // for (int j = 0; j < N; j++)
                // {
                //     struct link item = m[i + N][j];
                //     if (item.t != -1)
                //         nes[item.t].I[t + item.D] += item.w;
                // }
                for (int j = 0; j < m[i + N].size(); j++)
                {
                    struct link item = m[i + N][j];
                    I[(t_tmp + item.D) % mod][item.t] += item.w;
                    // nes[item.t].I[t + item.D] += item.w;
                }
            }
        }
        for (register int i = 0; i < N; i++) //
        {
            nes[i].t = t;
            double v = nes[i].v, u = nes[i].u;
            nes[i].v = v + dt * (0.04 * v * v + 5 * v + 140 - u) + I[t_tmp][i];
            // nes[i].v = v + dt * (0.04 * v * v + 5 * v + 140 - u) + nes[i].I[t];
            // nes[i].I.erase(t);
            nes[i].u = u + dt * nes[i].a * (nes[i].b * v - u);
            if (nes[i].v >= 30)
            {
                out_times[i]++;
                nes[i].v = nes[i].c;
                nes[i].u += nes[i].d;
                for (int j = 0; j < m[i].size(); j++)
                {
                    struct link item = m[i][j];
                    I[(t_tmp + item.D) % mod][item.t] += item.w;
                    // nes[item.t].I[t + item.D] += item.w;
                }
            }
        }
        memset(I[t_tmp], 0, sizeof I[t_tmp]);
    }
    double max_v = -1 * 1e8, min_v = 1e8;
    int max_times = -1, min_times = 1e5;
    for (register int i = 0; i < N; i++)
    {
        max_v = max(nes[i].v, max_v);
        min_v = min(nes[i].v, min_v);
        max_times = max(out_times[i], max_times);
        min_times = min(out_times[i], min_times);
    }
    // cout << fixed << setprecision(3) << min_v << ' ' << max_v << endl;
    // cout << min_times << ' ' << max_times;
    printf("%.3f %.3f\n", min_v, max_v);
    printf("%d %d", min_times, max_times);
    return 0;
}