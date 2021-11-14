#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int s,n,m;//可乐的体积，两个杯子的容量
struct pos{
    int a,b,c;
    int step;
};
int vis[105][105][105];//开数组太大会超时

//判断当前状态是否合法
int is_valid(int a,int b,int c){
    if(a==b && c==0) return 1;
    if(a==c && b==0) return 1;
    if(b==c && a==0) return 1;
    return 0;
}
void bfs();//if判断所有情况
void bfs2();//两层for循环，矩阵二维数组
int main(){
    while(cin>>s>>n>>m){
        if(s==0){
            break;
        }else if(s%2){
            cout<<"NO"<<endl;
        }else{
            memset(vis,0,sizeof(vis));
            bfs();

        }
    }

    return 0;
}

void bfs2(){
    
}

void bfs(){
    queue<pos> q;
    pos cur,next;

    cur.a=s;
    cur.b=0;
    cur.c=0;
    cur.step=0;

    q.push(cur);
    vis[s][0][0]=1;
    while(!q.empty()){
        cur=q.front();
        q.pop();
        if(is_valid(cur.a,cur.b,cur.c)){
          cout<<cur.step<<endl;
          return ;
        }
        if(cur.b){//中间的杯子有东西
            if(cur.b>s-cur.a){//能倒满第一个杯子
                next.c=cur.c;
                next.a=s;
                next.b=cur.b-(s-cur.a);
                if(!vis[next.a][next.b][next.c]){
                    next.step=cur.step+1;
                    q.push(next);
                    vis[next.a][next.b][next.c]=1;
                }
            }else{//到不满
                next.a=cur.b+cur.a;
                next.b=0;
                next.c=cur.c;
                if(!vis[next.a][next.b][next.c]){
                    next.step=cur.step+1;
                    q.push(next);
                    vis[next.a][next.b][next.c]=1;
                }
            }

            if(cur.b>m-cur.c){//能倒满第三个杯子
                next.a=cur.a;
                next.c=m;
                next.b=cur.b-(m-cur.c);
                if(!vis[next.a][next.b][next.c]){
                    next.step=cur.step+1;
                    q.push(next);
                    vis[next.a][next.b][next.c]=1;
                }
            
            }else{//到不满
                next.a=cur.a;
                next.b=0;
                next.c=cur.c+cur.b;
                if(!vis[next.a][next.b][next.c]){
                    next.step=cur.step+1;
                    q.push(next);
                    vis[next.a][next.b][next.c]=1;
                }

            }
        }

        if(cur.c){
            if(cur.c>s-cur.a){
                next.b=cur.b;
                next.a=s;
                next.c=cur.c-(s-cur.a);
                if(!vis[next.a][next.b][next.c]){
                    next.step=cur.step+1;
                    q.push(next);
                    vis[next.a][next.b][next.c]=1;
                }
            }else{
                next.b=cur.b;
                next.c=0;
                next.a=cur.a+cur.c;
                if(!vis[next.a][next.b][next.c]){
                    next.step=cur.step+1;
                    q.push(next);
                    vis[next.a][next.b][next.c]=1;
                }
            }

            if(cur.c>n-cur.b){
                next.b=n;
                next.a=cur.a;
                next.c=cur.c-(n-cur.b);
                if(!vis[next.a][next.b][next.c]){
                    next.step=cur.step+1;
                    q.push(next);
                    vis[next.a][next.b][next.c]=1;
                }
            }else{
                next.b=cur.b+cur.c;
                next.a=cur.a;
                next.c=0;
                if(!vis[next.a][next.b][next.c]){
                    next.step=cur.step+1;
                    q.push(next);
                    vis[next.a][next.b][next.c]=1;
                }
            }
        }

        if(cur.a){
            if(cur.a>n-cur.b){
                next.b=n;
                next.a=cur.a-(n-cur.b);
                next.c=cur.c;
                if(!vis[next.a][next.b][next.c]){
                    next.step=cur.step+1;
                    q.push(next);
                    vis[next.a][next.b][next.c]=1;
                }
            }else{
                next.b=cur.b+cur.a;
                next.a=0;
                next.c=cur.c;
                if(!vis[next.a][next.b][next.c]){
                    next.step=cur.step+1;
                    q.push(next);
                    vis[next.a][next.b][next.c]=1;
                }
            }

            if(cur.a>m-cur.c){
                next.b=cur.b;
                next.a=cur.a-(m-cur.c);
                next.c=m;
                if(!vis[next.a][next.b][next.c]){
                    next.step=cur.step+1;
                    q.push(next);
                    vis[next.a][next.b][next.c]=1;
                }
            }else{
                next.b=cur.b;
                next.a=0;
                next.c=cur.c+cur.a;
                if(!vis[next.a][next.b][next.c]){
                    next.step=cur.step+1;
                    q.push(next);
                    vis[next.a][next.b][next.c]=1;
                }
            }
        }



        

    }
    cout<<"NO"<<endl;
    return ;

}