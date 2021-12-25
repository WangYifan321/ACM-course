#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    getchar();
    while(n--){
        char ctr[50]="";
        gets(ctr);
        //for(int i=0;ctr[i]!='\0';i++)
        //cout<<strlen(ctr)<<endl;
        for(int i=strlen(ctr)-1;i>=0;i--){
            printf("%c",ctr[i]);
        }
        cout<<endl;
    }

    return 0;
}