#include<iostream>
#include<algorithm>
using namespace std;
int dp[1001];
int f[1001];//存储当前点的前一个点
struct Mouse
{
    int w,s;//重量和速度
    int num;//因为要重新排序，而 输出的是他们输入的相对位置，所以要记录一下位置
};
Mouse mouse[1001];
int cmp(Mouse a,Mouse b){
    if(a.w==b.w) return a.s>b.s;
    return a.w<b.w;
}

int main(){
    int x,y,n=0;
    while(cin>>x>>y && x){
        n++;
        dp[n]=1;
        f[n]=0;
        mouse[n].num=n;
        mouse[n].s=y;
        mouse[n].w=x;
    }
    sort(mouse+1,mouse+1+n,cmp);
    int maxi,maxlen=0;//分别存储最长的那个位置的下标，最大的长度。
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(mouse[j].w<mouse[i].w && mouse[j].s>mouse[i].s && dp[j]+1>dp[i]){
                dp[i]=dp[j]+1;
                if (dp[i]>maxlen){
                    maxlen=dp[i];
                    maxi=i; 
                }
                f[i]=j;
                       
            }
        }
    }
    cout<<maxlen<<endl;
    int res[1001];
    int i=0;
    while(maxlen>0){
        i++;
        res[i]=maxi;
        maxi=f[maxi];
        maxlen--;
    }
    while(i>0){
        cout<<mouse[res[i]].num<<endl;
        i--;
    }
    return 0;
}
