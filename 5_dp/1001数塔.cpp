#include<iostream>
using namespace std;
//递归会超时
/*
int fun(int i,int j){
    if(i==7){
        return data[i][j];
    }
    return data[i][j]+max(fun(i+1,j),fun(i+1,j+1));
}*/

int main(){
    int x;
    cin>>x;//一共x组数据
    while(x--){
        int n;//一组数据的数塔有多少层
        cin>>n;
        int data[101][101]={0};
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                cin>>data[i][j];
            }
        }

        for(int i=n-1;i>0;i--){
            for(int j=i;j>0;j--){
                data[i-1][j-1]+=max(data[i][j],data[i][j-1]);
            }
        }
        cout<<data[0][0]<<endl;
    }
    return 0;
}