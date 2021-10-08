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

