#include <bits/stdc++.h>
using namespace std;
struct rule
{
    string origin, change;
};
struct rule rules[7];
string a, b;
int len;
string copyString(string a, int start, int end)
{
    string result;
    for (int i = start; i < end; i++)
    {
        result.push_back(a[i]);
    }
    return result;
}
int min_step = 1 << 30;
void dfs(string n, int s)
{
    if (s > min_step || s > 10)
    {
        return;
    }
    if (n == b)
    {
        min_step = min(min_step, s);
        return;
    }
    for (int k = 0; k < len; k++)
    {
        string right, left;
        for (int i = 0; i < n.length(); i++)
        {
            bool flag = true;
            for (int j = 0; j < rules[k].origin.length(); j++)
            {
                if (i + j >= n.length()||n[i + j] != rules[k].origin[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                for (int j = i + rules[k].origin.length(); j < n.length(); j++)
                {
                    left.push_back(n[j]);
                }
                dfs(right + rules[k].change + left, s + 1);
            }
            right.push_back(n[i]);
        }
    }
}
int main()
{

    cin >> a >> b;
    getchar();
    string temp;
    while(cin>>rules[len].origin>>rules[len].change){
        len++;
    }
    // while (getline(cin, temp) && temp != "")
    // {
    //     int end = temp.find(' ');
    //     rules[len].origin = copyString(temp, 0, end);
    //     end = temp.rfind(' ');
    //     rules[len].change = copyString(temp, end + 1, temp.length());
    //     len++;
    // }
    dfs(a, 0);
    if (min_step > 10)
    {
        cout << "NO ANSWER!";
    }
    else
        cout << min_step;
    return 0;
}