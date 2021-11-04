#include<iostream>
#include<cstring>
using namespace std;
int data[1001];
int dp[1001];
int main(){
    int x;
    while(cin>>x && x!=0){
        for(int i=0;i<x;i++){
            cin>>data[i];
        }
        memset(dp,0,sizeof(dp));
        dp[0]=data[0];
        for(int i=1;i<x;i++){
            for(int j=0;j<i;j++){
                if(data[j]<data[i]){
                    dp[i]=max(dp[i],dp[j]+data[i]);
                }
            }
            dp[i]=max(dp[i],data[i]);//没有这个会报错.如果前面的数都不比当前数小，直接就是当前数的值
        }
        int max=0;
        for(int i=0;i<x;i++){
            if(dp[i]>max){
                max=dp[i];
            }
        }
        cout<<max<<endl;
    }
    
}