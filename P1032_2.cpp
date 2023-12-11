#include <bits/stdc++.h>
using namespace std;
string a, b;
struct rule
{
    string origin, change;
};
struct rule rules[7];
int len;
struct result
{
    string r;
    int step;
};
map<string, bool> m3;
queue<result> q;
int num;
int main()
{
    cin >> a >> b;
    getchar();
    while (cin >> rules[len].origin >> rules[len].change)
    {
        len++;
    }
    m3[a] = true;
    q.push((result){a, 0});
    struct result temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp.step > 10)
        {
            break;
        }
        for (int k = 0; k < len; k++)
        {
            string right, left;
            int v=0;
			while(temp.r.find(rules[k].origin,v)!=-1)//被坑了，不能只找一次，可能有多个相同的子串……应在找到一个后往后面继续找
			{
				string w=temp.r;
				int m=w.find(rules[k].origin,v);
				w.replace(m,rules[k].origin.size(),rules[k].change);
                if(w==b){
                    cout<<temp.step+1;
                    return 0;
                }
				if(m3[w]==0)//哈希表，不开最后一个点MLE
					q.push((result){w,temp.step+1}),m3[w]=1;
				v=m+rules[k].origin.size();//记录继续查找的位置
			}
        }
    }
    cout << "NO ANSWER!";
    return 0;
}