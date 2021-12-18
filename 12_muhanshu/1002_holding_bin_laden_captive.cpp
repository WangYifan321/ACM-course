#include <iostream>
using namespace std;
const int lmax=100010;
int c1[lmax+1],c2[lmax+1];
int main()
{	int n,i,j,k;
    int money[3]={1,2,5},num[3];//存储钱面值的大小和个数
	while (cin>>num[0]>>num[1]>>num[2])
	{	
        if(num[0]==0 && num[1]==0 && num[2]==0){
            break;
        }
        for (i=0;i<=lmax;i++){	
            c1[i]=0;	
            c2[i]=0;		
        }
        for(i=0;i<=num[0];i++){
            c1[i]=1;
        }
        int sum=num[0]*money[0];
		for (i=1;i<3;i++)
		{	for (j=0;j<=sum;j++)
				for (k=0;k<=money[i]*num[i];k+=money[i])
				{	
                    c2[j+k]+=c1[j];   
                }
                sum+=money[i]*num[i];
			for (j=0;j<=sum;j++)
			{	c1[j]=c2[j];	c2[j]=0;/*要不要都行*/	}
		}
        //cout<<sum<<endl;

        for(i=0;i<=sum+1;i++){
            if(c1[i]==0){
                cout<<i<<endl;
                break;
            }
        }
		
	}
	return 0;
}
