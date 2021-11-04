#include<iostream>
#include<algorithm>
using namespace std;
int dp[1001];//表示以i结尾的最长子序列长度
int f[1001];//记录i对应的上一个数据
int s[1001];//从后往前找时，存放最终结果下标
struct Mouse
{
 int w,s;//重量和速度
 int num;//记录排序之前的位置
}mouse[1001];
int cmp(Mouse a,Mouse b)//先按w从大到小排，再按r从小到大排
{
 if(a.w<b.w||a.w==b.w&&a.s>b.s) return 1;
 return 0;
}
int main()
{
 int n,m,x,y,i,j,min,maxlen,maxi;
 n=0;
 while(scanf("%d%d",&x,&y)!=EOF && x)
 {
  n++;
  dp[n]=1;f[n]=0;
  mouse[n].w=x;
  mouse[n].s=y;
  mouse[n].num=n;
 }
 sort(mouse+1,mouse+n+1,cmp);//排序
 dp[1]=1;dp[0]=0;
 maxlen=1;//最长序列长度
 maxi=1;//最长序列最后一个下标
 for(i=1;i<=n;i++)
 {
  min=0;
  for(j=1;j<i;j++)
   if(mouse[j].w<mouse[i].w && mouse[j].s>mouse[i].s && dp[j]+1>dp[i]&&dp[j]>dp[min]) min=j;
   if(min!=0)
   {
    dp[i]=dp[min]+1;
    f[i]=min;
    if(dp[i]>maxlen)
    {
     maxi=i;
     maxlen=dp[i];
    }
   }

 }
 m=0;
 while(maxlen>0)//保存到s[m]
 {
  m++;
  s[m]=maxi;
  maxi=f[maxi];
  maxlen--;
 }
 cout<<m<<endl;
 while(m>0)
 {
  cout<<mouse[s[m]].num<<endl;
  m--;
 }
 return 0;

}