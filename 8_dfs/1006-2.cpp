//记忆化搜索和dp
/*
Sample Input
3 1
1 2 5
10 11 6
12 12 7
-1 -1
Sample Output
37
*/
#include<iostream>
#include<cstring>
using namespace std;
int map[1050][1050],dp[1050][1050];
int a,b;
int dir[4][2]={{1,0},{-1,0},{0,-1},{0,1}};

int dfs(int c,int d){
    if(dp[c][d]>0){
        return dp[c][d];
    }else{
        int maxn=0;
        int tmp;
        for(int i=0;i<4;i++){
            for(int j=1;j<=b;j++){
                int x1=c+dir[i][0]*j;
                int y1=d+dir[i][1]*j;
                if(x1>=0 && y1>=0 && x1<a && y1<a && map[x1][y1]>map[c][d]){
                    tmp = dfs(x1,y1);
                    maxn=max(maxn,tmp);
                }

            }
        }
        dp[c][d]=maxn+map[c][d];
        return dp[c][d];
    }

}

int main(){
    while(cin>>a>>b){
        if(a==-1 && b==-1){
            return 0;
        }
        memset(dp,0,sizeof(dp));//dp数的中某一个值为0时代表没有访问过，>0的话说明已经访问过了
        memset(map,0,sizeof(dp));
        for(int i=0;i<a;i++){
            for(int j=0;j<a;j++){
                cin>>map[i][j];
            }
        }

        dfs(0,0);
        cout<<dp[0][0]<<endl;
    }


    return 0;
}