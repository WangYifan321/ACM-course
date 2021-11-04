#include<iostream>
#include<algorithm>
using namespace std;
struct Node{
    int p;//单价
    int h;//对应大米的重量
};
bool cmp(Node node1,Node node2){
    return node1.p<node2.p;
}
int main(){
    int x;
    cin>>x;
    while(x--){
       int n,m;
       cin>>n>>m;
       double sum=0.0;//买的最多的重量
       Node node[1010];
       for(int i=0;i<m;i++){
           cin>>node[i].p>>node[i].h;
       }
       sort(node,node+m,cmp);
       for(int i=0;i<m;i++){
           if(n==0){
               printf("%.2f\n",sum);
               break;
           }else if(n>(node[i].h*node[i].p)){
               n=n-node[i].h*node[i].p;
               sum+=node[i].h;
           }else{
               sum+=(n*1.0)/(node[i].p*1.0);
               n=0;
           }
       }
    }
    return 0;
}