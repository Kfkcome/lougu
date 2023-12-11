#include <bits/stdc++.h>
using namespace std;
int n;
struct people
{
    /* data */
    int T;
    int pol;
};
bool cmp(struct people p, struct people p2)
{
    return p.T < p2.T;
}
struct people t[1001];
long sum;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t[i].T;
        t[i].pol = i + 1;
    }
    sort(t, t + n, cmp);
    int time = 0;
    for (int i = 0; i < n - 1; i++)
    {
        cout << t[i].pol << ' ';
        time += t[i].T;
        sum = time + sum;
    }
    cout << t[n - 1].pol;
    // cout << endl
    //      << sum / (n * 1.0);
    printf("\n%.2f", sum / (n * 1.0));
    return 0;
}