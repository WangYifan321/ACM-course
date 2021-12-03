#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
    int m;
    while(cin>>m && m){
        int ans=0;
        for(int i=0;i<m;i++){
            int n;
            cin>>n;
            ans^=n;
        }
        if(ans) cout<<"Rabbit Win!"<<endl;
        else cout<<"Grass Win!"<<endl;

    }




    return 0;
}