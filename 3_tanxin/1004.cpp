#include<iostream>
#include<algorithm>
using namespace std;
//最优解是对结束时间进行排序，我刚开始是对节目时间进行排序，可能也能做，但是麻烦
struct Node{
    int a,b;
};
bool cmp(Node node1,Node node2){
    return node1.b<node2.b;
}
int main(){
    int x;
    while(cin>>x){
  
        if(x==0){
            return 0;
        }else{
            Node node[105];
            for(int i=0;i<x;i++){
                cin>>node[i].a>>node[i].b;
            }
            sort(node,node+x,cmp);
            int num=1;
            int t=node[0].b;
            for(int i=1;i<x;i++){
               if(t<=node[i].a){
                   num++;
                   t=node[i].b;
               }
            }
            cout<<num<<endl;


        }
    }
    return 0;

}
/*
2 -
1 -
7
5
4 -
5 
5 -
10
6
5 -
10
7




*/