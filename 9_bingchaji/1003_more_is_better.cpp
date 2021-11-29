#include<iostream>
using namespace std;
int f[10000010],flag[10000010];
//统计每个群的个数，另外开一个数组，存储每个群里的元素个数即可。初始值设为1，动态维护最大值
int maxn;
int find(int a){
    int i=a,j;
    while(a!=f[a]){
        a=f[a];
    }
    while(i!=a){//路径压缩
        j=f[i];
        f[i]=a;
        i=j;
    }
    return a;
}

void merge(int a,int b){
    int x=find(a);
    int y=find(b);
    if(x!=y){
        f[x]=y;
        flag[y]+=flag[x];
        maxn=max(maxn,flag[y]);
    }
}
int main(){
    int n;
    while(cin>>n){
        maxn=1;
        for(int i=1;i<10000010;i++){
            flag[i]=1;
            f[i]=i;
        }
        int a,b;
        while(n--){
            scanf("%d %d",&a,&b);//cin耗时间，会通不过
            merge(a,b);
        }
        cout<<maxn<<endl;
    }
    return 0;

}