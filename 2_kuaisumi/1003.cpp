#include<iostream>
using namespace std;
//辗转相除法找最小公倍数
int gcd(int a,int b){
    while(a%b != 0){
       int flag = a;
       a=b;
       b=flag%b;
    }
    return b;
}
int lcm(int a,int b){
    return a/gcd(a,b)*b;
}
int main(){
    int x;
    cin>>x;
    while (x--)
    {
        int n;
        cin>>n;
        int a,sum=1;
        while(n--){
            cin>>a;
            sum = lcm(sum,a);
            
        }
        cout<<sum<<endl;
    }
    return 0;
}