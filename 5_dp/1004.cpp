#include<iostream>
#include<algorithm>
#include<cstring>
//搬寝室问题。
#define min(a,b) a>b?b:a
using namespace std;
int dp[2010][2010],a[2010];
int main(){
    int n,k;
    while(cin>>n>>k){
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+1+n);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=k;i++){//要搬i对物品，一共有j个物品。
            dp[i][i+i]=dp[i-1][i+i-2]+(a[i+i-1]-a[i+i])*(a[i+i-1]-a[i+i]);
            for(int j=i+i+1;j<=n;j++){
                dp[i][j]=min(dp[i][j-1],dp[i-1][j-2]+(a[j]-a[j-1])*(a[j]-a[j-1]));
            }//分两个情况，为包含最后一个和不包含最后一个
            
        }
        cout<<dp[k][n]<<endl;


    }
    return 0;

}