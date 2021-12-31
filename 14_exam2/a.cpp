#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    int l,t1,t2,v1,v2;
    while(n--){
        cin>>l>>t1>>t2>>v1>>v2;
        float res1=t1+t2+(1.0*l/v1);
        float res2=1.0*l/v2;
        if(res1-res2<0){
            cout<<"Bike is OK!"<<endl;
        }else if(res1-res2>0){
            cout<<"Walk is OK!"<<endl;
        }else if(res1-res2==0){
            cout<<"Both are OK!"<<endl;
        }

    }
    

    return 0;
}