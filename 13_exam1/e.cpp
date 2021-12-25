#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    int dp[46]={0};
    int ans[46]={0};
    dp[1]=1;dp[2]=0;dp[3]=4;dp[4]=4;dp[5]=20;
	ans[1]=1;ans[2]=1;ans[3]=5,ans[4]=9,ans[5]=29;
    
    for(int i=6;i<=40;i++){
        for(int j=i-4;j<=i-2;j++){
            dp[i]+=dp[j]*4;
        }
        ans[i]=ans[i-1]+dp[i]-dp[i-5];
    }


    while(n--){
        int a;
        cin>>a;
        cout<<ans[a]<<endl;
    }

    return 0;
}