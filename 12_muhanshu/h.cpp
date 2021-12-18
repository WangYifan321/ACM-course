#include<stdio.h>
#include<string.h>
const int MAXN=100010;
int a[MAXN],b[MAXN];
int main(){
    int x,y,z,sum;
    int money[3],t[3];
    while(scanf("%d%d%d",&x,&y,&z),x||y||z){
        memset(a,0,sizeof(a));memset(b,0,sizeof(b));//初始化。。。
        for(int i=0;i<=x;i++)a[i]=1,b[i]=0;
        t[0]=x;t[1]=y;t[2]=z;
        money[0]=1;money[1]=2;money[2]=5;
        sum=money[0]*t[0];
        for(int i=1;i<3;i++){
        for(int j=0;j<=sum;j++)
            for(int k=0;k<=money[i]*t[i];k+=money[i])
                b[j+k]+=a[j];
                sum+=money[i]*t[i];
            for(int j=0;j<=sum;j++)
                a[j]=b[j];
        }
        printf("%d\n",sum);
        for(int i=0;i<=sum+1;i++)
            if(!a[i]){
                printf("%d\n",i);
                break;
            }
    }
    return 0;
}