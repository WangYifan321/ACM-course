#include<iostream>
#include<algorithm>
//��ͼ���ж�������֤����ż����������һ��С�����е���֮�ͣ�Ȼ��һ�������ͺ��ˣ������һ������Ϊ3���Ӵ�С����������������ֱ𶼼�һ��һ��������������
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int f=0;
        int x;
        cin>>x;
        int num[1010];
        int sum=0;
        for(int i=0;i<x;i++){
            cin>>num[i];
            sum+=num[i];
        }
        sort(num,num+x,cmp);
        if(sum%2==1 || num[0]>x-1 || num[0]==0){
            cout<<"no"<<endl;
        }else{
        for(int i=0;i<x;i++){
            if(num[0]>0){
            int flag=0;
            int tmp=num[0];
            for(int j=1;j<x;j++){
                if(num[j]>=1){
                    num[j]--;
                    num[0]--;
                    flag++;
                    if(flag==tmp) break;
                }
            }//443322 432212 431102 431111 431110 032212  322210 011110 111100  
            if(flag<tmp){
                cout<<"no"<<endl;
                f=1;//防止某些脏数据输出两遍
                break;
            }
            }
            sort(num,num+x,cmp);
        }
        if(f==0){
        if(num[0]==0){
            cout<<"yes"<<endl;
        }else {
            cout<<"no"<<endl;
        }
        }


    }

}
        return 0;
}
//443322   432212 1101 101 2111 001 