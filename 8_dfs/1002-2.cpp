#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[25],vis[25],n;
int isp[55],flag[55];//是否为素数，是否为合数

void isprime(){
    memset(isp,0,sizeof(isp));
    memset(flag,0,sizeof(flag));
    for(int i=2;i<=7;i++){
        if(!flag[i]){
            for(int j=i*i;j<=50;j+=i){
                flag[j]=1;
            }
        }
    }
    for(int i=2;i<=50;i++){
        if(!flag[i]){
            isp[i]=1;
        }
    }
}

void dfs(int k){
    if(k==n && isp[a[k-1]+a[0]]){
        printf("%d",a[0]);
        for(int i=1; i<n; i++)
            printf(" %d",a[i]);
        printf("\n");
    }else{
        for(int i=2;i<=n;i++){
            if(!vis[i] && isp[a[k-1]+i]){
                vis[i]=1;
                a[k]=i;
                dfs(k+1);
                vis[i]=0;
            }
        }
    }

}


int main(){
    
    int k=0;
    isprime();
    while(cin>>n){
        for(int i=0;i<n;i++){
            a[i]=i+1;
        }
        printf("Case %d:\n",++k);
        memset(vis,0,sizeof(vis));
        dfs(1);
        printf("\n");
    }
    return 0;
}