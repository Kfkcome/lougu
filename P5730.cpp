#include <bits/stdc++.h>
using namespace std;
int screen[5][500];
void insertNum(int num, int screen[][500], int n /*显示屏上第几个数*/)
{
    n = (n - 1) * 3 + n;
    switch (num)
    {
    case 0:
        for (int i = 0; i < 5; i++)
        {
            screen[i][n - 1] = 1;
            screen[i][n + 1] = 1;
        }
        screen[0][n] = 1;
        screen[4][n] = 1;
        break;
    case 1:
        for (int i = 0; i < 5; i++)
        {
            screen[i][n + 1] = 1;
        }
        break;
    case 2:
        for (int i = 0; i < 3; i++)
        {
            screen[0][n - 1 + i] = 1;
            screen[2][n - 1 + i] = 1;
            screen[4][n - 1 + i] = 1;
        }
        screen[1][n + 1] = 1;
        screen[3][n - 1] = 1;
        break;
    case 3:
        for (int i = 0; i < 3; i++)
        {
            screen[0][n - 1 + i] = 1;
            screen[2][n - 1 + i] = 1;
            screen[4][n - 1 + i] = 1;
        }
        screen[1][n + 1] = 1;
        screen[3][n + 1] = 1;
        break;
    case 4:
        for (int i = 0; i < 3; i++)
        {
            screen[i][n - 1] = 1;
        }
        for (int i = 0; i < 5; i++)
        {
            screen[i][n + 1] = 1;
        }
        screen[2][n] = 1;
        break;
    case 5:
        for (int i = 0; i < 3; i++)
        {
            screen[0][n - 1 + i] = 1;
            screen[2][n - 1 + i] = 1;
            screen[4][n - 1 + i] = 1;
        }
        screen[1][n - 1] = 1;
        screen[3][n + 1] = 1;
        break;
    case 6:
        for (int i = 0; i < 5; i++)
        {
            screen[i][n - 1] = 1;
            screen[i][n + 1] = 1;
        }
        screen[0][n] = 1;
        screen[4][n] = 1;
        screen[2][n] = 1;
        screen[1][n + 1] = 0;
        break;
    case 7:
        for (int i = 0; i < 5; i++)
        {
            screen[i][n + 1] = 1;
        }
        screen[0][n - 1] = 1;
        screen[0][n] = 1;
        break;
    case 8:
        for (int i = 0; i < 5; i++)
        {
            screen[i][n - 1] = 1;
            screen[i][n + 1] = 1;
        }
        screen[0][n] = 1;
        screen[4][n] = 1;
        screen[2][n] = 1;
        break;
    case 9:
        for (int i = 0; i < 5; i++)
        {
            screen[i][n - 1] = 1;
            screen[i][n + 1] = 1;
        }
        screen[0][n] = 1;
        screen[4][n] = 1;
        screen[2][n] = 1;
        screen[3][n - 1] = 0;
        break;
    default:
        break;
    }
}
void showScreen(int n, int screen[][500])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < n * 3 + n - 1; j++)
        {
            if (screen[i][j] == 1)
            {
                cout << "X";
            }
            else
                cout << ".";
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    char *a = new char[n];
    cin >> a;
    for (int i = 0; i < n; i++)
    {
        int num = a[i] - '0';
        insertNum(num, screen, i + 1);
    }
    showScreen(n, screen);
    return 0;
}