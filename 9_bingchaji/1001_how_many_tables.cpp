#include<iostream>

using namespace std;
int f[1100];//并查集维护的数组
int find(int a){
    while(a!=f[a]){
        a=f[a];
    }
    return a;
}
void merge(int a,int b){
    int c=find(a);
    int d=find(b);
    f[d]=c;
}
int main(){
    int p;
    cin>>p;
    while(p--){
        int n,m;
        cin>>n>>m;
        //初始化
        for(int i=1;i<=n;i++){
            f[i]=i;
        }
        while(m--){
            int x,y;
            cin>>x>>y;
            merge(x,y);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(i==f[i]) ans++;
        }
        cout<<ans<<endl;

    }
}