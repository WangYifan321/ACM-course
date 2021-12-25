#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
struct node{
	int x,y;
	int step;
}p,q;
queue<node> Q;
int n,m;//行数，列数
int sx,sy,endx,endy;
char map[15][15];
bool visit[15][15];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
bool isbond(node &a){
	if(a.x<1 || a.x>n || a.y<1 || a.y>m)return 1;
	return 0;
}
int bfs(){
	memset(visit,0,sizeof(visit));
	while(!Q.empty())//清空队列
    Q.pop();
    p.x=sx;
    p.y=sy;
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

		for(int i=0;i<4;i++)
		{
			q.x=p.x+dir[i][0];
	        q.y=p.y+dir[i][1];
			
			if(isbond(q))continue;
			if(visit[q.x][q.y])continue;
			if(map[q.x][q.y]=='.'){
                q.step=p.step+1;
			    visit[q.x][q.y]=1;
			    Q.push(q);
            }else{
                q.x=q.x+dir[i][0];
	            q.y=q.y+dir[i][1];
                if(isbond(q))continue;
			    if(visit[q.x][q.y])continue;
                if(map[q.x][q.y]=='.'){
                    q.step=p.step+1;
			        visit[q.x][q.y]=1;
			        Q.push(q);
                }
            }
			
			
		}
	}
    return -1;
}
int main(){
    while(cin>>n>>m){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>map[i][j];
            }
        }
        cin>>sx>>sy>>endx>>endy;
        int res = bfs();
        cout<<bfs()<<endl;
    }
    return 0;
}


