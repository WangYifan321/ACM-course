#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
int k[110];
using namespace std;
int main(){
    int n,m;
    while(cin>>n>>m && n && m){
        if(n%2==0||m%2==0)
          {
             printf("Wonderful!\n");
         }else
         {
             printf("What a pity!\n");
         }
    }
    

    return 0;
}