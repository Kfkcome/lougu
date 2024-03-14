#include <bits/stdc++.h>
using namespace std;
int n;
int a[500001];
map<int, vector<int>> mp1; // value 对应的位置有哪些
int main()
{
    cin >> n;
    bool zero = true;
    int max_range = 0;
    int temp_num = 0;
    // 输入并且计算非零段的数目的初值
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] != 0)
            mp1[a[i]].push_back(i);
        if (a[i] == 0)
            zero = true;
        if (a[i] != 0)
        {
            if (zero == true)
                temp_num++;
            zero = false;
        }
    }
    max_range = temp_num;
    for (auto item : mp1)
    {
        for (auto x : item.second)
        {
            if (x > 0 && x < n - 1)
            {
                if (a[x - 1] != 0 && a[x + 1] != 0)
                {
                    temp_num++;
                }
                else if (a[x - 1] == 0 && a[x + 1] == 0)
                {
                    temp_num--;
                }
            }
            if (x == 0 && a[x + 1] == 0)
            {
                temp_num--;
            }
            if (x == n - 1 && a[x - 1] == 0)
            {
                temp_num--;
            }
            a[x] = 0;
        }
        max_range = max(max_range, temp_num);
    }
    cout << max_range << endl;
    return 0;
}