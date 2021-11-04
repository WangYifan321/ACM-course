#include<iostream>
using namespace std;
//找循环节
int main(){
    int a,b,n;
    int f[54] = {0,1,1};
    int flag;
    while(cin>>a>>b>>n){
        if(a==0 && b==0 && n==0){

        }else if(n==1 || n==2){
          cout<<"1"<<endl;
        }else{
            
          for(int i=3 ;i < 54;i++){
              f[i] = (a * f[i-1] + b * f[i-2])%7;
              if(i>5){
                  if(f[i-1] == f[3] && f[i] == f[4]){
                      flag = i-4;//求出循环节的长度
                      break;
                  }
              }
          }
          int result = f[(n-3)%flag+3];
        cout<<result<<endl;
        }
        
    }


    return 0;
}