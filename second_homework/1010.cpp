#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int b;
    double a;
    while(cin>>a>>b){
        double sum=0;
        while(b--){
           sum+=a;
           a=sqrt(a);
        }
        printf("%.2f\n",sum);
    }
    return 0;
}