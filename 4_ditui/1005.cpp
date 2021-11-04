#include<iostream>
using namespace std;
int main(){
    int x;
    cin>>x;
    while(x--){
        int n;
        cin>>n;
        cout<<2*n*n-n+1<<endl;
    }
    return 0;
}