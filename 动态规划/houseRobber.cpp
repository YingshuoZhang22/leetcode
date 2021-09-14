#include <bits/stdc++.h>
using namespace std;

/* 198. House Robber
不能连着偷相邻的2间房子

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int size = nums.size();
        if (size == 1) return nums[0];
        
        vector<int> dp = vector<int>(size, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        // 要么偷要么不偷
        for (int i = 2; i < size; i++) 
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        return dp[size - 1];
    }
};
