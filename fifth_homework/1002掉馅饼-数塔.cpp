#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int dp[100055][13];
int threemax(int a,int b,int c){
    if(a>=b && a>=c) return a;
    if(b>=a && b>=c) return b;
    else return c;
}
int main(){
    int x;
    while(cin>>x){
        if(x==0){
            return 0;
        }else{
            memset(dp,0,sizeof(dp));//动态分配内存。直接给数组赋值会报错，直接赋值只能在定义时使用
            int maxt=0;//最大时间
            while(x--){
                int t,n;//t-时间，n馅饼掉落在某个位置
                scanf("%d %d",&n,&t);
                if(t>maxt){
                    maxt=t;
                }
                dp[t][n]++;
            }

            for(int i=maxt-1;i>=0;i--){
                for(int j=0;j<=10;j++){
                    dp[i][j]+=threemax(dp[i+1][j],dp[i+1][j-1],dp[i+1][j+1]);
                }//数组越界，特判j=0时就好了。但是这样也ac了
            }
            cout<<dp[0][5]<<endl;

        }

    }
    return 0;
}