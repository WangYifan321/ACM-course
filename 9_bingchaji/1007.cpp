//还是畅通工程，克鲁斯卡尔求最小生成树
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct Node{
    int x,y,dis;
}q[11000];//注意边的数量
int cmp(Node a,Node b){
    return a.dis<b.dis;
}
int f[110];
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
    }
}
int main(){
    int n;
    while(cin>>n && n){
        for(int i=1;i<=n;i++){
            f[i]=i;
        }
        int m=n*(n-1)/2;
        for(int i=0;i<m;i++){
            cin>>q[i].x>>q[i].y>>q[i].dis;
        }
        sort(q,q+m,cmp);
        int sum=0;
        for(int i=0;i<m;i++){
            if(find(q[i].x)!=find(q[i].y)){
                merge(q[i].x,q[i].y);
                sum+=q[i].dis;
            }
        }
        cout<<sum<<endl;
        


    }
    return 0;

}