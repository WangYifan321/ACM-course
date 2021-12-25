#include<iostream>
#include<cstring>
#include<algorithm>
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
    int n;
    cin>>n;
    while(n--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int e=a*c;
        int f=b*d;
        int re=gcd(e,f);
        cout<<e/re<<' '<<f/re<<endl;
    }

    return 0;
}