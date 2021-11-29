#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<math.h>
#include<set>
using namespace std;
#define INF 1e9
typedef long long ll;
int fa[105],n,cunt;
struct island
{
    int x,y;
}s[105];
struct Edge
{
    int s,e;///s记录起点，e记录终点
    double dis;///dis记录起点到终点的距离
}e[5555];
int cmp(Edge a,Edge b)
{
    return a.dis < b.dis;///按距离从小大大排列
}
int father(int x)///找父亲节点，用于判断是否在一个集合中
{
    if(x == fa[x]) return x;
    else
    {
        int root = father(fa[x]);
        fa[x] = root;
        return root;
    }
}
double Kruskal()
{
    for(int i = 1; i <= n; i++)
        fa[i] = i;
    sort(e,e+cunt,cmp);///按从小到大对边进行排序
    double ans = 0;
    int m = 0;
    for(int i = 0; i < cunt; i++)///遍历所有边
    {
        int a = father(e[i].s);
        int b = father(e[i].e);
        if(a != b && (e[i].dis >= 10.0 && e[i].dis <= 1000))
        {
            ans += e[i].dis;
            fa[a] = b;///合并集合
            m++;
        }
    }
    //cout << m << endl;
    if(m != n-1) return -1;
    else return ans;
}
double distance(int x0,int y0,int x1,int y1)
{
    return sqrt((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1));
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        scanf("%d",&n);
        for(int i = 1; i <= n; i++)
            cin >> s[i].x >> s[i].y;
        cunt = 0;
        for(int i = 1; i < n; i++)
        {
            for(int j = i+1; j <= n; j++)
            {
                e[cunt].dis = distance(s[i].x,s[i].y,s[j].x,s[j].y);
                e[cunt].s = i;
                e[cunt].e = j;
                cunt++;
            }
        }
        double sum = Kruskal();
        if(sum == -1) printf("oh!\n");
        else
        {
            sum = sum*100;
            printf("%.1lf\n",sum);
        }
    }
 
    return 0;
}