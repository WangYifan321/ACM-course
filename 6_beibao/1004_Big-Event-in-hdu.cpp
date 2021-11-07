#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int x;
    while(cin>>x && x>0){
        int val[5002],dp[255555];
        memset(val,0,sizeof(val));
        memset(dp,0,sizeof(dp));
        int l=0,sum=0;
        for(int i=0;i<x;i++){
            int a,b;
            cin>>a>>b;
            while(b--){
                val[l++]=a;
                sum+=a;
            }
        }
        //转变为01背包
        for(int i=0;i<l;i++){
            for(int j=sum/2;j>=val[i];j--){
                dp[j]=max(dp[j],dp[j-val[i]]+val[i]);
            }
        }
        cout<<sum-dp[sum/2]<<" "<<dp[sum/2]<<endl;

    }
    return 0;
}