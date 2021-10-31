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
	1010	小兔的棋盘
	1011	Game of Connections
```



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





































