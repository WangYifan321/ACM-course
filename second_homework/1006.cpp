#include<iostream>
using namespace std;
//抽屉原理，所有的糖果往最多的那个糖果中间插，只要剩下的总糖果数不少于最多的减一即可
//注意sum可能会越界，要用long long
int main(){
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        long long sum = 0;
        int max=0,tmp;
        while(x--){
            cin>>tmp;
            sum+=tmp;
            if(tmp>max){
                max = tmp;
            }
        }
        sum = sum - max;
        if(sum<max-1){
            cout<<"No"<<endl;
        }else{
            cout<<"Yes"<<endl;
        }

    }
    return 0;
}