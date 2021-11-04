#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100005
struct node
{
    double x,y;
} point[N];

int point1[N];//存储符合标准的点的坐标

bool cmpx(node a,node b)//按x坐标从小到大排序
{
    return a.x<b.x;
}

bool cmpy(int a,int b)//按y坐标从小到大进行排序
{
    return point[a].y<point[b].y;
}

double dist(node a,node b)//求出两点间的距离
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double near(int l,int r)//利用分治法找出最近的两个点的距离
{
    if(l>=r)
        return 1e10;
    int mid=(l+r)/2;
    int n=0;
    double distan=min(near(l,mid),near(mid+1,r));//利用二分法分为两个区间
    for(int i=mid; i>=l; --i)//把前一半符合条件的点的位置存入数组q中
    {
        if(point[mid].x-point[i].x<distan)
        {
            point1[n++]=i;
        }
        else break;
    }
    for(int i=mid+1; i<=r; ++i)//把后一半符合条件的点的位置存入数组q中
    {
        if(point[i].x-point[mid].x<distan)
        {
            point1[n++]=i;
        }
        else break;
    }
    sort(point1,point1+n,cmpy);//对这些点按纵坐标进行升序排序
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(point[point1[j]].y-point[point1[i]].y<distan)//找出这些点中距离的最小值
            {
                distan=min(dist(point[point1[i]],point[point1[j]]),distan);
            }
            else break;
        }
    }
    return distan;
}

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        if(n==0)
            break;
        for(int i=0; i<n; i++)
        {
            scanf("%lf %lf",&point[i].x,&point[i].y);
        }
        sort(point,point+n,cmpx);
        printf("%.2lf\n",near(0,n-1)/2);
    }
    return 0;
}
