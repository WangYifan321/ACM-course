#include<iostream>
using namespace std;
int main(){
    __int64 f[56];
    f[1]=1;
    f[2]=2;
    f[3]=3;
    f[4]=4;
    for(int i=5;i<55;i++){
        f[i]=f[i-1]+f[i-3];
    }
    int n;
    while(cin>>n && n!=0){
         cout<<f[n]<<endl;      
    }
    return 0;
}