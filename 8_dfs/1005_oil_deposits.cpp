#include<iostream>
#include<cstring>
using namespace std;
char map[105][105];
int dir[8][2]={{1,0},{-1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,1},{1,-1}};//可以走的八个方向
int m,n;//一共m行，每行n个字符
int ans;
void dfs(int i,int j){
    for(int x=0;x<8;x++){
        int x1=i+dir[x][0];
        int y1=j+dir[x][1];
        if(x1>0 && y1>0 && x1<=m && y1<=n)
        if(map[x1][y1]=='@'){
            map[x1][y1]='*';
            dfs(x1,y1);
        }

    }
    return ;

}
int main(){
    while(cin>>m>>n && m && n){
        ans=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                cin>>map[i][j];
            }
        }

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(map[i][j]=='@'){
                    ans++;
                    map[i][j]='*';
                    dfs(i,j);
                }
            }
        }

        cout<<ans<<endl;
    }
    return 0;

}