//继续畅通工程，克鲁斯卡尔
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define Maxn 10000
using namespace std;
int n,m,i,j,g;
int parent[Maxn];
struct edge
{
    int star,end1,w;
}edges[Maxn];
int cmp (struct edge a,struct edge b)
{
    return a.w<b.w;
}
void init()
{
    for(i=1; i<=n; i++)
        parent[i]=-1;
}
int Find(int x)
{
    int s;
    for(s=x; parent[s]>=0; s=parent[s]);
    while( s!=x )
    {
        int temp = parent[x];
        parent[x] = s;
        x = temp;
    }
    return s;
}
void merge(int R1,int R2)
{
    int r1 = Find(R1),r2=Find(R2);
    int temp = parent[r1]+parent[r2];
    if(parent[r1]>parent[r2])
    {
        parent[r1]=r2;
        parent[r2]=temp;
    }
    else
    {
        parent[r2]=r1;
        parent[r1]=temp;
    }
}
void kruskal()
{
    int sumweight=0;
    for(i=0; i<g; i++)
    {
        if(Find(edges[i].star)!=Find(edges[i].end1))
        {
            sumweight+=edges[i].w;
            merge(edges[i].star,edges[i].end1);
        }
    }
    printf("%d\n",sumweight);
}
int main()
{
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        g=0;
        memset(parent,0,sizeof(parent));
        init();
        m=n*(n-1)/2;
        for(i=0; i<m; i++)
        {
            int a,b,c,d;
            scanf("%d%d%d%d",&a,&b,&c,&d);
            if(d==1){
                merge(a,b);
            }
            else
            {
                edges[g].star=a;
                edges[g].end1=b;
                edges[g].w=c;
                g++;
            }
        }
        sort(edges,edges+g,cmp);
        kruskal();
    }
    return 0;
}