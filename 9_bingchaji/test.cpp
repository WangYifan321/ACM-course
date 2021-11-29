#include<iostream>
using namespace std;
 
const int maxn=10000;
int father[maxn];
int inDegree[maxn]; //节点入度
bool vis[maxn];   //是否是出现过的节点
int n=0;
 
void init(){   //初始化
    for(int i=0;i<maxn;i++){
        father[i]=i;
        inDegree[i]=0;
        vis[i]=false;
    }
}
 
int findFather(int x){   //寻找父节点
    int a=x;
    while(x!=father[x]){
        x=father[x];
    }
    while(a!=father[a]){  //合并路径
        int z=a;
        a=father[a];
        father[z]=x;
    }
    return x;
}
 
void Union(int a,int b){
    int faA=findFather(a);
    int faB=findFather(b);
    if(faA!=faB)
        father[faA]=faB;
}
 
bool isTree(){
    int component=0;  //连通分量个数
    int root=0;       //根节点个数
    bool flag=true;
    for(int i=0;i<=n;i++){
        if(vis[i]==false){
            continue;
        }
        if(father[i]==i){
            component++;
        }
        if(inDegree[i]==0){
            root++;
        }else if(inDegree[i]>1){
            flag=false;
        }
    }
    if(component!=1||root!=1)
        flag=false;
    if(component==0&&root==0)
        flag=true;
    return flag;
}
 
int main(){
    int a,b;
    int current=0;
    init();
    while(scanf("%d %d",&a,&b)!=EOF){
        if(a==-1&&b==-1)
            break;
        else if(a==0&&b==0){
            if(isTree()){
                printf("Case %d is a tree.\n",++current);
            }else{
                printf("Case %d is not a tree.\n",++current);
            }
            init();
        }else{
            Union(a,b);
            inDegree[b]++;
            vis[a]=true;
            vis[b]=true;
            n=max(n,a);
            n=max(n,b);
        }
    }
}