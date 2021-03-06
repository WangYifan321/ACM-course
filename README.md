# ACM-course

# 输入输出

```shell
	1001	A+B for Input-Output Practice (I)
	1002	A+B for Input-Output Practice (II)	
	1003	A+B for Input-Output Practice (III)
	1004	A+B for Input-Output Practice (IV)
	1005	A+B for Input-Output Practice (V)	51.34%(96/187)
	1006	A+B for Input-Output Practice (VI)	57.31%(98/171)
	1007	A+B for Input-Output Practice (VII)	58.23%(92/158)
	1008	A+B for Input-Output Practice (VIII)	
	1009	Sum Problem
	1010	计算两点间的距离	
	1011	成绩转换	
	1012	求奇数的乘积
```



# 快速幂

```shell
	1001->Sum Problem              求和公式的运用
	1002->Elevator
	1003->Least Common Multiple    辗转相除法求最小公倍数
	1004->Number Sequence          程序找循环节
	1005->Fibonacci Again          循环
	1006->吃糖果                 	抽屉原理往里插，要用Long long
	1007->人见人爱A^B               快速幂
	1008->Rightmost Digit     	   快速幂
	1009->最小公倍数
	1010->求数列的和
```

```cpp
//求最小公倍数和最大公约数
#include<iostream>
using namespace std;
int gcd(int a,int b){
    while(a%b!=0){
        int flag = a;
        a = b;
        b = flag%b;

    }
    return b;
}
int lcm(int a,int b){
    return a/gcd(a,b)*b;
}
int main(){
    int a,b;
    while(cin>>a>>b){
        cout<<lcm(a,b)<<endl;
    }
    return 0;
}
```

```cpp
//快速幂非递归
#include<iostream>
using namespace std;
int fast(int a,int b){
    int ans=1;
    a=a%10;
    while(b>0){
        if(b%2==1){
            ans=(ans*a)%10;

        }
        b=b/2;
        a=(a*a)%10;

    }
    return ans;
}
int main(){
    int x;
    cin>>x;
    while(x--){
        int a;
        cin>>a;
        cout<<fast(a,a)<<endl;
    }
    return 0;
}
```

# 贪心

算法前提------排序（浮点数比较|x-y|<0.000001，就代表两个数一样，double有精度损失）

可图化

HDOJ-1007:QuoitDesign

```shell
	1001    FatMouse'Trade
	1002	Moving Tables
	1003	Doing Homework again
	1004	今年暑假不AC					对结束时间排序
	1005	Tian Ji -- The Horse Racing	 
	1006	Degree Sequence of Graph G	
	1007	Quoit Design				最近距离的点对问题，分治法
	1008	Fighting for HDU
	1009	悼念512汶川大地震遇难同胞——老人是真饿了
	1010	Frogs' Neighborhood			 数列能否构成简单图
```

## 最近点对问题

写特殊情况，一个点、两个点、三个点

递归调用，分治法，得到左面和右面两部分的最小值，取最小。在左面和右面的点中找出距离mid小于最小值的点，存入一个新的数组。把这个数组按y排序，便利这个数组求最小值。

（也可以按x排序，只求相邻的两个点，找最小值，然后按y排序，遍历下去求相邻的最小值）

# 动态规划

递推，找出第n项和前几项的关系，写出方程求解

空间换时间，数据不多时，存到数组里面，后面直接查

## 折线分割平面

直线分割：多一条线，一定与其他n-1条线相交，因此有n-1个交点，多出来n条直线。故f(n)=f(n-1)+n   化简的f(n)=(n*n+n+2)/2 析:可能你以前就见过这题目，这充其量是一道初中的思考题。但一个类型的题目还是从简单的入手，才容易发现规律。当有n-1条直线时，平面最多被分成了f（n-1）个区域。则第n条直线要是切成的区域数最多，就必须与每条直线相交且不能有同一交点。 这样就会得到n-1个交点。这些交点将第n条直线分为2条射线和n-2条线断。而每条射线和线断将以有的区域一分为二。这样就多出了2+（n-2）个区域。
故：f(n)=f(n-1)+n
=f(n-2)+(n-1)+n
……
=f(1)+1+2+……+n
=n(n+1)/2+1

