#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int x;
    cin>>x;
    while(x--){
        int n,m;//金额和种类
        cin>>n>>m;
        int p[205];//每袋的价格
        int h[205];//每袋的重量
        int c[205];//对应种类的大米的袋数
        for(int i=0;i<m;i++){
            cin>>p[i]>>h[i]>>c[i];
        }
        int dp[100001];
        memset(dp,0,sizeof(dp));
        //多重背包
        for(int i=0;i<m;i++){
            if(p[i]*c[i]>=n){
                //完全背包
                for(int j=p[i];j<=n;j++){
                    dp[j]=max(dp[j],dp[j-p[i]]+h[i]);
                }
            }else{

            int k=1;
            //把c[i]个相同的物品拆开。变成1，2，4，2^(k-1),n[i]-2^k+1。比如13拆成1，2，4，6
            //这样保证1到n[i]的每一个数都可以用他们表示，同时加快了运算的速度
            while(k<c[i]){
                //01背包
                for(int j=n;j>=p[i]*k;j--){
                    dp[j]=max(dp[j],dp[j-p[i]*k]+h[i]*k);
                }
                c[i]-=k;
                k*=2;
            }
            //01背包
            for(int j=n;j>=p[i]*c[i];j--){
                dp[j]=max(dp[j],dp[j-p[i]*c[i]]+c[i]*h[i]);
            }
           }
        }
        cout<<dp[n]<<endl;

    }
}

/*不用二进制优化的代码。相当于01背包
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
using namespace std;
int height[505];
int value[505];
int dp[2000];
int mount[505]; 
 
int main()
{
	int T;
	scanf("%d",&T);
	int n,m;
	while(T--)
	{
		memset(dp,0,sizeof(dp));
		scanf("%d %d",&n,&m);
		for(int i=0;i<m;i++)
		{
			scanf("%d %d %d",&height[i],&value[i],&mount[i]);
		}
		for(int i=0;i<n;i++)
		{
			for(int k=1;k<=mount[i];k++)
			{
				for(int j=n;j>=height[i];j--)
				{
					dp[j] = max(dp[j],dp[j-height[i]] + value[i]);
				}
			}
		}
		printf("%d\n",dp[n]);
	}
	return 0;
}*/
