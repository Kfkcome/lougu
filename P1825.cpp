#include <bits/stdc++.h>
using namespace std;
int N, M;
char place[301][301];
int start_i, start_j, end_i, end_j;
bool dfs(int count)
{

}
int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> place[i][j];
            if (place[i][j] == '@')
            {
                start_i = i;
                start_j = j;
            }
            if (place[i][j] == '=')
            {
                end_i = i;
                end_j = j;
            }
        }
    }
    cout << dfs(0)

            return 0;
}