#include <bits/stdc++.h>
using namespace std;
int n;
string word[21], start;
int max_length;
int times[21];
int mat(string x, string y)
{
    for (int s1 = x.length() - 1; s1 >= 0; s1--)
    {
        bool flag = true;
        for (int s2 = s1; s2 < x.length(); s2++)
        {
            if (s2 - s1 >= y.length() || x[s2] != y[s2 - s1])
            {
                flag = false;
                break;
            }
        }
        if (x.length() != 1 && s1 == 0) // 不让y包含x
        {
            continue;
        }
        if (x.length() - s1 == y.length())
        {
            continue;
        }
        if (flag)
        {
            return s1;
        }
    }
    return -1;
}
void dfs(string head)
{
    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        if (times[i] >= 2)
        {
            continue;
        }
        int pol = mat(head, word[i]);
        if (pol != -1)
        {
            flag = true;
            string back_head = head;
            head += word[i].substr(head.length() - pol);
            times[i]++;
            max_length = max(max_length, (int)head.length());
            dfs(head);
            // 恢复状态
            times[i]--;
            head = back_head;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> word[i];
    }
    cin >> start;
    dfs(start);
    cout << max_length;
    return 0;
}