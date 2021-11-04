#include<iostream>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        int sum=0;
        while(n--){
            int m;
            cin>>m;
            sum+=m;
        }
        cout<<sum<<endl;

    }
    return 0;
}