#include<iostream>
using namespace std;
int main(){
    int x;
    cin>>x;
    while(x--){
        int m;
        cin>>m;
        int sum=0;
        while(m--){
            int n;
            cin>>n;
            sum+=n;
        }
        if(x==0){
            cout<<sum<<endl;
        }else
        cout<<sum<<endl<<endl;
    }
    return 0;
}