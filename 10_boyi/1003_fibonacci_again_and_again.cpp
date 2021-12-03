#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[20],sg[1000],vis[1000];
//打表求sg值
void getsg(){
    a[0]=1;
    a[1]=1;
    a[2]=2;
    for(int i=3;i<=19;i++){
        a[i]=a[i-1]+a[i-2];
    }
    memset(sg,0,sizeof(sg));
    for(int i=1;i<=1000;i++){
        memset(vis,0,sizeof(vis));
        for(int j=1;a[j]<=i;j++){
            vis[sg[i-a[j]]]=1;
        }
        for(int j=0;j<=1000;j++){
            if(vis[j]==0){
                sg[i]=j;
                break;
            }
        }
    }
}
int main(){
    int m,n,p;//三堆石子
    
    while(cin>>m>>n>>p){
        if(m==0 && n==0 && p==0){
            return 0;
        }
        getsg();
        //cout<<(sg[m]^sg[n]^sg[p])<<endl;
        if((sg[n]^sg[m]^sg[p])==0)      //注意异或运算的整个结果要加括号，我在这里wa到死
            cout<<"Nacci"<<endl;
        else
            cout<<"Fibo"<<endl;

    }
    return 0;
}