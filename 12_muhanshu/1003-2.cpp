#include<stdio.h>
#include<string.h>
int c1[200000],c2[200000];
int a[200],c[200];
int main()
{
	int n,i,j,sum,k;
	while(scanf("%d",&n)!=EOF)
	{
		if(n<0) break ;
		sum=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d %d",&a[i],&c[i]);
			sum+=a[i]*c[i];
		}
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		for(i=0;i<=a[1]*c[1];i+=a[1])//
		{
			c1[i]=1;
		}
		for(i=2;i<=n;i++)
		{
			for(j=0;j<=sum;j++)
				for(k=0;k<=a[i]*c[i]&&k+j<=sum;k+=a[i])//不是k++ 而是加a[i]
					c2[k+j]+=c1[j];
				for(j=0;j<=sum;j++)
				{
					c1[j]=c2[j];
					c2[j]=0;
				}
		}
		for(i=sum/2;i>0;i--)	
		{
			if(c1[i]!=0)	
				break;	
		}
		printf("%d %d\n",sum-i,i);
	}
	return 0;
}