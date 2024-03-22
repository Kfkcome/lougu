#include <bits/stdc++.h>
using namespace std;
struct dfile
{
    long long size;
    long long dir_size = 0;
    long long child_size = 0;
    long long dir_limit = 0;
    long long child_limit = 0;
    int type = -1; // 0是普通文件 1是目录文件
    map<string, struct dfile *> child;
    dfile(int t) : type(t) {}
};
struct dfile root(1);
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
bool deal_creat(string file_path, long long file_size) // 创建普通文件
{
    vector<string> path = convert_string_path(file_path);
    bool exist = false; // 这个文件是不是已经存在

    struct dfile *p = &root;
    vector<struct dfile *> fs;
    fs.push_back(p);
    bool newdir = false; // 记录有没有新的文件夹产生
    // 检查目录是不是被文件占用
    for (int i = 0; i < path.size() - 1; i++)
    {
        if (p->child.count(path[i]))
        {
            // 找到了文件看看是不是目录
            struct dfile *temp = p->child[path[i]];
            if (temp->type == 0) // 如果是普通文件
                return false;
            p = temp;
            fs.push_back(p);
        }
        else
            newdir = true;
    }
    // 文件名是不是被目录占用
    // 只有没有新建文件夹的时候才检查
    if (!newdir)
    {
        struct dfile *last = fs.back();
        if (last->child.count(path.back()))
        {
            if (last->child[path.back()]->type == 1)
                return false;
            exist = true;
            fs.push_back(last->child[path.back()]);
        }
        else
        {
            fs.push_back(new dfile(0));
        }
    }
    // 判断大小限制是不是符合
    long long t_file_size = file_size;
    if (exist)
        t_file_size = file_size - fs.back()->size;

    for (int i = 0; i < fs.size(); i++)
    {
        if (fs[i]->type == 1 && fs[i]->child_limit && fs[i]->child_size + t_file_size > fs[i]->child_limit)
            return false;
        if (fs[i]->type == 1 && !newdir && fs[i]->dir_limit && i == fs.size() - 2 && fs[i]->dir_size + t_file_size > fs[i]->dir_limit)
            return false;
    }

    // 给路径上的文件夹增加大小
    fs[0]->child_size += t_file_size;
    if (path.size() == 1)
        fs[0]->dir_size += t_file_size;
    for (int i = 0; i < path.size(); i++)
    {
        if (i >= fs.size() - 1) // 还未创建
        {
            struct dfile *temp = new dfile(1);
            if (i == path.size() - 1)
            {
                temp->size = file_size;
                temp->type = 0;
            }
            else
            {
                temp->child_size += t_file_size;
                temp->dir_size += i == path.size() - 2 ? t_file_size : 0;
                temp->type = 1;
            }
            // 建立索引
            fs.back()->child[path[i]] = temp;
            fs.push_back(temp);
        }
        else // 如果已经创建了
        {
            if (i == path.size() - 1)
            {
                fs[i + 1]->size = file_size;
                fs[i]->child[path[i]] = fs[i + 1];
            }
            else
            {
                fs[i + 1]->child_size += t_file_size;
                fs[i + 1]->dir_size += i == path.size() - 2 ? t_file_size : 0;
            }
        }
    }
    return true;
}
bool deal_remove(string file_path)
{
    vector<string> path = convert_string_path(file_path);
    vector<struct dfile *> fs;
    fs.push_back(&root);

    // 判断路径存不存在
    struct dfile *p = &root;
    for (int i = 0; i < path.size(); i++)
    {
        if (!p->child.count(path[i]))
            return true;
        p = p->child[path[i]];
        fs.push_back(p);
    }

    // 删去索引
    fs[fs.size() - 2]->child.erase(path.back());
    // 删除占用
    int type = fs.back()->type;
    if (type == 1) // 如果是文件夹
    {
        // 删除文件夹占用
        long long file_size = fs.back()->child_size;
        for (int i = 0; i < fs.size() - 1; i++)
        {
            fs[i]->child_size -= file_size;
        }
    }
    else
    {
        // 删除文件占用
        long long file_size = fs.back()->size;
        for (int i = 0; i < fs.size() - 1; i++)
        {
            fs[i]->child_size -= file_size;
            if (i == fs.size() - 2)
                fs[i]->dir_size -= file_size;
        }
    }
    return true;
}
bool deal_q(string file_path, long long ld, long long lr)
{

    vector<string> path = convert_string_path(file_path);
    struct dfile *p = &root;
    vector<struct dfile *> fs;
    fs.push_back(p);
    for (int i = 0; i < path.size(); i++)
    {
        if (!p->child.count(path[i])) // 如果没有找到
            return false;
        if (p->child[path[i]]->type == 0) // 如果不是目录文件
            return false;
        p = p->child[path[i]];
        fs.push_back(p);
    }
    struct dfile *dir = fs.back();
    if (ld != 0) // 检查孩子文件的大小是不是超过限制了
    {
        if (dir->dir_size > ld)
            return false;
    }
    if (lr != 0) // 检查后代文件的总和是不是超过了限制
    {
        if (dir->child_size > lr)
            return false;
    }
    dir->child_limit = lr;
    dir->dir_limit = ld;
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    // freopen("1.txt", "r", stdin);
    int n;
    cin >> n;
    // 初始化根目录
    root.type = 1;

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