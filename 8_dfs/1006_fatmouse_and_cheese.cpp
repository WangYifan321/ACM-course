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
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int point[2][4]={{0,0,1,-1},{1,-1,0,0}};//函数point用来设置移动方向
int a,b,c,d,r[1010][1010],dp[1010][1010];//r用来存矩阵，dp表示最大序列和
int dfs(int m,int n){

    if(dp[m][n]>0)
        return dp[m][n];//证明dp已经被走过
    else{
        int maxn=0;//用来找四周的最大和
        int sum;//存当前的和
        int dx,dy;
        for(int i=0;i<4;i++){
            for(int j=1;j<=b;j++){

                dx=m+(point[0][i])*j;
                dy=n+(point[1][i])*j;
                if(dx>=0&&dy>=0&&dx<a&&dy<a&&r[dx][dy]>r[m][n]){
                    sum=dfs(dx,dy);
                    maxn=max(sum,maxn);
                }
            }
        }
        dp[m][n]=maxn+r[m][n];//回溯到m,n时的最大和（从大到小）
        return dp[m][n];
    }
}
int main(){
    while(scanf("%d%d",&a,&b)!=EOF){
        if(a==-1&&b==-1)return 0;
        memset(r,0,sizeof(r));
        memset(dp,0,sizeof(dp));
        for(int i=0;i<a;i++){
            for(int j=0;j<a;j++){
                scanf("%d",&r[i][j]);
            }
        }
        dfs(0,0);
        printf("%d\n",dp[0][0]);//此时的dp[0][0]就是最大和
    }
    return 0;
}