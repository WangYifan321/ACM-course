#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
    long long n;
    while(cin>>n && n){
        int cnt[4] = { 0 };   // 分别表示分解质因数后 2,3,5,7 的幂次

		while (true)
		{
			if (n % 2 == 0)
			{
				cnt[0]++;
				n /= 2;
				continue;
			}
			else if (n % 3 == 0)
			{
				cnt[1]++;
				n /= 3;
				continue;
			}
			else if (n % 5 == 0)
			{
				cnt[2]++;
				n /= 5;
				continue;
			}
			else if (n % 7 == 0)
			{
				cnt[3]++;
				n /= 7;
				continue;
			}

			break;
		}

		printf("%lld\n", (cnt[0] + 1) * (cnt[1] + 1) * (cnt[2] + 1) * (cnt[3] + 1));
    }
    

    return 0;
}


/*

正整数 378000 共有多少个正约数？

解：将 378000 分解成质因数，378000=2^4 * 3^5 * 5^3 * 7^1
    有约数定理可知共有正约束(4+1)*(3+1)*(3+1)*(1+1)=160个

*/