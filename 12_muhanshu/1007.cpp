#include <iostream>
using namespace std;
const int lmax=200000;
int c1[lmax+1],c2[lmax+1];
int main()
{	int n,i,j,k;
    int value[26],num[200];
    for(i=0;i<26;i++){
        value[i]=i+1;
    }
    cin>>n;
	while (n--)
	{	
        for(i=0;i<26;i++){
            cin>>num[i];
        }
        for (i=0;i<=lmax;i++){	
            c1[i]=0;	
            c2[i]=0;		
        }
        for(i=0;i<=num[0]*value[0];i+=value[0]){
            c1[i]=1;
        }
        int sum=value[0]*num[0];
		for (i=1;i<26;i++)
		{	for (j=0;j<=sum;j++)
				for (k=0;k<=value[i]*num[i];k+=value[i])
				{	c2[j+k]+=c1[j];	}
                sum+=value[i]*num[i];
			for (j=0;j<=sum;j++)
			{	c1[j]=c2[j];	c2[j]=0;	}
		}
       
       int res=0;
       for(i=1;i<=50;i++){
           res+=c1[i];
       }
       cout<<res<<endl;
        
	}
	return 0;
}