两条平行线分割：把2n带入上面的公式中，但是平行线分割出的平面会少n个故f(n)=2n*n+1

折线分割：根据直线分平面可知，由交点决定了射线和线段的条数，(一个交点就是一条线段)进而决定了新增的区域数。当n-1条折线时，区域数为f（n-1）。为了使增加的区域最多，则折线的两边的线段要和n-1条折线的边，即2*（n-1）条线段相交。那么新增的线段数为4*（n-1），射线数为2。但要注意的是，折线本身相邻的两线段只能增加一个区域。
故：f(n)=f(n-1)+4(n-1)+2-1
=f(n-1)+4(n-1)+1
=f(n-2)+4(n-2)+4(n-1)+2
=f(1)+4+4*2+……+4(n-1)+(n-1)
=2n^2-n+1

## 卡特兰数

**1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, 742900, 2674440, 9694845, 35357670, 129644790, 477638700**

令h(0)=1,h(1)=1，Catalan数满足递推式：h(n)= h(0)*h(n-1)+h(1)*h(n-2) + ... + h(n-1)*h(0) (n>=2)
例如：

h(2)=h(0)*h(1)+h(1)*h(0)=1*1+1*1=2
h(3)=h(0)*h(2)+h(1)*h(1)+h(2)*h(0)=1*2+1*1+2*1=5
**另类递推式：h(n)=h(n-1)*(4*n-2)/(n+1)**
递推关系的解为：h(n)=C(2n,n)/(n+1) (n=0,1,2,...)
递推关系的另类解为：h(n)=C(2n,n)-C(2n,n+1)(n=0,1,2,...)

卡特兰数求前三十项可以用int64求，太大的话要用大数乘除法

大数卡特兰模板

```c
#include<iostream>
#include<string.h>
using namespace std;
int a[104][100];//保存卡特兰数
int b[100];//卡特兰数的位数
void catalan() //求卡特兰数模板
{
    int i, j, len, carry, temp;
    a[1][0] = b[1] = 1;
    len = 1;
    for(i = 2; i <= 100; i++)
    {
        for(j = 0; j < len; j++) //乘法
        a[i][j] = a[i-1][j]*(4*(i-1)+2);
        carry = 0;
        for(j = 0; j < len; j++) //处理相乘结果
        {
            temp = a[i][j] + carry;
            a[i][j] = temp % 10;
            carry = temp / 10;
        }
        while(carry) //进位处理
        {
            a[i][len++] = carry % 10;
            carry /= 10;
        }
        carry = 0;
        for(j = len-1; j >= 0; j--) //除法
        {
            temp = carry*10 + a[i][j];
            a[i][j] = temp/(i+1);
            carry = temp%(i+1);
        }
        while(!a[i][len-1]) //高位零处理
        len --;
        b[i] = len;
    }
}
int main()
{
	int n,i,j;
	catalan();
	while(cin>>n)
	{
		if(n==-1) break;
		for(i=b[n]-1;i>=0;i--)
			cout<<a[n][i];
		cout<<endl;
	}
	return 0;
}

```



```
1001	超级楼梯	
1002	一只小蜜蜂...	
1003	不容易系列之(3)—— LELE的RPG难题	
1004	骨牌铺方格	
1005	折线分割平面	
1006	母牛的故事	
1007	悼念512汶川大地震遇难同胞——重建希望小学	
1008	Tiling_easy version	
1009	统计问题	
1010	小兔的棋盘	卡特兰数
1011	Game of Connections  卡特兰数，以一个点为基点，分成两部分
```

https://blog.csdn.net/doc_sgl/article/details/8880468卡特兰数经典题型

数塔问题和掉馅饼问题都是倒着往前推，构建一个二维数组。因为后面的不对前面的产生影响永远都是最优解。分析最后一个结果的来源，取最大值。比如掉馅饼问题中最后一个结果的来源只能是j，j-1，j+1位置的馅饼数，加上本身的，把每一层的都算出来，就可以得到答案。





