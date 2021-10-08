#include<iostream>
using namespace std;
int main(){
    int s[8]={1,2,0,2,2,1,0,1},n;
    while(cin>>n){
        if(!s[n%8]){
            cout<<"yes"<<endl;
        }else{
            cout<<"no"<<endl;
        }
    }
    return 0;
}

/*
0 1 2 3 4 5 6 7 8 9 10
7 11 18 29 47 76 123 199



*/