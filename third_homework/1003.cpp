#include<iostream>
#include<algorithm>
using namespace std;
struct Node{
    int a,b;
}node[1001];
bool cmp(Node node1,Node node2){
    if(node1.b!=node2.b){
        return node1.b>node2.b;
    }else{
        return node1.a<node2.a;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int flag[1001]={0};

        for(int i=0;i<n;i++){
           int a;
           cin>>a;
           node[i].a=a;
        }
        for(int i=0;i<n;i++){
            int b;
            cin>>b;
            node[i].b=b;
        }
        sort(node,node+n,cmp);
        int ans=0;
        for(int i=0;i<n;i++){
            int j=node[i].a;
            for(;j>0;j--){
                if(flag[j]==0){
                    flag[j]=1;
                    j=-1;
                    break;
                }
            }
            if(j!=-1){ 
                ans+=node[i].b;

            }

        }
        cout<<ans<<endl;
    }
    return 0;
}
//7 6 5 4 3 2 1
//4 2 3 1 - - 6