```shell
1001	数塔	      动态规划二位数组
1002	免费馅饼	类似于数塔
1003	Super Jumping! Jumping! Jumping!   最长不连续增数列，一维数组
1004	搬寝室		二维数组，一个物品对数，一个总物品数
1005	Humble Numbers	由前面的数乘来，分别取min
1006	FatMouse's Speed	排序结构体，最长不连续序列，一维数组
1007	Common Subsequence	字符串，二维数组，两个维度分别为两个字符串的长度，加一个字符串有两种情况，一样或不一样
1008	Max Sum	
1009	威威猫系列故事——打地鼠
```

感觉递归就是遍历的改进，采用了空间换时间的策略，存储之前遍历的过程。所以一般都要开一个dp一维或二维数组、进行取大或取校的操作。从后往前推，找出n和前面几个的关系，就得出来了递推公式，问题就解决了、、。



# 背包

```shell
1001	Bone Collector	简单的01背包
1002	Piggy-Bank	完全背包且必须装满
1003	悼念512汶川大地震遇难同胞——珍惜现在，感恩生活	多重背包
1004	Big Event in HDU	完全背包
1005	寒冰王座	简单的01背包
1006	湫湫系列故事——减肥记I	多重背包
1007	I NEED A OFFER!	   01背包变形。取大改为取小
1008	FATE 二维背包
```

> 背包的第一层循环为物品的数量，第二层为背包的所有大小



如果问题是背包必须装满的话可以设置dp数组的所有值为最大值或者最小值。dp[0]=0。这样如果最后dp[背包容量]还是最大或最小值就代表装不满。

## 01背包

```bash
f[i][v]=max{f[i-1][v],f[i-1][v-c[i]]+w[i]}
```



>  每个物品最多只能放一次

```cpp
#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int x;
    cin>>x;
    int v[1010],w[1010],dp[1010];
    while(x--){
        int n,m;
        cin>>n>>m;
        memset(v,0,sizeof(v)); 
        memset(w,0,sizeof(w));
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        cin>>w[i];//输入价值
        for(int i=0;i<n;i++)
        cin>>v[i];//输入体积
        for(int i=0;i<n;i++){
            for(int j=m;j>=v[i];j--){
                dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
            }
        }

        cout<<dp[m]<<endl;
    }
    return 0;
}
```

## 完全背包

> 每种物品可以放无限多次

```bash
f[i][v]=max{f[i-1][v-k*c[i]]+k*w[i]|0<=k*c[i]<=v}
f[i][v]=max{f[i-1][v],f[i][v-c[i]]+w[i]}
```

相比于01背包，完全背包不同的是选过的物品还可以再选。

```cp
#include<iostream>
#include<cstring>
using namespace std;
const int INF=0x3f3f3f3f;
//完全背包且必须装满
int v[10010];
int w[10010];//硬币的面值，重量
int dp[1001000];
int main(){
    int k;
    cin>>k;
    while(k--){
        int a,b;
        cin>>a>>b;
        int ans=b-a;
        int c;
        cin>>c;

        for(int i=0;i<c;i++){
            cin>>v[i]>>w[i];
        }
        memset(dp,INF,sizeof(dp));
        dp[0]=0;
        for(int i=0;i<c;i++){
            for(int j=w[i];j<=ans;j++){
                dp[j]=min(dp[j],dp[j-w[i]]+v[i]);
            }
        }

        if(dp[ans]!=INF){
			printf("The minimum amount of money in the piggy-bank is %d.\n",dp[ans]);
		}else{
			cout<<"This is impossible."<<endl;
		}


    }

}
```



## 多重背包

> 每种物品有一个固定的次数上限

```
f[i][v]=max{f[i-1][v-k*c[i]]+k*w[i]|0<=k<=n[i]}

procedure MultiplePack(cost,weight,amount)
    if cost*amount>=V
        CompletePack(cost,weight)
        return
    integer k=1
    while k<amount
        ZeroOnePack(k*cost,k*weight)
        amount=amount-k
        k=k*2
    ZeroOnePack(amount*cost,amount*weight)
```



