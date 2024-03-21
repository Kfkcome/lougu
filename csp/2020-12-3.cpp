#include <bits/stdc++.h>
using namespace std;
struct file
{
    string name;
    int size;

    int dir_limit;
    int child_limit;
    int type = -1; // 0是普通文件 1是目录文件
    int to_paths;  // 用于寻找文件内的索引
} f[100001];
long long top;
map<int, vector<int>> paths;
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
    res.push_back(temp);
    return res;
}
int find_file_from_dir(int dir, string name) // 返回文件位置
{
    vector<int> temp = paths[f[dir].to_paths];
    for (int i = 0; i < temp.size(); i++)
    {
        if (name == f[temp[i]].name)
        {
            return temp[i];
        }
    }
    return -1;
}
bool deal_creat(string file_path, int file_size) // 创建普通文件
{
    vector<string> path = convert_string_path(file_path);
    vector<int> real_path;
    int dir = 0; // 先从根目录开始
    for (int i = 0; i < path.size(); i++)
    {
        int file_locate = find_file_from_dir(dir, path[i]);
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
                    real_path.push_back(file_locate);
                }
            }
            else // 如果要创建目录
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
    dir = 0;
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
        }
        dir = f[real_path[i]].to_paths;
    }
    return true;
}
bool deal_remove(string file_path)
{
    vector<string> path = convert_string_path(file_path);
    vector<int> real_path;
    real_path.push_back(0); // 把根目录添加
    int dir = 0;
    for (int i = 0; i < path.size(); i++)
    {
        int file_locate = find_file_from_dir(dir, path[i]);
        if (file_locate == -1)
        {
            return true;
        }
        real_path.push_back(file_locate);
        dir = file_locate;
    }
    dir = 0;
    int file_locate = f[real_path[real_path.size() - 2]].to_paths;
    vector<int> temp = paths[file_locate];
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
    }
    return true;
}
int main()
{
    freopen("1.txt", "r", stdin);
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
            int file_size;
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
    }
    return 0;
}