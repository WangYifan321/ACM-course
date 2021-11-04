#include<iostream>
using namespace std;
//丑数。每一个数只能由前面的乘以2、3、5、7得到
int dp[5850] = {0,1};
int main(){
    int x1=1,x2=1,x3=1,x4=1;
    int dp1,dp2,dp3,dp4;
    for(int i=2;i<5850;i++){
        dp1=dp[x1]*2;
        dp2=dp[x2]*3;
        dp3=dp[x3]*5;
        dp4=dp[x4]*7;
        dp[i]=min(min(dp1,dp2),min(dp3,dp4));
        if(dp[i]==dp1) x1++;
        if(dp[i]==dp2) x2++;
        if(dp[i]==dp3) x3++;
        if(dp[i]==dp4) x4++;
    }
    int n;
    while(cin>>n && n){
        if(n % 10 == 1 && n % 100 != 11)        //这一块要掌握，巧妙找到末尾是11的数
            printf("The %dst humble number is %d.\n", n, dp[n]);
        else if(n % 10 == 2 && n % 100 != 12)
            printf("The %dnd humble number is %d.\n", n, dp[n]);
        else if(n % 10 == 3 && n % 100 != 13)
            printf("The %drd humble number is %d.\n", n, dp[n]);
        else
            printf("The %dth humble number is %d.\n", n, dp[n]);
    }
    return 0;
}