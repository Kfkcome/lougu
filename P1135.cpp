#include <bits/stdc++.h>
using namespace std;
int N, A, B;
int K[201];
int step[201];
struct level
{
    int i; // 表示第i层
    int j; // 表示j步
};
queue<level> q;
int main()
{
    cin >> N >> A >> B;
    for (int i = 1; i <= N; i++)
    {
        cin >> K[i];
    }
    struct level temp;
    q.push((level){A, 0});
    if (A == B)
    {
        cout << 0;
        return 0;
    }
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (step[temp.i + K[temp.i]] == 0 && K[temp.i] + temp.i <= N)
        {
            step[temp.i + K[temp.i]] = temp.j + 1;
            if (temp.i + K[temp.i] == B)
            {
                cout << temp.j + 1;
                return 0;
            }
            q.push((level){temp.i + K[temp.i], temp.j + 1});
        }
        if (step[temp.i - K[temp.i]] == 0 && temp.i - K[temp.i] >= 1)
        {
            step[temp.i - K[temp.i]] = temp.j + 1;
            if (temp.i - K[temp.i] == B)
            {
                cout << temp.j + 1;
                return 0;
            }
            q.push((level){temp.i - K[temp.i], temp.j + 1});
        }
    }
    cout << -1;
    return 0;
}