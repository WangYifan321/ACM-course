#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int x;
    while(cin>>x){
        if(x==0){
            break;
        }else{
            int a[105],b[105];//中国，日本
            for(int i=0;i<x;i++){
                cin>>a[i];
            }
            for(int i=0;i<x;i++){
                cin>>b[i];
            }
            sort(a,a+x);
            sort(b,b+x);
            int suma=0,sumb=0;
            for(int i=0;i<x;i++){
                if(a[i]>b[i]){
                    suma+=2;
                }else if(a[i]<b[i]){
                    sumb+=2;
                }else{
                    suma++;
                    sumb++;
                }
            }
            cout<<suma<<" vs "<<sumb<<endl;
        }
    }
    return 0;
    
}