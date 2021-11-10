/*完全背包，二维背包

首先应该是将经验当价值，因为你的经验可以没有上限，所以不能当背包容量，而杀怪数和忍受度都有限度，两个变量，应当用二维数组
如果怪物只能杀一遍，是01背包题，二维数组的变量应当从大到小递减，但是现在一个怪物可以杀多次，所以是完全背包
我是这么理解的，把这个二维数组看成一个一维数组，应当是从小到大递增，也就是从左到右，但现在是二维，所以要从左上角到右下角递增，所以是从左到右，从上到下，都是递增的。
并且很好理解， 首先状态转移方程如下： dp[j][k] = max(dp[j][k], dp[j - endure[i]][k - 1]) 因为在max中dp[j][k]还是i-1状态的j，k。如果j，k都是从小到大递增。
而dp[j - endure[i]][k - 1]就是i状态的j，k。也就是说重复杀怪了，否则就是每个怪只杀一次

最后要选出忍耐度最大的值，就要找耗费的忍耐度尽量小。只要找出杀s怪之内的最小值。只需一层循环。贴上代码：
*/
#include <stdio.h>
#include <string.h>
 
int experience[100];//经验值
int endure[100];//忍耐度
 
int dp[100][100];
 
int max(int a, int b)
{
    return a > b ? a : b;
}
//当作背包的变量一定是有一个最大值的，就是背包容量。通过这个特性可以判断背包题目哪个变量是背包
int main(void)
{
    int ex, en, n, s;//经验值，忍耐度，怪物的种类数，最多的杀怪数
    int i, j, k;
    int min;
 
    while (scanf("%d %d %d %d", &ex, &en, &n, &s) != EOF)
    {
        for (i = 1; i <= n; i++)
        {
            scanf("%d %d", &experience[i], &endure[i]);
        }
 
        memset(dp, 0, sizeof(dp));
 
        for (i = 1; i <= n; i++)
        {
            for (j = endure[i]; j <= en; j++)
            {
                for (k = 1; k <= s; k++)
                {
                    dp[j][k] = max(dp[j][k], dp[j - endure[i]][k - 1] + experience[i]);
                }
            }
        }
 
        if (dp[en][s] < ex)
        {
            printf("-1\n");
        }
        else
        {
            min = en;
            for (i = 0; i <= en; i++)
            {
                if (dp[i][s] >= ex)
                {
                    printf("%d\n", en - i);
                    break;
                }
            }
        }
    }
    return 0;
}