```cpp
#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int x;
    cin>>x;
    while(x--){
        int n,m;//金额和种类
        cin>>n>>m;
        int p[205];//每袋的价格
        int h[205];//每袋的重量
        int c[205];//对应种类的大米的袋数
        for(int i=0;i<m;i++){
            cin>>p[i]>>h[i]>>c[i];
        }
        int dp[100001];
        memset(dp,0,sizeof(dp));
        //多重背包
        for(int i=0;i<m;i++){
            if(p[i]*c[i]>=n){
                //完全背包
                for(int j=p[i];j<=n;j++){
                    dp[j]=max(dp[j],dp[j-p[i]]+h[i]);
                }
            }else{

            int k=1;
            while(k<c[i]){
                //01背包
                for(int j=n;j>=p[i]*k;j--){
                    dp[j]=max(dp[j],dp[j-p[i]*k]+h[i]*k);
                }
                c[i]-=k;
                k*=2;
            }
            //01背包
            for(int j=n;j>=p[i]*c[i];j--){
                dp[j]=max(dp[j],dp[j-p[i]*c[i]]+c[i]*h[i]);
            }
           }
        }
        cout<<dp[n]<<endl;

    }
}

/*不用二进制优化的代码。相当于01背包
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
using namespace std;
int height[505];
int value[505];
int dp[2000];
int mount[505]; 
 
int main()
{
	int T;
	scanf("%d",&T);
	int n,m;
	while(T--)
	{
		memset(dp,0,sizeof(dp));
		scanf("%d %d",&n,&m);
		for(int i=0;i<m;i++)
		{
			scanf("%d %d %d",&height[i],&value[i],&mount[i]);
		}
		for(int i=0;i<n;i++)
		{
			for(int k=1;k<=mount[i];k++)
			{
				for(int j=n;j>=height[i];j--)
				{
					dp[j] = max(dp[j],dp[j-height[i]] + value[i]);
				}
			}
		}
		printf("%d\n",dp[n]);
	}
	return 0;
}*/

```







## 二维费用背包

> 扩展

二维费用的背包问题是指：对于每件物品，具有两种不同的费用；选择这件物品必须同时付出这两种代价；对于每种代价都有 一个可付出的最大值（背包容量）。问怎样选择物品可以得到最大的价值。设这两种代价分别为代价1和代价2，第i件物品所需的两种代价分别为a[i]和 b[i]。两种代价可付出的最大值（两种背包容量）分别为V和U。物品的价值为w[i]。

```
f[i][v][u]=max{f[i-1][v][u],f[i-1][v-a[i]][u-b[i]]+w[i]}
```







## 分组背包

有N件物品和一个容量为V的背包。第i件物品的费用是c[i]，价值是w[i]。这些物品被划分为若干组，每组中的物品互相冲突，最多选一件。求解将哪些物品装入背包可使这些物品的费用总和不超过背包容量，且价值总和最大。

```
f[k][v]=max{f[k-1][v],f[k-1][v-c[i]]+w[i]|物品i属于组k}

for 所有的组k
    for v=V..0
        for 所有的i属于组k
            f[v]=max{f[v],f[v-c[i]]+w[i]}
```





# bfs

## 优先队列

```c
priority_queue<int, vector<int>, less<int>> pq;  // 最大堆
等同于priority_queue<int>
priority_queue<int, vector<int>, greater<int>> pq;  // 最小堆

//排序方式
//方法一重载()
struct cmp{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
// priority_queue自定义函数的比较与sort正好是相反的
// 也就是说，如果你是把大于号作为第一关键字的比较方式，那么堆顶的元素就是第一关键字最小的
    priority_queue<ListNode*, vector<ListNode*>, cmp> pq; 
// 此时pq就按照节点的值将最小的放在堆顶


//方法二重载<
    struct Status{
        int val;
        ListNode* node;
        bool operator < (const Status &tmp) const{ 
        // 函数必须是静态的 使得该函数可以被 const 对象也就是常量所调用
        // 形参可以加上const关键字和&，保证安全性，提高效率
            return val > tmp.val;
        }
    };
    priority_queue<Status> pq;  
//重载()和重载<是两种不同的思路，前者是修改优先队列设置优先级的方式，后者是改变优
//先队列存放的数据类型，可以根据需要选择合适的自定义排序方法。

方法3 利用友元函数重载<    struct Status{
        int val;
        ListNode* node; 
        friend bool operator<(Status a, Status b) 
        {
            return a.val > b.val;
        }
    };
    priority_queue<Status> pq；
```



