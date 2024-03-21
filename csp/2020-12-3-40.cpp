#include <bits/stdc++.h>
using namespace std;
struct file
{
    string name;
    long long size;

    long long dir_size;
    long long child_size;
    long long dir_limit;
    long long child_limit;
    int type = -1; // 0是普通文件 1是目录文件
    int to_paths;  // 用于寻找文件内的索引
} f[2000001];
long long top;
map<long long, vector<long long>> paths;
long long indexes; // 提供一个不重复的索引
vector<string> convert_string_path(string file_path)
{
    vector<string> res;
    string temp = "";
    for (int i = 1; i < file_path.size(); i++)
    {
        if (file_path[i] != '/')
        {
            temp += file_path[i];
        }
        else
        {
            res.push_back(temp);
            temp.clear();
        }
    }
    if (!temp.empty())
        res.push_back(temp);
    return res;
}
int find_file_from_dir(long long dir, string name) // 返回文件位置
{
    vector<long long> temp = paths[f[dir].to_paths];
    for (int i = 0; i < temp.size(); i++)
    {
        if (name == f[temp[i]].name)
        {
            return temp[i];
        }
    }
    return -1;
}
bool deal_creat(string file_path, long long file_size) // 创建普通文件
{
    vector<string> path = convert_string_path(file_path);
    vector<long long> real_path;
    bool exist = false; // 这个文件是不是已经存在

    if (f[0].child_limit && f[0].child_size + file_size > f[0].child_limit)
        return false;
    if (f[0].dir_limit && path.size() == 1 && f[0].dir_size + file_size > f[0].dir_limit)
        return false;

    long long dir = 0; // 先从根目录开始
    for (int i = 0; i < path.size(); i++)
    {
        long long file_locate = find_file_from_dir(dir, path[i]);
        if (file_locate == -1)
        {
            // 先申请一个目录的位置
            dir = top;
            real_path.push_back(top++);
        }
        else
        {
            if (i == path.size() - 1) // 如果是最后一个 则是文件不是目录
            {
                if (f[file_locate].type == 1)
                {
                    return false;
                }
                else // 替换这个文件
                {
                    exist = true;
                    real_path.push_back(file_locate);
                }
            }
            else // 找到了文件看看是不是目录
            {
                if (f[file_locate].type == 0) // 如果是普通文件
                {
                    return false;
                }
                else // 如果该目录存在
                {
                    real_path.push_back(file_locate);
                    dir = file_locate;
                }
            }
        }
    }
    long long t_file_size = file_size;
    if (exist)
        t_file_size = file_size - f[real_path[real_path.size() - 1]].size;
    for (int i = 0; i < real_path.size() - 1; i++)
    {
        if (f[real_path[i]].child_limit && f[real_path[i]].child_size + t_file_size > f[real_path[i]].child_limit)
            return false;
        if (f[real_path[i]].dir_limit && i == real_path.size() - 2 && f[real_path[i]].dir_size + t_file_size > f[real_path[i]].dir_limit)
            return false;
    }
    dir = 0;
    if (path.size() == 1)
        f[0].dir_size += t_file_size;
    f[0].child_size += t_file_size;
    for (int i = 0; i < path.size(); i++)
    {
        if (f[real_path[i]].type == -1) // 还未创建
        {
            f[real_path[i]].name = path[i];
            if (i == path.size() - 1)
            {
                f[real_path[i]].size = file_size;
                f[real_path[i]].type = 0;
            }
            else
            {
                f[real_path[i]].child_size += t_file_size;
                f[real_path[i]].dir_size += i == path.size() - 2 ? t_file_size : 0;

                f[real_path[i]].to_paths = indexes++; // 为这个文件构建索引
                f[real_path[i]].type = 1;
            }
            // 建立索引
            paths[dir].push_back(real_path[i]);
        }
        else // 如果已经创建了
        {
            if (i == path.size() - 1)
            {
                f[real_path[i]].size = file_size;
            }
            else
            {
                f[real_path[i]].child_size += t_file_size;
                f[real_path[i]].dir_size += i == path.size() - 2 ? t_file_size : 0;
            }
        }
        dir = f[real_path[i]].to_paths;
    }
    return true;
}
bool deal_remove(string file_path)
{
    vector<string> path = convert_string_path(file_path);
    vector<long long> real_path;
    real_path.push_back(0); // 把根目录添加
    int dir = 0;
    for (int i = 0; i < path.size(); i++)
    {
        long long file_locate = find_file_from_dir(dir, path[i]);
        if (file_locate == -1)
        {
            return true;
        }
        real_path.push_back(file_locate);
        dir = file_locate;
    }

    // 删去索引
    int file_locate = f[real_path[real_path.size() - 2]].to_paths;
    vector<long long> temp = paths[file_locate];
    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i] == real_path[real_path.size() - 1])
        {
            paths[file_locate].erase(paths[file_locate].begin() + i);
            break;
        }
    }
    int type = f[real_path[real_path.size() - 1]].type;
    if (type == 1)
    {
        paths.erase(f[real_path[real_path.size() - 1]].to_paths);
        // 删除占用
        long long file_size = f[real_path[real_path.size() - 1]].child_size;
        for (int i = 0; i < real_path.size() - 1; i++)
        {
            f[real_path[i]].child_size -= file_size;
        }
    }
    else
    {
        // 删除占用
        long long file_size = f[real_path[real_path.size() - 1]].size;
        for (int i = 0; i < real_path.size() - 1; i++)
        {
            f[real_path[i]].child_size -= file_size;
            if (i == real_path.size() - 2)
                f[real_path[i]].dir_size -= file_size;
        }
    }
    return true;
}
long long get_sum_size(int dir)
{
    vector<long long> temp = paths[f[dir].to_paths];
    long long sum = 0;
    for (auto item : temp)
    {
        if (f[item].type == 0)
        {
            sum += f[item].size;
        }
        else if (f[item].type == 1)
        {
            sum += get_sum_size(item);
        }
    }
    return sum;
}
bool deal_q(string file_path, long long ld, long long lr)
{
    long long dir = 0;
    vector<string> path = convert_string_path(file_path);
    vector<long long> real_path;
    real_path.push_back(0);
    for (int i = 0; i < path.size(); i++)
    {
        long long file_locate = find_file_from_dir(dir, path[i]);
        if (file_locate == -1)
            return false;
        if (f[file_locate].type == 0) // 如果不是目录文件
            return false;
        real_path.push_back(file_locate);
        dir = file_locate;
    }
    long long pos = real_path[real_path.size() - 1];
    if (ld != 0) // 检查孩子文件的大小是不是超过限制了
    {
        vector<long long> temp = paths[f[pos].to_paths];
        long long sum = 0;
        for (int i = 0; i < temp.size(); i++)
        {
            if (f[temp[i]].type == 0)
            {
                sum += f[temp[i]].size;
            }
        }
        if (sum > ld) // 检查后代文件的总和是不是超过了限制
            return false;
    }
    if (lr != 0)
    {
        long long sum = get_sum_size(pos);
        if (sum > lr)
            return false;
    }
    f[pos].child_limit = lr;
    f[pos].dir_limit = ld;
    return true;
    // f[real_path[real_path.size() - 1]].child_limit
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    // freopen("1.txt", "r", stdin);
    int n;
    cin >> n;
    // 初始化根目录
    f[0].name = "";
    f[0].type = 1;
    f[0].to_paths = indexes++;
    top++;
    for (int i = 0; i < n; i++)
    {
        string type;
        cin >> type;
        if (type == "C")
        {
            string file_path;
            long long file_size;
            cin >> file_path >> file_size;
            if (deal_creat(file_path, file_size))
                cout << "Y" << endl;
            else
                cout << "N" << endl;
        }
        if (type == "R")
        {
            string file_path;
            cin >> file_path;
            if (deal_remove(file_path))
                cout << "Y" << endl;
        }
        if (type == "Q")
        {
            string file_path;
            long long ld, lr;
            cin >> file_path >> ld >> lr;
            if (deal_q(file_path, ld, lr))
                cout << "Y" << endl;
            else
                cout << "N" << endl;
        }
    }
    return 0;
}