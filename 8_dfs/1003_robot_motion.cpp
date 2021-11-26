#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char map[15][15];
int m,n,s;//行数，列数，从第几个开始
int d[15][15];

void dfs(int i,int j,int steps){
    if(i<1 || j<1 || i>m || j>n){
        cout<<steps<<" step(s) to exit"<<endl;
        return;
    }
    if(d[i][j]!=-1){
        cout<<d[i][j]<<" step(s) before a loop of "<<steps-d[i][j]<<" step(s)"<<endl;
        return;
    }
    d[i][j]=steps;
    if(map[i][j]=='N'){
        dfs(i-1,j,steps+1);
    }else if(map[i][j]=='S'){
        dfs(i+1,j,steps+1);
    }else if(map[i][j]=='E'){
        dfs(i,j+1,steps+1);
    }else{
        dfs(i,j-1,steps+1);
    }

}

int main(){
    while(cin>>m>>n){
        if(m==0 || n==0) return 0;
        cin>>s;
        memset(d,-1,sizeof(d));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                cin>>map[i][j];
            }
        }
        dfs(1,s,0);
    }
    return 0;
}