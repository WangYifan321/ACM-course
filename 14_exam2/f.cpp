#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct Node{
   int score;
   int age;
   char name[15];
};

bool cmp(Node a,Node b){
    if(a.age!=b.age) return a.age>b.age;
else
    if(a.score!=b.score) return a.score<b.score;
else
    if(strcmp(a.name,b.name)<0) return true;
    else return false;
}
int main(){
    int c;
    cin>>c;
     while(c--){
         int n,m;
         cin>>n>>m;
    Node node[1011];
    for(int i=0;i<n;i++){
        cin>>node[i].name>>node[i].age>>node[i].score;
    }

    sort(node,node+n,cmp);

    for(int i=0;i<m;i++){
        printf("%s %d %d\n",node[i].name,node[i].age,node[i].score);
    }
    cout<<endl;
    }
    return 0;
}