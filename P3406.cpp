#include <bits/stdc++.h>
using namespace std;
int N, M;
int P[1000];
int way[1003];
struct tickts
{
    int a, b, c;
};
struct tickts t[1001];
int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> P[i];
    }
    for (int i = 1; i <= N - 1; i++)
    {
        cin >> t[i].a >> t[i].b >> t[i].c;
    }
    for (int i = 0; i < M; i++)
    {
        int start = min(P[i], P[i + 1]);
        int end = max(P[i], P[i + 1]);
        way[start]++;
        way[end]--;
    }
    int sum = 0;
    for (int i = 1; i <= N - 1; i++)
    {
        way[i] = way[i] + way[i - 1];
        sum += min(way[i] * t[i-1].a, way[i] * t[i-1].b + t[i-1].c);
    }
    cout << sum;
    return 0;
}
