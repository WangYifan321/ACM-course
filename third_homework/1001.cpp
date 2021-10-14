#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Node{
    int j,f;
    double p;
};
bool cmp (Node a,Node b){
    return a.p<b.p;
}
int main(){
    int m,n;
    while(cin>>m>>n){
        if(m == -1 && n == -1){
            return 0;
        }else{
            vector<Node> nodes;
            for(int i=0;i<n;i++){
                int a,b;
                cin>>a>>b;
                double c = (b*1.0)/(a*1.0);
                Node node;
                node.f=b;
                node.j=a;
                node.p=c;
                nodes.push_back(node);
            }
            sort(nodes.begin(),nodes.end(),cmp);
            double sum=0;
            for(int i=0;i<nodes.size();i++){
                if(m>=nodes[i].f){
                   sum+=nodes[i].j;
                   m=m-nodes[i].f;
                }else if(m>0 && m<nodes[i].f){
                    sum+=(m*1.0)/nodes[i].p;                   
                    break;
                }
            }
            printf("%.3f\n",sum);

        }
    }

    
    return 0;
}