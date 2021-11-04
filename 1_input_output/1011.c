#include<stdio.h>
int main(){
    int x;
    while(scanf("%d",&x)==1){
        if(x>100 || x<0){
            printf("Score is error!\n");
        }else if(x<60){
            printf("E\n");
        }else if(x<70){
            printf("D\n");
        }else if(x<80){
            printf("C\n");
        }else if(x<90){
            printf("B\n");
        }else{
            printf("A\n");
        }
    }
    return 0;
}