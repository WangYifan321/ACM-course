#include<iostream>
using namespace std;
int main(){
    int x;
    while(cin>>x){
        if(x!=0){
            int sum=0;
            int m;
            while(x--){
               cin>>m;
               sum+=m;
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}