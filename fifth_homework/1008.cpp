#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int j=0;j<n;j++){
        int num;
        cin>>num;
        int pre=0,max=-100001,start,end,s,e,tmp;
        for(int i=0;i<num;i++){
            int a;
            cin>>a;
            if(i==0) start=i+1;//第一个数特殊处理
            if(pre+a>=a){
                pre+=a;
                end=i+1;
            }else{
                pre=a;
                start=i+1;
                end=i+1;
            }
            if(pre>max){
                max=pre;
                s=start;
                e=end;
            }
        }
        printf("Case %d:\n%d %d %d\n",j+1,max,s,e);
        if(j<n-1)
        printf("\n");

    }
}
