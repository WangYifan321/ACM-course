#include<iostream>
using namespace std;
int a[104][100];//卡特兰数，一共105个，每一个最多可以表示105位
int b[100];//对应卡特兰数的位数
//公式：f(n)=f(n-1)*(4*n-2)/(n+1)
void catalan(){
    a[1][0]=b[1]=1;
    int carry,len,temp;
    len=1;
    for(int i=2;i<=100;i++){
        carry=0;
        for(int j=0;j<len;j++){
            temp=carry+a[i-1][j]*(4*i-2);
            a[i][j]=temp%10;
            carry=temp/10;
        }//求卡特兰数第一步，乘法
        while(carry){//处理高位
            a[i][len++]=carry%10;
            carry/=10;
        }
        carry=0;
        for(int j=len-1;j>=0;j--){//大数除法
            temp=carry*10+a[i][j];
            carry=temp%(i+1);
            a[i][j]=temp/(i+1);
        }
        while(!a[i][len-1])//处理掉高位的0
        len--;
        b[i]=len;
    }

}
int main(){
    int n;
    catalan();
    while(cin>>n){
        if(n==-1)
        break;
        for(int i=b[n]-1;i>=0;i--){
            cout<<a[n][i];
        }
        cout<<endl;
    }
    return 0;
}
