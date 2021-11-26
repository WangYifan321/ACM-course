#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
struct point {
    int a;
    int b[4];//各个数位的数字
    int sum;
    int tol;
};
point tt[105];
int f[4];
int tag;//是否能确定一个数
int ok;//如果能确认一个数，ok存储它的值

void dfs(int x){
    if(x>9999){
        return;
    }
    f[0]=x%10;
    f[1]=x/10%10;
    f[2]=x/100%10;
    f[3]=x/1000;
    int hj;
    for(int i=0;i<n;i++){
        hj=0;
        int c[5];
        int aa=0,bb=0;//bb相同的数字并且数位相同，aa是相同的数字
        memset(c,0,sizeof(c));
        for(int j=0;j<4;++j){
            if(tt[i].b[j]==f[j]){
                bb++;
            }
        }
        if(bb!=tt[i].tol){ hj=1; break;}
        for(int j = 0;j < 4;j++){
            for(int k = 0;k < 4;k++){
                if(tt[i].b[k]==f[j]&&c[k]==0){
                    aa++;
                    c[k]=1;
                    break;
                }
            }
        }
        if(aa!=tt[i].sum){ hj=1;break; }
    }
    if(hj){dfs(x+1);}
    else{
        tag++;
        ok=x;
        dfs(x+1);
    }
}

int main(){
    while(scanf("%d",&n)!=EOF&&n){
          for(int i = 0;i < n;i++){
            scanf("%d%d%d",&tt[i].a,&tt[i].sum,&tt[i].tol);
            tt[i].b[0]=tt[i].a%10;
            tt[i].b[1]=tt[i].a/10%10;
            tt[i].b[2]=tt[i].a/100%10;
            tt[i].b[3]=tt[i].a/1000;
          }
          tag=0;
          dfs(1000);
          if(tag!=1){
            printf("Not sure\n");
          }
          else{
            printf("%d\n",ok);
          }
    }
    return 0;
}