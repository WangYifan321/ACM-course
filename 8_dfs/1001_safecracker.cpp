#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 26

#define res(v,w,x,y,z) v-w*w+x*x*x-y*y*y*y+z*z*z*z*z
using namespace std;
bool isvisited[maxn];
long long target;
char str[maxn];
int l[26];

bool cmp(char a,char b){
    return a>b;
}


//深搜枚举
bool dfs( int k){
    if(k==5){
        long long temp=res(l[0],l[1],l[2],l[3],l[4]);
            if(temp==target)
                return true;
        return false;
    }
    else{
        for(int i=0;i<strlen(str);i++){
            if(isvisited[i]==false){
                isvisited[i]=true;
                l[k]=str[i];
                if(dfs(k+1)) return true;
                isvisited[i]=false;
            }
        }
    }
    return false;
}


int main(){
    while(scanf("%lld%s",&target,str)!=EOF&&target!=0&&strcmp("END",str)!=0){
        memset(isvisited,false,sizeof(isvisited));
        memset(l,0,sizeof(l));
        //先对数组进行排序后得到的就是最大的
        sort(str,str+strlen(str),cmp);
        for(int i=0;i<strlen(str);i++)
            str[i]=str[i]-'A'+1;
        if(dfs(0))
                for(int i=0;i<5;i++)
                    printf("%c",l[i]+'A'-1);
        else
            printf("no solution");
        printf("\n");
    }
 return 0;
}


