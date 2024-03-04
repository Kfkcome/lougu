#include <bits/stdc++.h>
using namespace std;
const double pi8 = acos(-1) / 8;
int n, data1[65], top;
int q[8][8], m[8][8]; // 量化矩阵和数据矩阵
int T;
void insertMatrix()
{
    // 首先插入上半个矩阵
    int x = 0, y = 0, moveflag = 1; // moveflag如果是右移 则是1 如果是下移则是0
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            m[x][y] = data1[top++];

            if (top == n) // 已经把所有数据都插入了
            {
                return;
            }
            if (j != i && moveflag == 1)
            {
                x--;
                y++;
            }
            else if (j != i && moveflag == 0)
            {
                x++;
                y--;
            }
        }
        if (moveflag == 1) // 如果是右移
        {
            y++;
        }
        else if (moveflag == 0)
        {
            x++;
        }
        moveflag = !moveflag;
    }

    moveflag = 0;
    x = 7, y = 1;
    // 然后插入下半个矩阵
    for (int i = 7; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            m[x][y] = data1[top++];
            if (top == n) // 已经把所有数据都插入了
            {
                return;
            }
            if (j != i && moveflag == 1)
            {
                x++;
                y--;
            }
            else if (j != i && moveflag == 0)
            {
                x--;
                y++;
            }
        }
        if (moveflag == 1) // 如果是右移
        {
            y++;
        }
        else if (moveflag == 0) // 如果是下移
        {
            x++;
        }
        moveflag = !moveflag;
    }
}
void multipleMatrix()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            m[i][j] *= q[i][j];
        }
    }
}
double DctConvert(int x, int y)
{
    double sum = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            double a1 = i == 0 ? sqrt(0.5) : 1, a2 = j == 0 ? sqrt(0.5) : 1;
            sum += a1 * a2 * m[i][j] * cos(pi8 * (x + 0.5) * i) * cos(pi8 * (y + 0.5) * j);
        }
    }
    return sum / 4;
}
void addAll(double matr[8][8])
{

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            m[i][j] = (int)(matr[i][j] + 128 + 0.5);
            if (m[i][j] > 255)
            {
                m[i][j] = 255;
            }
            else if (m[i][j] < 0)
            {
                m[i][j] = 0;
            }
        }
    }
}
void show(int martrix[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << martrix[i][j] << ' ';
        }
        cout << endl;
    }
}
void show(double martrix[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << martrix[i][j] << ' ';
        }
        cout << endl;
    }
}
int main()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> q[i][j];
        }
    }
    cin >> n;
    cin >> T;
    for (int i = 0; i < n; i++)
    {
        cin >> data1[i];
    }
    if (T == 0)
    {
        insertMatrix();
    }
    else if (T == 1)
    {
        insertMatrix();
        multipleMatrix();
    }
    else if (T == 2)
    {
        insertMatrix();
        multipleMatrix();
        double m2[8][8];
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                m2[i][j] = DctConvert(i, j);
            }
        }
        addAll(m2);
    }
    show(m);
    return 0;
}
