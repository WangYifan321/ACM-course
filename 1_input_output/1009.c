#include<stdio.h>
int main(){
    int x;
    while(scanf("%d",&x)==1){
        int sum=0;
        while(x>0){
            sum+=x;
            x--;
        }
        printf("%d\n\n",sum);
    }
    return 0;
}