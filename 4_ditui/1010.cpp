#include<iostream>
using namespace std;
int main(){
    __int64 f[36]={0};//卡特兰数
    f[0]=1;
    f[1]=1;
    for(int i=2;i<=35;i++){
        for(int j=0;j<=i-1;j++){
            f[i]+=f[j]*f[i-j-1];
        }
    }
    int num=1;
    int n;
    while(cin>>n && n!=-1){
        printf("%d %d %I64d\n",num++,n,f[n]*2);
    }


}