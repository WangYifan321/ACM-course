#include<iostream>
#include<cstring>
//简单的01背包
using namespace std;
int dp[10010];
int a[]={150,200,350};
int main(){
    int t;//一共t组数据
    cin>>t;
    while(t--){
        int n;
        cin>>n;//死亡骑士一共有多少钱，相当于背包的容量
        memset(dp,0,sizeof(dp));
        for(int i=0;i<3;i++){
            for(int j=a[i];j<=n;j++){
                dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
            }
        }
        cout<<n-dp[n]<<endl;
    }
    return 0;
}