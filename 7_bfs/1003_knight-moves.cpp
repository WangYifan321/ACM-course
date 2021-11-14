#include<iostream>
#include<cstring>
#include<string>
#include<queue>
//走“日”字。弄一个二维数组存储接下来要走的坐标即可。
#include <fstream>
using namespace std;
struct node{
	int x,y;
	int step;
}p,q;
queue<node> Q;
int dir[8][2]={-2,-1,-2,1,-1,-2,-1,2,1,-2,1,2,2,-1,2,1};
int sx,sy,endx,endy;
bool visit[10][10];
bool isbond(node &a){
	if(a.x<0 || a.x>7 || a.y<0 || a.y>7)return 1;
	return 0;
}
int bfs(){
	memset(visit,0,sizeof(visit));
	while(!Q.empty())//清空队列
    Q.pop();
	p.step=0;
	visit[p.x][p.y]=1;
	Q.push(p);
	if(p.x==endx&&p.y==endy){
		return 0;
	}
	while(!Q.empty())
	{
		p=Q.front();
		Q.pop();
		if(p.x==endx&&p.y==endy)return p.step;
		for(int i=0;i<8;i++)
		{
			q.x=p.x+dir[i][0];
			q.y=p.y+dir[i][1];
			
			if(isbond(q))continue;
			if(visit[q.x][q.y])continue;
			
			q.step=p.step+1;
			visit[q.x][q.y]=1;
			Q.push(q);
			
		}
	}
}
int main()
{
	string a,b;
//	ifstream fin;
//	fin.open("aaa.txt");
	while(cin>>a>>b)
	{
		p.x=a[0]-'a';
		p.y=a[1]-'1';
		endx=b[0]-'a';
		endy=b[1]-'1';
		cout<<"To get from "<<a<<" to "<<b<<" takes ";
		cout<<bfs()<<" knight moves."<<endl;
	}
	return 0;
}