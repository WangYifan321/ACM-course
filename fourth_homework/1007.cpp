#include<iostream>
using namespace std;
int main(){
    __int64 f[31];
    f[1]=1;
    f[2]=3;
    f[3]=5;
    for(int i=4;i<=30;i++){
        f[i]=f[i-1]+f[i-2]*2;
    }

    int x;
    cin>>x;
    while(x--){
        int n;
        cin>>n;
        cout<<f[n]<<endl;

    }
    return 0;
}