```shell
	1001	A strange lift	普通dfs
	1002	非常可乐	普通dfs
	1003	Knight Moves	走日字的dfs
	1004	Rescue	优先队列的dfs
	1005	胜利大逃亡	64.71%(11/17)

```



# dfs

```shell
	1000	Tempter of the Bone	回溯，剪枝
	1001	Safecracker	做标记，回溯
	1002	Prime Ring Problem	dfs加点判断条件
	1003	Robot Motion	dfs，另外弄个数组做标记，有无访问过
	1004	猜数字	75.00%(18/24)
	1005	Oil Deposits	遍历，遇见@递归搜索
	1006	FatMouse and Cheese	记忆化搜索，dp
	1007	How many ways	记忆化搜索dp
```





## 素数打表

>  埃氏筛 和 欧拉塞塞素数

```cpp
int flag[55],isp[55];///isp[i]是记录i是否为素数的数组
void is_prime()///素数打表
{
    int k=0;
    memset(isp,0,sizeof(isp));
    memset(flag,0,sizeof(0));
    for(int i=2; i<=7; i++)
        if(!flag[i])
            for(int j=i*i; j<=50; j+=i)
                flag[j]=1;//标记为合数
    for(int i=2; i<=50; i++)
        if(!flag[i])
            isp[i]=1;
}
```



# 并查集

## 合并（路径压缩

```cpp
int find(int x)
{
    if(x == fa[x])
        return x;
    else{
        fa[x] = find(fa[x]);  //父节点设为根节点
        return fa[x];         //返回父节点
    }
}
//简写
int find(int x)
{
    return x == fa[x] ? x : (fa[x] = find(fa[x]));
}
```

## 按秩合并

```cpp
inline void init(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        fa[i] = i;
        rank[i] = 1;
    }
}

inline void merge(int i, int j)
{
    int x = find(i), y = find(j);    //先找到两个根节点
    if (rank[x] <= rank[y])
        fa[x] = y;
    else
        fa[y] = x;
    if (rank[x] == rank[y] && x != y)
        rank[y]++;                   //如果深度相同且根节点不同，则新的根节点的深度+1
}
```

```shell
	1001	How Many Tables	简单并查集
	1002	Is It A Tree?	入度，根节点个数，群的个数判断是否一颗树
	1003	More is better	并查集维护的一个集合里，求元素个数最大的群
	1004	Constructing Roads	先排序，结构体
	1005	More is better
	1006	畅通工程	求群的个数减一
	1007	还是畅通工程	kruskal求最小生成树
	1008	畅通工程再续	kruskal求最小生成树
	1009	继续畅通工程	kruskal
```

1009:已经链接的村庄就直接合并，其他的放到一个结构体数组里，存储起始点和终点和距离就行，然后直接kruskal即可。

## kruskal求最小生成树

> 按边的长度从小到大排序，如果不连通就连上合并

