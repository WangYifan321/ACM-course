#include<iostream>
using namespace std;
int main(){
    int f[21];
    f[1]=3;
    f[2]=7;
    for(int i=3;i<=20;i++){
        f[i]=f[i-1]*2+f[i-2];
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