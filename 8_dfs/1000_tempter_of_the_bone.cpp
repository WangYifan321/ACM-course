#include<iostream>
using namespace std;
char map[7][7];//地图
int direct[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int n,m,t,dx,dy,sx,sy;//迷宫的大小，n行m列，开门时间
bool flag;
void dfs(int x,int y,int step){

    if(x==dx && y==dy && step==t){
        flag=1;
        return;
    }
    int p=(t-step)-abs(x-dx)-abs(y-dy);
    if(p<0||p&1){
        return;
    }
    for(int i=0;i<4;i++){
        int x1=x+direct[i][0];
        int y1=y+direct[i][1];
        if(map[x1][y1]!='X' && x1>0 && x1<=n && y1>0 && y1<=m){
            map[x1][y1]='X';
            dfs(x1,y1,step+1);
            map[x1][y1]='.';
        }
    }
    return;
}

int main(){
    while(cin>>n>>m>>t){
        if(n==0 && m==0 && t==0){
            return 0;
        }
        int wall=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>map[i][j];
                if(map[i][j]=='S'){
                    sx=i;
                    sy=j;
                }else if(map[i][j]=='D'){
                    dx=i;
                    dy=j;
                }else if(map[i][j]=='X'){
                    wall++;
                }
            }
        }
        flag=0;
        map[sx][sy]='X'; 
        if(n*m-wall<=t){
            cout<<"NO"<<endl;
            continue;
        }
        dfs(sx,sy,0);
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}