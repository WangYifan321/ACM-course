//悼念521汶川大地震遇难同胞----选拔志愿者
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
int k[110];
using namespace std;
int main(){
    int c;
    cin>>c;
    while(c--){
        int n,m;//最先使得捐款达到n元的为啥胜者，每次只能捐款1-m元
        cin>>n>>m;
        if(n<=m){
            cout<<"Grass"<<endl;
        }else{
            if(n%(m+1)==0){
                cout<<"Rabbit"<<endl;
            }else{
                cout<<"Grass"<<endl;

            }
        }
    }
    

    return 0;
}