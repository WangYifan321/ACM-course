#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

//匈牙利算法
int n,m;//左侧元素、右侧元素的数量
int map[150][150];//邻接矩阵
int vis[150];//记录右侧元素是否已经被访问过
int p[150];//记录当前右侧元素所对应的左侧元素
bool dfs(int i){
    for(int j=1;j<=n;j++){
        if(map[i][j] && !vis[j]){
            vis[j]=1;
            if(p[j]==-1 || dfs(p[j])){
                p[j]=i;
                return true;
            }
        }
    }
    return false;

}

int hungary(){
    int res=0;
    memset(p,-1,sizeof(p));
    for(int i=1;i<=m;i++){
        memset(vis,0,sizeof(vis));
        if(dfs(i)) res++;
    }
    return res;


}
int main(){
    int k,a,b,id,num;
    cin>>num;
    while(num--){
        memset(map,0,sizeof(map));
        cin>>m;
        n=m;
        cin>>k;
        while(k--){
            cin>>a>>b;
            map[a][b]=1;
        }
        cout<<n-hungary()<<endl;
    }
    return 0;

}