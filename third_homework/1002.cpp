#include<iostream>
using namespace std;
//对门构成一个通道，算出所有搬的桌子经过所有的通道，经过最多的那个通道就是最长时间
int main(){
    int x;
    cin>>x;
    while(x--){
        int n;
        cin>>n;
        int id[201]={0};
        while(n--){
            int a,b;
            cin>>a>>b;
            if(a>b){
               int i=a;
               a=b;
               b=i;
            }
            for(int i=(a+1)/2;i<=(b+1)/2;i++){
                id[i]++;
            }


        }
        int max=0;
        for(int i=0;i<201;i++){
            if(max<id[i]){
                max=id[i];
            }
        }
        cout<<max*10<<endl;
    }
    return 0;
}