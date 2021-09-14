// 背包问题求方案数
// https://www.acwing.com/solution/content/2954/
/*
一个正整数 n 可以表示成若干个正整数之和，形如：n=n1+n2+…+nk，其中 n1≥n2≥…≥nk,k≥1。
我们将这样的一种表示称为正整数 n 的一种划分。
现在给定一个正整数 n，请你求出 n 共有多少种不同的划分方法。
*/

#include <iostream>
using namespace std;
const int N = 1e3 + 7, mod = 1e9 + 7;
int f[N][N];    // f[i][j]表示只用前i个物品装满容量为j的背包需要的方案数

int main() {
    int n;
    cin >> n;

    for (int i = 0; i <= n; i ++) 
        f[i][0] = 1; // 容量为0时，前 i 个物品全不选也是一种方案
    

    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j <= n; j ++) {
            f[i][j] = f[i - 1][j] % mod; // 特殊 f[0][0] = 1
            if (j >= i) f[i][j] = (f[i - 1][j] + f[i][j - i]) % mod;
        }
    }

    cout << f[n][n] << endl;
}