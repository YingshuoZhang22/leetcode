/*
有 N 种物品和一个容量是 V 的背包，每种物品都有无限件可用。
第 i 种物品的体积是 vi，价值是 wi。
求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
输出最大价值。

输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品种数和背包容积。

接下来有 N 行，每行两个整数 vi,wi，用空格隔开，分别表示第 i 种物品的体积和价值。

输出格式
输出一个整数，表示最大价值。
*/

// 宫水三叶：https://mp.weixin.qq.com/s?__biz=MzU4NDE3MTEyMA==&mid=2247486107&idx=1&sn=e5fa523008fc5588737b7ed801caf4c3&chksm=fd9ca184caeb28926959c0987208a3932ed9c965267ed366b5b82a6fc16d42f1ff40c29db5f1&token=990510480&lang=zh_CN#rd

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1010;
int v[N], w[N]; // value & weight
int dp[N][N];   // dp[i][j], 只考虑前i个物品，总体积不超过j的最大价值 


int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)    cin >> w[i] >> v[i];
    for (int i = 1; i <= n; i ++) { // value
        for (int j = 1; j <= m; j ++) { // weight
            if (j < w[i])   dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - w[i]] + v[i]);
        }
    }
    cout << dp[n][m];
    return 0;
}

/* 279. Perfect Squares
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
*/

class Solution {
public:

// dp[i][j] 为考虑前 i 个数字，凑出数字总和 j 所需要用到的最少数字数量。
    int numSquares(int n) {
        vector<int> w(1, 0);
        for (int i = 1; i * i <= n; i++)    w.push_back(i * i);
        int len = w.size() - 1;
        vector<vector<int>> dp(len + 1, vector<int>(n + 1, 1e9));
        dp[0][0] = 0;

        for (int i = 1; i <= len; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = dp[i-1][j];  //不选第i个数字
                if (j >= w[i])  dp[i][j] = min(dp[i][j], dp[i][j - w[i]] + 1);  // 每个物品价值为1

                //for (int k = 1; k * v[i] <= j; k++)
                //    if (dp[i - 1][j - k * v[i]] != 1e9)
                //        dp[i][j] = min(dp[i][j], dp[i - 1][j - k * v[i]] + k);
            }
        }
        return dp[len][n];
    }
};