```cpp
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<math.h>
#include<set>
using namespace std;
#define INF 1e9
typedef long long ll;
int fa[105],n,cunt;
struct island
{
    int x,y;
}s[105];
struct Edge
{
    int s,e;///s记录起点，e记录终点
    double dis;///dis记录起点到终点的距离
}e[5555];
int cmp(Edge a,Edge b)
{
    return a.dis < b.dis;///按距离从小大大排列
}
int father(int x)///找父亲节点，用于判断是否在一个集合中
{
    if(x == fa[x]) return x;
    else
    {
        int root = father(fa[x]);
        fa[x] = root;
        return root;
    }
}
double Kruskal()
{
    for(int i = 1; i <= n; i++)
        fa[i] = i;
    sort(e,e+cunt,cmp);///按从小到大对边进行排序
    double ans = 0;
    int m = 0;
    for(int i = 0; i < cunt; i++)///遍历所有边
    {
        int a = father(e[i].s);
        int b = father(e[i].e);
        if(a != b && (e[i].dis >= 10.0 && e[i].dis <= 1000))
        {
            ans += e[i].dis;
            fa[a] = b;///合并集合
            m++;
        }
    }
    //cout << m << endl;
    if(m != n-1) return -1;
    else return ans;
}
double distance(int x0,int y0,int x1,int y1)
{
    return sqrt((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1));
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        scanf("%d",&n);
        for(int i = 1; i <= n; i++)
            cin >> s[i].x >> s[i].y;
        cunt = 0;
        for(int i = 1; i < n; i++)
        {
            for(int j = i+1; j <= n; j++)
            {
                e[cunt].dis = distance(s[i].x,s[i].y,s[j].x,s[j].y);
                e[cunt].s = i;
                e[cunt].e = j;
                cunt++;
            }
        }
        double sum = Kruskal();
        if(sum == -1) printf("oh!\n");
        else
        {
            sum = sum*100;
            printf("%.1lf\n",sum);
        }
    }
 
    return 0;
}
```



# 博弈

> 能走到必败点就是必胜点，只能走到必胜点就代表下一个选手到的点是必胜点，所以当前点是必败点

```
1001	Brave Game	简单博弈，取余即可，倍数点一定是必败点
1002	Good Luck in CET-4 Everybody!	找规律，3的倍数一定是必败点
1003	Fibonacci again and again	肥波那次数列，求sg值，打表
1004	Rabbit and Grass	nim游戏
1005	Being a Good Boy in Spring Festival	求异或值，比大小即可
1006	Public Sale	取余求必败点和必胜点
1007	悼念512汶川大地震遇难同胞——选拔志愿者	取余即可
1008	kiki's game	只要有偶数就是先手赢，偶数行和偶数列全为必胜点
1009	S-Nim	异或，求sg值，打表
```

```cpp
//挨个循环遍历，打表
 int f[N],sg[N],hash[N];     
 void getSG(int n)
 {
     int i,j;
     memset(sg,0,sizeof(sg));
     for(i=1;i<=n;i++)
     {
         memset(hash,0,sizeof(hash));
         for(j=1;f[j]<=i;j++)
             hash[sg[i-f[j]]]=1;
         for(j=0;j<=n;j++)    //求mes{}中未出现的最小的非负整数
         {
             if(hash[j]==0)
             {
                 sg[i]=j;
                 break;
             }
         }
     }
 }

//记忆化dfs
//注意 S数组要按从小到大排序 SG函数要初始化为-1 对于每个集合只需初始化1遍
//n是集合s的大小 S[i]是定义的特殊取法规则的数组
 int s[110],sg[10010],n;
 int SG_dfs(int x)
 {
     int i;
     if(sg[x]!=-1)
         return sg[x];
     bool vis[110];
     memset(vis,0,sizeof(vis));
     for(i=0;i<n;i++)
     {
         if(x>=s[i])
         {
             SG_dfs(x-s[i]);
             vis[sg[x-s[i]]]=1;
         }
     }
     int e;
     for(i=0;;i++)
         if(!vis[i])
         {
             e=i;
             break;
         }
     return sg[x]=e;
 }
```





## nim游戏

一共有n堆，可以从一堆中取走任意数量

> 对所有组的数量进行异或，0是必败点，非0是必胜点

```cpp
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
    int m;
    while(cin>>m && m){
        int ans=0;
        for(int i=0;i<m;i++){
            int n;
            cin>>n;
            ans^=n;
        }
        if(ans) cout<<"Rabbit Win!"<<endl;
        else cout<<"Grass Win!"<<endl;

    }
    return 0;
}
```

