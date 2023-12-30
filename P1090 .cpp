#include <bits/stdc++.h>
using namespace std;
int n, ans;
int weight[10001];
priority_queue<int, vector<int>, greater<int>> q;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
        q.push(weight[i]);
    }
    list<int>::iterator it;
    while (q.size() > 1)
    {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        ans += a + b;
        q.push(a + b);
    }
    cout<<ans;
    return 0;
}