#include<stdio.h>
#include<math.h>
void main(){
    double x1,y1,x2,y2,m;
    while(scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2)==4){
       m = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
       printf("%.2f\n",m);
    }
}