#include<iostream>
#include<cstring>
using namespace std;
//记忆化搜索，直接搜索？
int map[105][105];
int dp[105][105];
int n,m;
int dfs(int x,int y){
    if(dp[x][y]>=0){
        return dp[x][y];
    }
    dp[x][y]=0;
    for(int i=0;i<=map[x][y];i++){
        for(int j=0;j<=map[x][y]-i;j++){
            if(x+i>=1 && y+j>=1 && x+i<=n && y+j<=m){
            dp[x][y]+=dfs(x+i,y+j);
            dp[x][y]%=10000;
            }
        }
    }
    return dp[x][y];
}
int main(){
    int p;
    cin>>p;
    while(p--){
        memset(dp,-1,sizeof(dp));
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>map[i][j];
            }
        }
        dp[n][m]=1;
        cout<<dfs(1,1)<<endl;
    }
    return 0;
}