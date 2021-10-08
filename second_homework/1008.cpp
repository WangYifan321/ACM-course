#include<iostream>
using namespace std;
int fast(int a,int b){
    int ans=1;
    a=a%10;
    while(b>0){
        if(b%2==1){
            ans=(ans*a)%10;

        }
        b=b/2;
        a=(a*a)%10;

    }
    return ans;
}
int main(){
    int x;
    cin>>x;
    while(x--){
        int a;
        cin>>a;
        cout<<fast(a,a)<<endl;
    }
    return 0;
}