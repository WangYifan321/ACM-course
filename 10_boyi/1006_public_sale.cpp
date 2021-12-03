#include<iostream>
#include<cstring>
#include<algorithm>
int k[110];
using namespace std;
int main(){
    //拍卖价格大于等于成本价时即卖出
    int m,n;//成本价，加价幅度1-n之间
    while(cin>>m>>n){
        if(n>m){
            while(n>m){
                cout<<m<<" ";
                m++;
            }
            cout<<n<<endl;
        }else{
            if(m%(n+1)==0){
                //所处位置是整数倍，必败点
                cout<<"none"<<endl;
            }else{
                cout<<(m%(n+1))<<endl;

            }
        }
    
    }
    return 0;
}