#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
bool isTra(int a,int b,int c){
    if(a+b>c && a+c>b && b+c>a){
        return true;
    }else{
        return false;
    }
}

void fun(int a,int b,int c){
    int A=a*a;
    int B=b*b;
    int C=c*c;
    if((A>B+C) || (B>A+C) || (C>A+B)){
        //钝角
        cout<<"Obtuse triangle"<<endl;
    }else if((A==B+C)||(B==A+C)||(C==A+B)){
        //直角
        cout<<"Right triangle"<<endl;
    }else{
        //锐角
        cout<<"Acute triangle"<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    int a,b,c;
    while(n--){
        cin>>a>>b>>c;
        if(isTra(a,b,c)){
            fun(a,b,c);
        }else{
            cout<<"Impossible!"<<endl;
        }
    }

    return 0;
}