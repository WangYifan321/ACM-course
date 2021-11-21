#include<stdio.h>
#include<string.h>
#include<queue>
//优先队列的使用
#include<algorithm>
#define N 210
using namespace std;
char a[N][N];
int b[N][N];
int n,m,ax,ay;
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
struct zz
{
	int x,y,ans;
	friend bool operator<(zz x,zz y)
	{
		return x.ans>y.ans;/*按照时间从小到大排序*/
	}
};
void bfs(int x,int y)
{
	memset(b,0,sizeof(b));
	priority_queue<zz>q;
	zz f1,f2;
	f1.x=x;f1.y=y;
	f1.ans=0;/*第一部一定要让ans=0*/	
	q.push(f1);
	b[x][y]=1;
	while(!q.empty())
	{
		f1=q.top() ;
		q.pop();
		if(a[f1.x][f1.y]=='r')
		{
			printf("%d\n",f1.ans);
			return ;
		}
		for(int i=0;i<4;i++)
		{
			f2.x=f1.x+dx[i];
			f2.y=f1.y+dy[i];
			if(f2.x>0&&f2.x<=n&&f2.y>0&&f2.y<=m&&!b[f2.x][f2.y]&&a[f2.x][f2.y]!='#')
			{/*没有越界不是墙壁没有被用过的点执行下一步操作*/
				b[f2.x][f2.y]=1;
				if(a[f2.x][f2.y]=='x')
					f2.ans=f1.ans+2;/*遇到x时间加1*/
				else
					f2.ans=f1.ans+1;
					q.push(f2);
			}
		}
	}
	printf("Poor ANGEL has to stay in the prison all his life.\n");/*当遍历一遍之后还未找到人r*/
}
int main(){
	int i,j;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=1;i<=n;i++)
			scanf("%s",a[i]+1);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(a[i][j]=='a')
				{
					ax=i;ay=j;/*找到a的坐标*/
				}
			}
		}
		bfs(ax,ay);
	}
	return 0;
}