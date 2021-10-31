#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int dp[21][21],a[21][21];
    int n,k;
    while(cin>>n>>k){
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            cin>>a[i][j];
        }
    }
    memset(dp,0,sizeof(dp));
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<k;j++){
            dp[i][j]=1111111;
            for(int x=0;x<k;x++){
                dp[i][j]=min(dp[i][j],dp[i+1][x]+abs(a[i][j]-a[i+1][x]));
            }
        }
    }
    int ans=1111111;
    for(int i=0;i<k;i++){
        if(dp[0][i]<ans)
        ans=dp[0][i];
    }
    cout<<ans<<endl;



  }
  return 0;

}