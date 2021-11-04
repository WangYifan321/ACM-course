#include<iostream>
using namespace std;
int main(){
    int x;
    __int64 f[51];
    f[1]=3;
    f[2]=6;
    f[3]=6;
    for(int i=4;i<51;i++){
        f[i]=f[i-1]+2*f[i-2];
    }
    while(cin>>x){
        if(x==1){
            cout<<3<<endl;
        }else{
            
            cout<<f[x]<<endl;
        }
    }

}
