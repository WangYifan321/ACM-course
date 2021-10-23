#include<iostream>
using namespace std;
//技巧：大数是使用__int64，可以存到数组里面，速度快
int main(){
    int x;
    cin>>x;
    __int64 f[51];
    f[1]=1;
    f[2]=2;
    for(int i=3;i<51;i++){
        f[i]=f[i-1]+f[i-2];
    }
    while(x--){
        int a,b;
        cin>>a>>b;
        cout<<f[b-a]<<endl;
        
    }
    return 0;
}