#include<iostream>
#include<cstring>
#include<algorithm>
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
    int n,m;//学校的数目，道路的数目
    f[0]=0;
    while(cin>>n>>m){
        for(int i=1;i<=n;i++){
            f[i]=i;
        }
        int a,b;
        while(m--){
            cin>>a>>b;
            if(find(a)==0)
            merge(a,b);
            else if(find(b)==0){
                merge(b,a);
            }else{
                merge(a,b);
            }

        }
        int res=0;
        for(int i=1;i<=n;i++){
            if(find(i)!=0){
                res++;
            }
        }
        cout<<res<<endl;
    }
    

    return 0;
}