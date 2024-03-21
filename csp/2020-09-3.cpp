#include <bits/stdc++.h>
using namespace std;
struct device
{
    string func;
    vector<int> input; // 输入
    int output;        // 输出结果
} d[501];
int M, N;
map<int, vector<int>> im;
int in[501];
int I[10001][2501];
int links[501][501];
void reset()
{
    memset(links, 0, sizeof(links));
    memset(in, 0, sizeof(in));
    im.clear();
    for (int i = 1; i <= N; i++)
    {
        d[i].input.clear();
    }
}
bool check(bool used[501], int temp_in[501])
{
    for (int i = 1; i <= N; i++)
    {
        if (!used[i])
            return true;
    }
    return false;
}
void run_one(int pos, bool used[501], int temp_in[501])
{
    used[pos] = true;
    if (d[pos].func == "NOT")
    {
        d[pos].output = !(d[pos].input[0]);
    }
    else if (d[pos].func == "AND")
    {
        d[pos].output = d[pos].input[0];
        for (int i = 1; i < d[pos].input.size(); i++)
        {
            d[pos].output = (d[pos].output & d[pos].input[i]);
        }
    }
    else if (d[pos].func == "OR")
    {
        d[pos].output = d[pos].input[0];
        for (int i = 1; i < d[pos].input.size(); i++)
        {
            d[pos].output = (d[pos].output | d[pos].input[i]);
        }
    }
    else if (d[pos].func == "XOR")
    {
        d[pos].output = d[pos].input[0];
        for (int i = 1; i < d[pos].input.size(); i++)
        {
            d[pos].output = (d[pos].output ^ d[pos].input[i]);
        }
    }
    else if (d[pos].func == "NAND")
    {
        d[pos].output = d[pos].input[0];
        for (int i = 1; i < d[pos].input.size(); i++)
        {
            d[pos].output = (d[pos].output & d[pos].input[i]);
        }
        d[pos].output = !(d[pos].output);
    }
    else if (d[pos].func == "NOR")
    {
        d[pos].output = d[pos].input[0];
        for (int i = 1; i < d[pos].input.size(); i++)
        {
            d[pos].output = (d[pos].output | d[pos].input[i]);
        }
        d[pos].output = !(d[pos].output);
    }

    // 将结果传送
    for (int i = 1; i <= N; i++)
    {
        if (links[pos][i])
        {
            d[i].input.push_back(d[pos].output);
            temp_in[i]--;
        }
    }
}
bool run_device(int I[2501], int si, int snum[501])
{
    bool used[501];
    int temp_in[501];
    copy(begin(in), end(in), begin(temp_in));
    memset(used, 0, sizeof(used));
    for (int i = 1; i <= M; i++)
    {
        for (auto item : im[i])
        {
            d[item].input.push_back(I[i]);
        }
    }
    while (check(used, temp_in)) // 这里应该处理有环的情况
    {
        bool flag = false;
        for (int i = 1; i <= N; i++)
        {
            if (!used[i] && temp_in[i] == 0)
            {
                flag = true;
                run_one(i, used, temp_in);
            }
        }
        if (!flag)
        {
            cout << "LOOP" << endl;
            return false;
        }
    }
    for (int i = 1; i <= si; i++)
    {
        cout << d[snum[i]].output << ' ';
    }
    cout << endl;
    return true;
}

int main()
{
    // freopen("1.txt", "r", stdin);
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {

        cin >> M >> N;
        for (int j = 1; j <= N; j++)
        {
            cin >> d[j].func;
            int k;
            cin >> k;
            for (int z = 0; z < k; z++)
            {
                string temp;
                cin >> temp;
                int num = stoi(string(temp.begin() + 1, temp.end()));
                if (temp[0] == 'I')
                {
                    im[num].push_back(j);
                }
                else if (temp[0] == 'O')
                {
                    links[num][j] = 1;
                    in[j]++;
                }
            }
        }
        int S;
        cin >> S;
        for (int i = 1; i <= S; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                int temp;
                cin >> temp;
                I[i][j] = temp;
            }
        }
        bool flag = true;
        for (int i = 1; i <= S; i++)
        {
            int s;
            cin >> s;
            int snum[501];
            for (int j = 1; j <= s; j++)
            {
                int temp;
                cin >> temp;
                snum[j] = temp;
            }
            if (flag)
            {
                flag = run_device(I[i], s, snum);
            }
            for (int j = 1; j <= N; j++)
            {
                d[j].input.clear(); // 清楚保存的数据
            }
        }
        reset();
    }

    return 0;
}