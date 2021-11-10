#include<iostream>
#include<cstring>
//简单的多重背包，食物数量无限个
using namespace std;
int n;//每天的食谱清单有n种食物
int a[250],b[250];//a代表每种食物的幸福值。b代表吃这种食物吸收的卡路里量
int m;//吸收的卡路里量不能超过m。相当于背包容量
int dp[100100];
int main(){
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>a[i]>>b[i];
        }
        cin>>m;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=b[i];j<=m;j++){
                dp[j]=max(dp[j],dp[j-b[i]]+a[i]);
            }
        }
        cout<<dp[m]<<endl;
    }
    return 0;
}