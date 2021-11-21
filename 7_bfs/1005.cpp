#include<iostream>
#include<queue>
#include<stdio.h>
#include<algorithm>
#include<cstring>
using namespace std;
 
int dirx[6]={-1,1,0,0,0,0};
int diry[6]={0,0,1,-1,0,0};
int dirz[6]={0,0,0,0,-1,1};
int a,b,c,t;
int map[51][51][51];
int vis[51][51][51];
struct node
{
	int x;
	int y;
	int z;
	int step;
};
 
void bfs(node p)
{
	queue<node> q;
	q.push(p);
	//vis[v.x][v.y][v.z]=1;
	node vv;
	while(!q.empty())
	{
		node v=q.front();
		q.pop();
		//vis[v.x][v.y][v.z]=1;
		if(v.x==a-1&&v.y==b-1&&v.z==c-1&&v.step<=t)
		{
			cout<<v.step<<"\n";
			return;
		}
		for(int i=0;i<6;i++)
		{
			int x=v.x+dirx[i];
			int y=v.y+diry[i];
			int z=v.z+dirz[i];
			int step=v.step+1;
			if(x<0||x>=a||y<0||y>=b||z<0||z>=c)continue;
			else if(vis[x][y][z]||map[x][y][z]==1)continue;
			else
			{
				vis[x][y][z]=1;
				vv.x=x;vv.y=y;vv.z=z;vv.step=step;
				q.push(vv);
			}
		}
	}
	cout<<"-1\n";
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		scanf("%d %d %d %d",&a,&b,&c,&t);
		for(int i=0;i<a;i++)
			for(int j=0;j<b;j++)
				for(int k=0;k<c;k++)
					scanf("%d",&map[i][j][k]);
		memset(vis,0,sizeof(vis));
		node p;
		p.x=0;p.y=0;p.z=0;p.step=0;
		vis[p.x][p.y][p.z]=1;
		bfs(p);
	}
}