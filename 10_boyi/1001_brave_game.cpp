#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main(){
    int c;//c组测试数据
    cin>>c;
    int n,m;//一堆石子一共有n个，每个人可以取走1-m个
    while(c--){
        cin>>n>>m;
        if(n%(m+1)==0){
            cout<<"second"<<endl;
        }else{
            cout<<"first"<<endl;
        }


    }







    return 0;
}