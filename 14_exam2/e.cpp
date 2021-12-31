#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int j[10000],f[10000],dp[10000];//某个房间有j[]五香豆，用f[]的猫粮去换
const int INF=-0x3f3f3f3f;
int main(){
    int m,n;
    while(cin>>m>>n){
        if(m==-1 && n==-1){
            break;
        }

        memset(j,0,sizeof(j)); 
        memset(f,0,sizeof(f));
        memset(dp,INF,sizeof(dp));
        dp[0]=0;

        for(int i=0;i<n;i++){
            cin>>j[i]>>f[i];
        }

         for(int i=0;i<n;i++){
            for(int w=m;w>=f[i];w--){
                dp[w]=max(dp[w],dp[w-f[i]]+j[i]);
            }
        }
        if(dp[m]>=0){
			printf("%d\n",dp[m]);
		}else{
			cout<<"-1"<<endl;
		}




    }
    

    return 0;
}