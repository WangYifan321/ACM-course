#include<iostream>
using namespace std;
int main(){
    int x;
    cin>>x;
    while(x--){
        int n;
        cin>>n;
        int p=0,q=0,r=1;
        for(int i=1;i<n;i++){
            p=q;
            q=r;
            r=q+p;
        }
        cout<<r<<endl;

    }
    return 0;
}