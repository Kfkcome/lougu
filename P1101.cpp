#include <bits/stdc++.h>
using namespace std;
int n;
string word = "yizhong";
int x_change[] = {1, 0, -1, 0, 1, -1, 1, -1};
int y_change[] = {0, 1, 0, -1, 1, -1, -1, 1};
string martx[105];
bool isword[101][101];
bool findword(int i, int j, int di, int dj, int next)
{
    if (next >= 7)
    {
        return true;
    }
    if (i + di >= 0 && i + di < n && j + dj >= 0 && j + dj < n && martx[i + di][j + dj] == word[next])
    {
        if (findword(i + di, j + dj, di, dj, next + 1))
        {
            isword[i + di][j + dj] = true;
            return 1;
        }
    }
    return 0;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> martx[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                findword(i - x_change[k], j - y_change[k], x_change[k], y_change[k], 0);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isword[i][j])
            {
                cout << martx[i][j];
            }
            else
                cout << "*";
        }
        cout << endl;
    }
    return 0;
}