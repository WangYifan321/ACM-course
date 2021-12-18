#include <iostream>
using namespace std;
const int lmax=200000;
int c1[lmax+1],c2[lmax+1];
int main()
{	int n,i,j,k;
    int value[200],num[200];
    
	while (cin>>n && n!=0)
	{	
        for(i=0;i<n;i++){
            cin>>value[i]>>num[i];
        }
        for (i=0;i<=lmax;i++){	
            c1[i]=0;	
            c2[i]=0;		
        }
        for(i=0;i<=num[0]*value[0];i+=value[0]){
            c1[i]=1;
        }
        int sum=value[0]*num[0];
		for (i=1;i<n;i++)
		{	for (j=0;j<=sum;j++)
				for (k=0;k<=value[i]*num[i];k+=value[i])
				{	c2[j+k]+=c1[j]%10000;	}//注意取余的位置，最后再取余会wrong的
                sum+=value[i]*num[i];
			for (j=0;j<=sum;j++)
			{	c1[j]=c2[j]%10000;	c2[j]=0;	}
		}
       if(sum%3==0){
           if(c1[sum/3]==0){
               cout<<"sorry"<<endl;
           }else{
               cout<<c1[sum/3]<<endl;
           }
       }else{
           cout<<"sorry"<<endl;
       }
        
	}
	return 0;
}
