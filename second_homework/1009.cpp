#include<iostream>
using namespace std;
int gcd(int a,int b){
    while(a%b!=0){
        int flag = a;
        a = b;
        b = flag%b;

    }
    return b;
}
int lcm(int a,int b){
    return a/gcd(a,b)*b;
}
int main(){
    int a,b;
    while(cin>>a>>b){
        cout<<lcm(a,b)<<endl;
    }
    return 0;
}