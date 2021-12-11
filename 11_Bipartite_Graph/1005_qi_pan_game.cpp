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
    int k,a,b,t=0;
    while(cin>>m>>n>>k){
        memset(map,0,sizeof(map));
        int c=0,l;//Board T(第几组数据) have C(有几个重要点，就是哪个边不能删掉) important blanks for L(最多可以放几个车) chessmen.
        for(int i=0;i<k;i++){
            cin>>a>>b;
            map[a][b]=1;
        }
        l=hungary();
        t++;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(map[i][j]==1){
                    map[i][j]=0;
                    int tmp=hungary();
                    if(tmp!=l){//是重要点，影响结果，不能去掉
                        c++;
                    }
                    map[i][j]=1;
                }
            }
        }
        printf("Board %d have %d important blanks for %d chessmen.\n",t,c,l);


        
    }
    return 0;

}