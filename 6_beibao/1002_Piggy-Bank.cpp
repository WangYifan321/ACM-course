#include<iostream>
#include<cstring>
using namespace std;
const int INF=0x3f3f3f3f;
//完全背包且必须装满
int v[10010];
int w[10010];//硬币的面值，重量
int dp[1001000];
int main(){
    int k;
    cin>>k;
    while(k--){
        int a,b;
        cin>>a>>b;
        int ans=b-a;
        int c;
        cin>>c;

        for(int i=0;i<c;i++){
            cin>>v[i]>>w[i];
        }
        memset(dp,INF,sizeof(dp));
        dp[0]=0;
        for(int i=0;i<c;i++){
            for(int j=w[i];j<=ans;j++){
                dp[j]=min(dp[j],dp[j-w[i]]+v[i]);
            }
        }

        if(dp[ans]!=INF){
			printf("The minimum amount of money in the piggy-bank is %d.\n",dp[ans]);
		}else{
			cout<<"This is impossible."<<endl;
		}


    }

}