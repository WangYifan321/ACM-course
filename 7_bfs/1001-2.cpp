#include<iostream>
#include<cstring>
#include<queue>

using namespace std;
int n,a,b;
int data[210],vis[210];
struct pos{
    int level;
    int steps;
};

void bfs();
int main(){
    while(cin>>n && n!=0){
        cin>>a>>b;
        for(int i=1;i<=n;i++){
            cin>>data[i];
        }
        memset(vis,0,sizeof(vis));
        bfs();
    }
    return 0;
}



void bfs(){
    pos cur,next;
    queue<pos> q;
    cur.level=a;
    cur.steps=0;
    q.push(cur);
    vis[cur.level]=1;

    while(!q.empty()){
        cur=q.front();
        q.pop();
        if(cur.level==b){
            cout<<cur.steps<<endl;
            return ;
        }

        next.steps=cur.steps+1;
        next.level=cur.level+data[cur.level];
        if(next.level<=n){
            if(vis[next.level]==0){
                vis[next.level]=1;
                q.push(next);
            }
        }

        next.steps=cur.steps+1;
        next.level=cur.level-data[cur.level];
        if(next.level>0){
            if(vis[next.level]==0){
                vis[cur.level]=1;
                q.push(next);
            }
        }
    }
    cout<<"-1"<<endl;
    return ;

}