#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

//匈牙利算法
int n,m;//左侧元素、右侧元素的数量
int map[550][550];//邻接矩阵
int vis[550];//记录右侧元素是否已经被访问过
int p[550];//记录当前右侧元素所对应的左侧元素
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
    int k,a,b;
    while(cin>>k && k){
        cin>>m>>n;
        memset(map,0,sizeof(map));
        while(k--){
            cin>>a>>b;
            map[a][b]=1;
        }
        cout<<hungary()<<endl;
    }
    return 0;

}