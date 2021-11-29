#include<iostream>
//连接所有的村庄，把所有的村庄路径都放到一个结构体数组里，从小到大排序，没连的连上。
#include<algorithm>
using namespace std;
int f[10010]={0};
struct Node
{
    int start,end,dis;
}q[10010];
int cmp(Node a,Node b){
    return a.dis<b.dis;
}

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
    int n;//代表一共有几个村庄
    while(cin>>n){
    int k=0;
    for(int i=1;i<=n;i++){
        f[i]=i;
        for(int j=1;j<=n;j++){
            int tmp;
            cin>>tmp;
            if(j<i){
                q[k].start=i;
                q[k].end=j;
                q[k].dis=tmp;
                k++;
            }

        }
    }
    sort(q,q+k,cmp);
    int m;
    cin>>m;//有几对村庄是连接的
    int a,b;
    while(m--){
        cin>>a>>b;
        merge(a,b);
    }

    int sum=0;
    for(int i=0;i<k;i++){
        if(find(q[i].start)!=find(q[i].end)){
            merge(q[i].start,q[i].end);
            sum+=q[i].dis;
        }
    }
    cout<<sum<<endl;

    }
    return 0;
}