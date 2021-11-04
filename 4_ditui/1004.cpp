#include<iostream>
using namespace std;
//可能开数组，空间换时间
int main(){
    __int64 f[51];
    f[1]=1;
    f[2]=2;
    f[3]=3;
    for(int i=4;i<51;i++){
        f[i]=f[i-1]+f[i-2];
    }
    int x;
    while(cin>>x){
        cout<<f[x]<<endl;
    }
    return 0;
}