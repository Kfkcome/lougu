#include <bits/stdc++.h>
using namespace std;
long num[200000];
long n, c, sum;
int binSearch(int x, int l, int r)
{
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (num[mid] >= x)
        {
            r = mid;
        }
        else
            l = mid + 1;
    }
    if (x == num[r])
        return l;
    return -1;
}
int binSearch2(int x, int l, int r)
{
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (num[mid] <= x)
        {
            l = mid;
        }
        else
            r = mid - 1;
    }
    if (x == num[r])
        return r;
    return -1;
}
int main()
{
    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    sort(num, num + n);
    for (int i = 0; i < n - 1; i++)
    {
        long A = c + num[i];
        int locat1 = binSearch(A, i + 1, n - 1);
        int locat2 = binSearch2(A, i + 1, n - 1);
        if (locat1 == -1)
            continue;
        sum += locat2 - locat1 + 1;
    }
    cout << sum << endl;
}