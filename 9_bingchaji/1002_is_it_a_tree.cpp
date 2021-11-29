#include<iostream>
//判断树：必须有一个根节点，除了根节点其他节点的入度必须为1
using namespace std;
int f[10100];
int in[10100];
int vis[10100];
void init(){
    for(int i=1;i<=10100;i++){
        vis[i]=0;
        in[i]=0;
        f[i]=i;
    }
}

int find(int a){
    while(a!=f[a]) a=f[a];
    return a;
}

void merge(int a,int b){
    int x=find(a);
    int y=find(b);
    if(x==y) return ;
    f[x]=y;

}

int  main(){
    int a,b,ans=1;
    while(cin>>a>>b){
        if(a==-1 && b==-1){
            break;
        }
        if(a==0 && b==0){
            cout<<"Case "<<ans<<" is a tree."<<endl;
            ans++;
            continue;
        }
        
        init();
        vis[a]=1;
        vis[b]=1;
        in[b]++;
        merge(a,b);
        int root=0;//根节点的个数
        int flag=1;//出了根节点外，其他节点的入度需为1
        int counts=0;//通过并查集，看有几个群
         if(a==b){
              flag=0;
            }
        while(cin>>a>>b){
            if(a==0 && b==0) break;

            vis[a]=1;
            vis[b]=1;
            in[b]++;
            merge(a,b);
        }

        
        for(int i=1;i<10100;i++){
            if(vis[i] && in[i]==0){
                root++;
            }
            if(in[i]>=2){
                flag=0;
                break;
            }
            if(vis[i]&&f[i]==i){
                counts++;
            }
        }
        if(root!=1 ||counts>1) flag=0;
        if(flag){
            cout<<"Case "<<ans<<" is a tree."<<endl;
            ans++;
        }else{
            cout<<"Case "<<ans<<" is not a tree."<<endl;
            ans++;
        }



    }
    return 0;
}