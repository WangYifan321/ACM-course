#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct Node{
   float score;
   int age;
   char name[20];
};

bool cmp(Node a,Node b){
    if(a.score==b.score && a.age==b.age){
        if(strcmp(a.name,b.name) < 0){
            return true;
        }  else{
            return false;
        }
    }else if(a.score==b.score){
         return a.age<b.age;
    }else{
         return a.score>b.score;
    }
}
int main(){
    int n;
    cin>>n;
    Node node[101];
    for(int i=0;i<n;i++){
        cin>>node[i].name>>node[i].age>>node[i].score;
    }

    sort(node,node+n,cmp);

    for(int i=0;i<n;i++){
        printf("%s %d %.2f\n",node[i].name,node[i].age,node[i].score);
    }

    return 0;
}