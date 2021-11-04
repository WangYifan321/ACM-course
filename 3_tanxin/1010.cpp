#include<iostream>
#include<algorithm>
using namespace std;
struct Node{
    int id;
    int num;
};
bool cmp(Node node1,Node node2){
    return node1.num>node2.num;
}
int main(){
    int x;
    cin>>x;
    while(x--){
        int n;
        cin>>n;
        Node node[15];
        for(int i=0;i<n;i++){
            node[i].id=i;
            cin>>node[i].num;
        }
        sort(node,node+n,cmp);
        int flag=1;
        int res[15][15]={0};
        while(node[0].num>0 && flag){
            for(int i=1;i<=node[0].num;i++){
                res[node[0].id][node[i].id]=1;
                res[node[i].id][node[0].id]=1;
                
                node[i].num--;
                if(node[i].num<0){
                    flag=0;
                    break;
                }

            }
            node[0].num=0;
            sort(node,node+n,cmp);

        }
        if(flag){
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout<<res[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;

        }else{
            cout<<"NO"<<endl<<endl;
        }



    }

}
