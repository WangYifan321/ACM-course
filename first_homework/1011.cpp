#include<iostream>
using namespace std;
int main(){
    int x;
    while(cin>>x){
        if(x>100 || x<0){
            cout<<"Score is error!\n";
        }else if(x<60){
            cout<<"E\n";
        }else if(x<70){
            cout<<"D\n";
        }else if(x<80){
            cout<<"C\n";
        }else if(x<90){
            cout<<"B\n";
        }else{
            cout<<"A\n";
        }
    }
    return 0;
}