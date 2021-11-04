#include<iostream>
using namespace std;
int main(){
    int a,n,m;
    while(cin>>n>>m){
        if(n==0 && m==0){
            break;
        }
        if(n==0 && m!=0){
            cout<<"0"<<endl;
        }
        if(n!=0 && m==0){
            cout<<"1"<<endl;
        }
        if(n!=0 && m!=0){
            int s = n;
            a=m-1;
            while(a--){
                s=s*n;
                s=s%1000;
            }
            cout<<s<<endl;
        }
    }
    return 0;
}