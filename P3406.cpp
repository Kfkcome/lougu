#include <bits/stdc++.h>
using namespace std;
int N, M;
int P[100009];
long long  way[100009];
struct tickts
{
    int a, b, c;
};
struct tickts t[100009];
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
    for (int i = 0; i < M-1; i++)
    {
        int start = min(P[i], P[i + 1]);
        int end = max(P[i], P[i + 1]);
        way[start]++;
        way[end]--;
    }
    unsigned long long sum = 0;
    for (int i = 1; i <= N-1; i++)
    {
        way[i] = way[i] + way[i - 1];
        sum += min(way[i] * t[i].a, way[i] * t[i].b + t[i].c);
    }
    cout << sum;
    return 0;
}
