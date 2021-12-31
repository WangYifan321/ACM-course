#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
char map[101][101];
int res;
struct node{
	int x,y;
}p,q;
queue<node> Q;
int n,m;//行数，列数
int sx,sy;
bool visit[101][101];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
bool isbond(node &a){
	if(a.x<1 || a.x>n || a.y<1 || a.y>n)return 1;
	return 0;
}
int bfs(){
    res=1;
	memset(visit,0,sizeof(visit));
	while(!Q.empty())//清空队列
    Q.pop();
    p.x=sx;
    p.y=sy;
	visit[p.x][p.y]=1;
	Q.push(p);

	while(!Q.empty())
	{
		p=Q.front();
		Q.pop();

		for(int i=0;i<4;i++)
		{
			q.x=p.x+dir[i][0];
	        q.y=p.y+dir[i][1];
			
			if(isbond(q))continue;
			if(visit[q.x][q.y])continue;
			if(map[q.x][q.y]!=map[p.x][p.y]){
                res++;
			    visit[q.x][q.y]=1;
			    Q.push(q);
            }
			
		}
	}
    return res;
}

int main(){
    while(cin>>n>>m){
       for(int i=1;i<=n;i++){
           for(int j=1;j<=n;j++){
               cin>>map[i][j];
           }
       }
       int i,j;
       while(m--){
           cin>>i>>j;
           sx=i;
           sy=j;
           cout<<bfs()<<endl;
       }



    }
    

    return 0;
}