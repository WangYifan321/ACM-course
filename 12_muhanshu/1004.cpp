#include <iostream>
using namespace std;
const int lmax=200000;
int c1[lmax+1],c2[lmax+1];
int main()
{	int n,i,j,k;
    int value[200],num[200];
    cin>>n;
	while (n--)
	{	
        int a,b;
        cin>>a>>b;
        for(i=0;i<b;i++){
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
		for (i=1;i<b;i++)
		{	for (j=0;j<=sum;j++)
				for (k=0;k<=value[i]*num[i];k+=value[i])
				{	c2[j+k]+=c1[j];	}
                sum+=value[i]*num[i];
			for (j=0;j<=sum;j++)
			{	c1[j]=c2[j];	c2[j]=0;	}
		}
       cout<<c1[a]<<endl;
        
	}
	return 0;
}
