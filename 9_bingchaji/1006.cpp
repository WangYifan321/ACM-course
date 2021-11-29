//畅通工程
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int f[1010];
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
    int n,m;
    while(cin>>n && n){
        for(int i=1;i<=n;i++){
            f[i]=i;
        }
        cin>>m;
        while(m--){
            int a,b;
            cin>>a>>b;
            merge(a,b);
        }
        int sum=0;
        for(int i=1;i<=n;i++){
            if(i==f[i]){
                sum++;
            }
        }
        cout<<sum-1<<endl;



    }
    return 0;

}