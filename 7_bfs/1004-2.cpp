#include<cstring>
#include<iostream>
#include<queue>

using namespace std;
char map[210][210];
int vis[210][210];
int m,n;
int ax,ay;
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
struct node
{
    int x,y,t;
    friend bool operator<(node a,node b){
        return a.t>b.t;
    }
};


void bfs(){
    memset(vis,0,sizeof(vis));
    node cur,next;
    priority_queue<node> q;
    cur.t=0;
    cur.x=ax;
    cur.y=ay;
    q.push(cur);
    vis[ax][ax]=1;
    while(!q.empty()){
        cur=q.top();
        q.pop();

        if(map[cur.x][cur.y]=='r'){
            cout<<cur.t<<endl;
            return;
        }

        for(int i=0;i<4;i++){
            next.x=cur.x+dx[i];
            next.y=cur.y+dy[i];
            if(next.x>0&&next.x<=m&&next.y>0&&next.y<=n&&!vis[next.x][next.y]&&map[next.x][next.y]!='#'){
                vis[next.x][next.y]=1;
                if(map[next.x][next.y]=='x'){
                    next.t=cur.t+2;
                }else{
                    next.t=cur.t+1;
                }

                q.push(next);
            }
        }
    }
    printf("Poor ANGEL has to stay in the prison all his life.\n");/*当遍历一遍之后还未找到人r*/
}

int main(){
    while(cin>>m>>n){
        for(int i=1;i<=m;i++)
			scanf("%s",map[i]+1);
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(map[i][j]=='a')
				{
					ax=i;ay=j;/*找到a的坐标*/
				}
			}
		}
        cout<<ax<<ay<<endl;
		bfs();
    }
    return 0;

}