#include <bits/stdc++.h>
using namespace std;
int s, w;
string init;
vector<int> numbers;
vector<int> code_word;
void convert_state(int &state, char a)
{
    int to_state = 0;
    if (a >= '0' && a <= '9')
        to_state = 2;
    if (a <= 'Z' && a >= 'A')
        to_state = 3;
    if (a <= 'z' && a >= 'a')
        to_state = 1;
    if (to_state == state) // 如果当前字母和当前状态一样
        return;
    else // 如果不相同
    {
        if (state == 1)
        {
            if (to_state == 2)
                numbers.push_back(28);
            if (to_state == 3)
            {
                numbers.push_back(28);
                numbers.push_back(28);
            }
        }
        if (state == 2)
        {
            if (to_state == 1)
                numbers.push_back(27);
            if (to_state == 3)
                numbers.push_back(28);
        }
        if (state == 3)
        {
            if (to_state == 1)
                numbers.push_back(27);
            if (to_state == 2)
                numbers.push_back(28);
        }
    }
    state = to_state;
}
int main()
{
    cin >> w >> s;
    cin >> init;
    const int begin_num[4] = {0, 'a', '0', 'A'};
    int state = 3; // 如果 state=1 小写 state=2 数字 state=3 大写
    for (int i = 0; i < init.size(); i++)
    {
        convert_state(state, init[i]);
        numbers.push_back(init[i] - begin_num[state]);
    }

    if (numbers.size() % 2 == 1) // 如果是奇数
    {
        numbers.push_back(29);
    }
    code_word.push_back(0); // 先增加一个长度位
    for (int i = 0; i < numbers.size(); i += 2)
    {
        code_word.push_back(30 * numbers[i] + numbers[i + 1]);
    }

    int k = -1;
    if (s != -1)
    {
        k = 1;
        for (int i = 0; i < s + 1; i++)
        {
            k *= 2;
        }
    }
    if ((code_word.size() + max(0, k)) % w != 0)
    {
        int add_num = w - (code_word.size() + max(0, k)) % w;
        while (add_num > 0)
        {
            code_word.push_back(900);
            add_num--;
        }
    }
    code_word[0] = code_word.size();
    // 计算校验字
    // 模拟多项式除法
    int g[513]; // g(x)的系数
    int d[930]; // d(x)的系数
    // 初始化g(x)
    for (int i = 0; i <= k; i++)
    {
        g[i]=
    }
    for (int i = 0; i < code_word[0]; i++)
    {
    }
    for (int i = 0; i < code_word.size(); i++)
    {
        cout << code_word[i] << endl;
    }
    return 0;
}