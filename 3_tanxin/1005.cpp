#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int x;
    while(cin>>x){
        if(x==0){
            return 0;
        }else{
            int t[1010];
            int k[1010];
            int n=x;//每个人都有n匹马
            for(int i=0;i<n;i++){
                cin>>t[i];
            }
            for(int i=0;i<n;i++){
                cin>>k[i];
            }
            sort(t,t+n);
            sort(k,k+n);
            int ts=0,td=n-1,ks=0,kd=n-1,ty=0,ky=0;//田忌小马、大马，国王小马、大马，田忌赢的次数，国王赢得次数
            while(ts<=td){
                if(t[ts]>k[ks]){
                    ty++;
                    ts++;
                    ks++;
                }else if(t[ts]<k[ks]){
                    ky++;
                    ts++;
                    kd--;
                }else{
                    //if(ts==td) break;//关键---易错点
                    if(t[td]>k[kd]){
                        ty++;
                        td--;
                        kd--;
                    }else 
                    {
                        if (t[ts]<k[kd])//易错点
                        ky++;
                        ts++;
                        kd--;
                    }
                }
            }
            cout<<(ty-ky)*200<<endl;

        }
    }



    return 0;
}
/*
总结：如果小马相等且都是最后一匹马时可以直接推出
      小马相等比大马比不过时不一定输，如样例第二个，有相等的情况，肯定是小马去碰大马，但是不一定输
*/

