#include <bits/stdc++.h>
using namespace std;
long long n, m;
struct avaliable
{
    int a;
    long long time;
};
unordered_map<int, map<int, vector<struct avaliable>>> cost;
int search(int day, int id)
{
    int maxi = -1;
    long long max_sum = 0;
    for (auto item : cost[id])
    {
        long long sum = 0;
        for (int i = 0; i < item.second.size(); i++)
        {
            if (item.second[i].time >= day)
            {
                sum += item.second[i].a;
            }
            else
            {
                item.second.erase(item.second.begin() + i);
                i--;
            }
        }
        if (maxi == -1 || (sum > max_sum))
        {
            maxi = item.first;
            max_sum = sum;
        }
    }

    if (max_sum <= 0)
    {
        return 0;
    }
    return maxi;
}
int main()
{
    // freopen("1.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int u, v, x, y;
            cin >> u >> v >> x >> y;
            struct avaliable temp;
            temp.a = x;
            temp.time = i + y - 1;
            cost[u][v].push_back(temp);
            cost[v][u].push_back(temp);
        }
        int l;
        cin >> l;
        int pattern[100001];
        bool pat_true[100001];
        memset(pat_true, 0, sizeof(pat_true));
        for (int j = 0; j < l; j++)
        {
            int id;
            cin >> id;
            pat_true[id] = true;
            pattern[id] = search(i, id);
            cout << pattern[id] << endl;
        }
        int p, q;
        cin >> p >> q;

        if (p == 1)
        {
            int sum = 0;
            for (int j = 1; j <= n; j++)
            {
                pattern[j] = search(i, j);
                pat_true[j] = true;
                if (!pattern[j])
                    sum++;
            }
            cout << sum << endl;
        }
        if (q == 1)
        {
            int sum = 0;
            for (int j = 1; j <= n; j++)
            {
                if (!pat_true[j])
                {
                    pat_true[j] = true;
                    pattern[j] = search(i, j);
                }
            }
            for (int j = 1; j <= n; j++)
            {
                if (pattern[j] != 0 && pattern[pattern[j]] == j)
                {
                    sum++;
                }
            }
            cout << sum / 2 << endl;
        }
    }
    return 0;
}