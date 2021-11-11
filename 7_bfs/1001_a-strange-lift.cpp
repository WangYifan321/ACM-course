#include<iostream>
#include<queue>
#include<cstring>
//用到了树的bfs思想。但是没有必要先建立一棵树。用思想去遍历即可！！！！！！！

using namespace std;
int data[210],vis[210];
int n,s,e;//n个楼层。从s开始。到e结束
struct pos{
    int level;//当前在第几层
    int steps;//到当前位置走了多少层
};
void bfs();
int main(){
    while(cin>>n && n!=0){
        cin>>s>>e;

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

    cur.level=s;
    cur.steps=0;
    q.push(cur);
    vis[s]=1;
    while(!q.empty()){
        cur=q.front();
        q.pop();
        if(cur.level==e){
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
                vis[next.level]=1;
                q.push(next);
            }
        }
    }
    cout<<"-1"<<endl;
    return;

}