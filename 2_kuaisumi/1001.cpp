#include<iostream>
using namespace std;
int main(){
    int x;
    int a;
    while(cin>>x){
        if(x==1){
            a=1;
        }else if(x&1){
            a = ((1+x)/2)*x;
        }else{
            a = (x/2)*(1+x);
        }
        cout<<a<<"\n"<<endl;
    }
    return 0;
}