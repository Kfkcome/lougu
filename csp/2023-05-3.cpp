#include <bits/stdc++.h>
using namespace std;
int s;
string temp[5000000];
int pos = 0;
string allData = "";
int hexToDec(string a) // 十六进制转十进制
{
    int num = 0;
    for (int i = 0; i < a.size(); i++)
    {
        int t;
        if (a[i] >= '0' && a[i] <= '9')
        {
            t = a[i] - '0';
        }
        else
            t = a[i] - 'a' + 10;
        num *= 16;
        num += t;
    }
    return num;
}
void addToData(int len) // 把压缩的数据插入到解压缩数据中
{
    len = len * 2;
    int end = pos + len;
    for (; pos < end; pos++)
    {
        allData.push_back(temp[pos / 16][pos % 16]);
    }
}
int main()
{
    cin >> s;
    getchar();
    int end = s / 8;
    if (s % 8 == 0)
        end--;
    for (int i = 0; i <= end; i++)
    {
        getline(cin, temp[i]);
    }
    int len = 0;
    int base = 1;
    for (int i = 0; i < 4; i++)
    {
        int num = hexToDec(string(temp[0].begin() + i * 2, temp[0].begin() + i * 2 + 2));
        len += base * (num % 128);
        base *= 128;
        pos += 2;
        if (num<128)
        {
            break;
        }
    }
    while (pos < s * 2)
    {
        // 字符串切片操作
        string type = string(temp[pos / 16].begin() + pos % 16, temp[pos / 16].begin() + pos % 16 + 2);
        pos += 2;
        int t = hexToDec(type);
        if (t % 4 == 3) // 不合法
        {
            break;
        }
        else if (t % 4 == 0) // 字面量
        {
            int length = t / 4;
            if (length < 60)
            {
                addToData(length + 1);
            }
            else
            {
                string l = "";
                for (int i = length - 59 - 1; i >= 0; i--)
                {
                    l.push_back(temp[(pos + i * 2) / 16][(pos + i * 2) % 16]);
                    l.push_back(temp[(pos + i * 2 + 1) / 16][(pos + i * 2 + 1) % 16]);
                }
                pos += (length - 59) * 2;
                length = hexToDec(l);  // 将十六进制字符串转化为十进制
                addToData(length + 1); // 插入到解压缩数据中
            }
        }
        else // 回溯索引
        {
            int o, l;
            if (t % 4 == 1)
            {
                // 高三位和后一个字节
                o = (t / 32) * 256 + hexToDec(string(temp[pos / 16].begin() + pos % 16, temp[pos / 16].begin() + pos % 16 + 2));
                pos += 2;
                l = (t / 4) % 8 + 4; // 中间三位 再加4
            }
            else if (t % 4 == 2)
            {
                l = t / 4 + 1;
                // 往后读取两个字节作为o
                o = hexToDec(string(temp[pos / 16].begin() + pos % 16, temp[pos / 16].begin() + pos % 16 + 2));
                pos += 2;
                o += hexToDec(string(temp[pos / 16].begin() + pos % 16, temp[pos / 16].begin() + pos % 16 + 2)) * 256;
                pos += 2;
            }
            // 得到o和l之后添加到解压缩数据中
            if (o >= l)
            {
                allData += string(allData.end() - o * 2, allData.end() - o * 2 + l * 2);
            }
            else if (o < l)
            {
                string t1 = string(allData.end() - o * 2, allData.end());
                for (int i = 0; i < l * 2; i++)
                {
                    allData.push_back(t1[i % t1.size()]);
                }
            }
        }
    }
    for (int i = 0; i < allData.size(); i++)
    {
        if (i != 0 && i % 16 == 0)
        {
            cout << endl;
        }
        cout << allData[i];
    }
    return 0;
}
