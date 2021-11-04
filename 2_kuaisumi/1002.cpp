#include<iostream>
using namespace std;
int main(){
    int x;
    while(cin>>x){
        if(x!=0){
           int front = 0;
           int behind,sum = x*5;
           while(x--){
               cin>>behind;
               if(behind > front){
                   sum = sum + (behind-front)*6;
               }else if(behind < front){
                   sum = sum + (front-behind)*4;
               }
               front = behind;

           }
           cout<<sum<<endl;
        }
    }
    return 0;
}