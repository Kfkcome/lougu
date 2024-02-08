#include <bits/stdc++.h>
using namespace std;
int n, m, sum;
struct node
{
    int p, a;
};
bool cmp(node a, node b)
{
    return a.p < b.p;
}
struct node people[5001];
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> people[i].p >> people[i].a;
    }
    sort(people, people + m, cmp);
    for (int i = 0; i < m; i++)
    {
        if (n > people[i].a)
        {
            n -= people[i].a;
            sum += people[i].p * people[i].a;
        }
        else
        {
            sum += n * people[i].p;
            break;
        }
    }
    cout<<sum;
    return 0;
}