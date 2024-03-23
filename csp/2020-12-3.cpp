#include <bits/stdc++.h>
using namespace std;
struct dfile
{
    long long size = 0;
    long long dir_size = 0;    //
    long long child_size = 0;  // 后代大小
    long long dir_limit = 0;   // 目录配额
    long long child_limit = 0; // 孩子配额
    bool isDir = 0;            // 1是目录 0是文件
    map<string, struct dfile *> child;
    dfile(int t) : isDir(t) {}
};
struct dfile root(1);
vector<string> split(const string &s, const string &c = "")
{
    vector<string> res;
    for (long long i = 0, j = 0; i < s.size(); i = j + 1)
    {
        j = s.find(c, i);
        if (j == -1)
            j = s.size();
        res.push_back(s.substr(i, j - i));
    }
    return res;
}
int get_file_size(vector<string> path)
{
    struct dfile *p = &root;
    for (int i = 1; i < path.size() && p; i++)
    {
        p = p->child.count(path[i]) ? p->child[path[i]] : nullptr;
    }
    return p and !p->isDir ? p->size : 0;
}
bool can_create(vector<string> path, long long sz)
{
    struct dfile *p = &root;
    for (int i = 1; i < path.size() && p; i++)
    {
        // 向前判断判断i-1的时候的p 不会判断最后一个p（文件的指针）
        if (!p->isDir or (p->child_limit && p->child_size + sz > p->child_limit) or (i == path.size() - 1 && p->dir_limit && p->dir_size + sz > p->dir_limit))
            return false;
        p = p->child.count(path[i]) ? p->child[path[i]] : nullptr;
    }
    return !p or !p->isDir; // 如果没有文件、文件夹占用文件名 或者 是文件占用文件名
}
bool deal_creat(vector<string> path, long long file_size) // 创建普通文件
{
    int sz = file_size - get_file_size(path);

    if (!can_create(path, sz))
        return false;
    struct dfile *p = &root;
    for (int i = 1; i < path.size() - 1 /*剩下最后一个是文件*/; i++)
    {
        p->child_size += sz;
        if (!p->child.count(path[i]))
            p->child[path[i]] = new dfile(1);
        p = p->child[path[i]];
    }
    // p是文件的上一级
    p->child_size += sz, p->dir_size += sz;
    // 判断文件是不是存在
    if (!p->child.count(path.back()))
        p->child[path.back()] = new dfile(0);

    // 设置大小 注意这里不管是新建的还是覆盖的都是+=sz
    p->child[path.back()]->size += sz;
    return true;
}
bool deal_remove(vector<string> path)
{
    vector<struct dfile *> fs;
    fs.push_back(&root);

    // 判断路径存不存在
    struct dfile *p = &root;
    for (int i = 1; i < path.size(); i++)
    {
        if (!p->child.count(path[i]))
            return true;
        p = p->child[path[i]];
        fs.push_back(p);
    }

    // 删去索引
    fs[fs.size() - 2]->child.erase(path.back());
    // 删除占用
    bool type = fs.back()->isDir;
    if (type) // 如果是文件夹
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
bool deal_q(vector<string> path, long long ld, long long lr)
{
    struct dfile *p = &root;
    for (int i = 1; i < path.size(); i++)
    {
        if (!p->child.count(path[i])) // 如果没有找到
            return false;
        if (p->child[path[i]]->isDir == 0) // 如果不是目录文件
            return false;
        p = p->child[path[i]];
    }
    struct dfile *dir = p;
    if (ld && dir->dir_size > ld) // 检查孩子文件的大小是不是超过限制了
        return false;
    if (lr && dir->child_size > lr) // 检查后代文件的总和是不是超过了限制
        return false;
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

    for (int i = 0; i < n; i++)
    {
        string type, file_path;
        cin >> type >> file_path;
        vector<string> path = split(file_path, "/");
        if (type == "C")
        {
            long long file_size;
            cin >> file_size;
            cout << (deal_creat(path, file_size) ? "Y" : "N") << endl;
        }
        if (type == "R")
        {
            deal_remove(path);
            cout << "Y" << endl;
        }
        if (type == "Q")
        {
            long long ld, lr;
            cin >> ld >> lr;
            cout << (deal_q(path, ld, lr) ? "Y" : "N") << endl;
        }
    }
    return 0;
}