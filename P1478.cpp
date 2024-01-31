#include <bits/stdc++.h>
using namespace std;
int n, s, a, b, sum;
struct apple
{
    bool get = false;
    int x, y;
} apples[5005];
int main()
{
    cin >> n >> s >> a >> b;
    for (int i = 0; i < n; i++)
        cin >> apples[i].x >> apples[i].y;
    while (s > 0)
    {
        int min = 0x7fffffff, min_index = -1;
        for (int i = 0; i < n; i++)
        {
            if (apples[i].x <= a + b && apples[i].y < min && apples[i].y <= s && apples[i].get == false)
            {
                min = apples[i].y;
                min_index = i;
            }
        }
        if (min_index == -1)
            break;
        else
        {
            apples[min_index].get = true;
            sum++;
            s -= apples[min_index].y;
        }
    }
    cout << sum << endl;

    return 0;
}