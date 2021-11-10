#include<iostream>
#include<cstring>
using namespace std;
float dp[10010];
int main(){
    int n,m;
    while(cin>>n>>m){
        int a[10010];
        float b[10010];
        if(n==0 && m==0) break;
        for(int i=0;i<m;i++){
            cin>>a[i]>>b[i];
        }
        //memset(dp,1.0,sizeof(dp));中间传入的值是int

        for(int i=0;i<=n;i++) dp[i]=1.0;
        for(int i=0;i<m;i++){
            for(int j=n;j>=a[i];j--){
                dp[j]=min(dp[j],dp[j-a[i]]*(1-b[i]));
            }
        }
        printf("%.1f",(1-dp[n])*100);
        printf("%%\n");
    }
}
