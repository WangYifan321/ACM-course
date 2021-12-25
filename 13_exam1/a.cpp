#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        int a,b,c,d,e;
        cin>>a>>b>>c>>d>>e;
        float res1=a*a*1.0;
        float res2=b*c*1.0;
        float res3=d*e*(1.0)/2;
        if(res1>res2 && res1>res3){
            cout<<"Perch"<<endl;
        }
        if(res2>res1 && res2>res3){
            cout<<"Semon"<<endl;
        }
        if(res3>res2 && res3>res1){
            cout<<"Belinda"<<endl;
        }
    }
    return 0;
}