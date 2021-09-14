/*
有 N 件物品和一个容量是 V 的背包。每件物品只能使用一次。
第 i 件物品的体积是 vi，价值是 wi。
求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
输出最大价值。

输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品数量和背包容积。
接下来有 N 行，每行两个整数 vi,wi，用空格隔开，分别表示第 i 件物品的体积和价值。

输出格式
输出一个整数，表示最大价值。

数据范围
0<N,V≤1000
0<vi,wi≤1000
*/

// https://mp.weixin.qq.com/s/xmgK7SrTnFIM3Owpk-emmg    宫水三叶背包问题
// 01背包空间复杂度可以通过倒序遍历的方法优化成一维度数组

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1010;
int v[N], w[N]; // value & weight
int dp[N][N];   // dp[i][j], 只考虑前i个物品，总体积不超过j的最大价值 


int main() {
    int n, m;
    cin >> n >> m;  // n是物品数量，m是weight限制
    for (int i = 1; i <= n; i ++)    cin >> w[i] >> v[i];
    for (int i = 1; i <= n; i ++) { // value
        for (int j = 1; j <= m; j ++) { // weight
            if (j < w[i])   dp[i][j] = dp[i - 1][j];    // 不选
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
        }
    }
    cout << dp[n][m];
    return 0;
}

/* 416. Partition Equal Subset Sum
Given a non-empty array nums containing only positive integers, 
find if the array can be partitioned into two subsets such that 
the sum of elements in both subsets is equal.

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
*/

// 我们背包容量为 target = sum / 2 ，每个数组元素的「价值」与「成本」
// 都是其数值大小，求我们能否装满背包。

// dp[i][j] 代表考虑前 i 个数值，其选择数字总和不超过 j 的最大价值。

class Solution {
public:
// 01背包问题
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for (auto n: nums)  sum += n;
        if (sum % 2 != 0)   return false;
        int target = sum / 2;

// dp[i][j] 代表考虑前 i 个数值，其选择数字总和**不超过** j 的最大价值。
        vector<vector<int> > dp(n + 5, vector<int>(target + 5, 0)); 
        nums.insert(nums.begin(), 0);
        for (int i = 1; i <= n ; i++) {
            for (int j = 1; j <= target; j++) {
                if (nums[i] > j)    dp[i][j] = dp[i-1][j];
                else dp[i][j] = max(dp[i-1][j], dp[i-1][j-nums[i]] + nums[i]);
                
            }
        }
        return dp[n][target] == target;
    }
};

class Solution {
public:
// 01背包问题
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for (auto n: nums)  sum += n;
        if (sum % 2 != 0)   return false;
        int target = sum / 2;

// dp[i][j] 代表考虑前 i 个数值，其选择数字总和是否恰好为 j。
// dp[0][0] vacuously true
        vector<vector<int> > dp(n + 5, vector<int>(target + 5, 0));
        dp[0][0] = true; 
        nums.insert(nums.begin(), 0);
        for (int i = 1; i <= n ; i++) {
            for (int j = 1; j <= target; j++) {
                dp[i][j] |= dp[i-1][j];
                if (nums[i] <= j)    
                    dp[i][j] |= dp[i-1][j-nums[i]];
            }
        }
        return dp[n][target];
    }
};