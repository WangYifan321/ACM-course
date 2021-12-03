#include<iostream>
#include<cstring>
#include<algorithm>
int k[110];
using namespace std;
int main(){
    int m;//扑克牌的堆数
    while(cin>>m && m){
        int ans=0,res=0;
        //让所有的值异或
        for(int i=0;i<m;i++){
            cin>>k[i];
            ans^=k[i];
        }

        for(int i=0;i<m;i++){
            int tmp=ans^k[i];//在所有的异或值中去掉当前这个值
            if(k[i]>tmp){//如果当前这个值大，代表从当前堆中取走几个，满足所有值的异或为0，就是必败点
                res++;
            }
        }
        if(!ans) cout<<"0"<<endl;
        else cout<<res<<endl;


    }




    return 0;
}