# 二分匹配



匈牙利算法

## 模板

```cpp
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

//匈牙利算法
int n,m;//左侧元素、右侧元素的数量
int map[550][550];//邻接矩阵
int vis[550];//记录右侧元素是否已经被访问过
int p[550];//记录当前右侧元素所对应的左侧元素
bool dfs(int i){
    for(int j=1;j<=n;j++){
        if(map[i][j] && !vis[j]){
            vis[j]=1;
            if(p[j]==-1 || dfs(p[j])){
                p[j]=i;
                return true;
            }
        }
    }
    return false;

}

int hungary(){
    int res=0;
    memset(p,-1,sizeof(p));
    for(int i=1;i<=m;i++){
        memset(vis,0,sizeof(vis));
        if(dfs(i)) res++;
    }
    return res;


}
int main(){
    int k,a,b;
    while(cin>>k && k){
        cin>>m>>n;
        memset(map,0,sizeof(map));
        while(k--){
            cin>>a>>b;
            map[a][b]=1;
        }
        cout<<hungary()<<endl;
    }
    return 0;

}
```

**1003：**最小路径覆盖数就是用最少的点覆盖所有的路径

二分图**最小路径覆盖数=二分图的结点数n-二分图的最大匹配数res**

一开始图中每个节点代表一条长为0的路径，共有n条，每次在二分图中找到一条匹配的边即将两条路径合并成了一条路径，造成路径数减1，所以有几条匹配的边，路径数就少几条。

1004：求最大独立集，最大独立集 = 顶点数 - 最大匹配数（最小顶点覆盖数），因为本题没有给出具体的性别，所以会造成重复现象，求出最大匹配数除以二才是实际的最大匹配数。`scanf("%d: (%d)",&a,&num);`



```
1001	过山车	模板题，套用匈牙利算法模板
1002	Machine Schedule	转化为二部图，求配对，模板题
1003	Air Raid	dag图，有向无环图，最小路径覆盖
1004	Girls and Boys	求最大独立集，巧妙的输入数据，利用scanf
1005	棋盘游戏 转化为匈牙利算法，二分匹配问题，重要点就是不能去掉的边，即影响结果的在二分图中的边
```









![博弈2](博弈2.jpg)

![博弈3](博弈3.jpg)

![博弈1](博弈1.jpg)





# 母函数

> 多项式相乘



特点：排列组合，多项式相乘。一般都会是货币面值，与货币的个数，求他们的组合。还有的给资源数和资源的价值，求出能组成资源数的种类和不能的种类。

![母函数](母函数.jpg)

## 模板一

```cpp
#include <iostream>
using namespace std;
const int lmax=300;
int c1[lmax+1],c2[lmax+1];
int main()
{	int n,i,j,k;
	while (cin>>n && n!=0)
	{	for (i=0;i<=n;i++){	
            c1[i]=0;	
            c2[i]=0;		
        }
        for(i=0;i<=n;i++){
            c1[i]=1;
        }
		for (i=2;i<=n;i++)
		{	for (j=0;j<=n;j++)
				for (k=0;k+j<=n;k+=i)
				{	c2[j+k]+=c1[j];	}
			for (j=0;j<=n;j++)
			{	c1[j]=c2[j];	c2[j]=0;	}
		}
		cout<<c1[n]<<endl;
	}
	return 0;
}
```





## 模板二

```cpp
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
            cin>>value[i]>>num[i];//面值和数量
        }
        for (i=0;i<=lmax;i++){	//初始化
            c1[i]=0;	
            c2[i]=0;		
        }
        for(i=0;i<=num[0]*value[0];i+=value[0]){
            c1[i]=1;
        }
        int sum=value[0]*num[0];
		for (i=1;i<n;i++)//n-1趟多项式相乘
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

```



```
	1001	Ignatius and the Princess III	
	1002	Holding Bin-Laden Captive!	
	1003	Big Event in HDU	
	1004	选课时间	
	1005	Square Coins	
	1006	Crisis of HDU
	1007	找单词	
	1008	The Balance
```

