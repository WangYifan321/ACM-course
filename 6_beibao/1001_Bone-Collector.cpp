//01背包问题
#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int x;
    cin>>x;
    int v[1010],w[1010],dp[1010];
    while(x--){
        int n,m;
        cin>>n>>m;
        memset(v,0,sizeof(v)); 
        memset(w,0,sizeof(w));
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        cin>>w[i];//输入价值
        for(int i=0;i<n;i++)
        cin>>v[i];//输入体积
        for(int i=0;i<n;i++){
            for(int j=m;j>=v[i];j--){
                dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
            }
        }

        cout<<dp[m]<<endl;
    }
    return 0;
}

/*
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int w[1005], v[1005]; //分别表示第i件商品的价值与体积
int dp[1005][1005]; //用于存储结果, dp[i][j]. 表示可选购商品有i件, 背包容量为j时的最优解
int main(void)
{
	int t; cin >> t;
	while (t--) {
		int n, m; scanf("%d %d", &n, &m); //n表示商品总数, m表示背包总容量
		memset(dp, 0, sizeof(dp));

		for (int i = 1; i <= n; i++) scanf("%d", &w[i]); //读入价值
		for (int i = 1; i <= n; i++) scanf("%d", &v[i]); //读入体积
		for (int i = 1; i <= n; i++) { //可选购的商品i
			for (int j = 0; j <= m; j++) { //由于可能有体积为0的商品, 所以从0开始循环
				if (j >= v[i]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]); //dp思路的核心
				else dp[i][j] = dp[i - 1][j];  如果现在背包的容量比当前的商品体积大了, 才是能买的情况.
												至于是否购买, 则取决于买后的总价值是否高于不买时的总价值.
			}
		}
		printf("%d\n", dp[n][m]); //输出 可选购的商品有n件, 背包容量为m时的最优解
	}
	return 0;
}*/