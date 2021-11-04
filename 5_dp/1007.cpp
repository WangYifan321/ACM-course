#include<iostream>
#include<algorithm>
#include<cstring>
//模板题目，字符串的最长公共子序列
using namespace std;
int dp[1010][1010];
int main(){
    string a,b;
    while(cin>>a>>b){
        int alen=a.size();
        int blen=b.size();
        memset(dp,0,sizeof(dp));
        for(int i=0;i<alen;i++){
            for(int j=0;j<blen;j++){
                if(a[i]==b[j]){
                    dp[i+1][j+1]=dp[i][j]+1;
                }else{
                    dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        cout<<dp[alen][blen]<<endl;
    }
    return 0;
}