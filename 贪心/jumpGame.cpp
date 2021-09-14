/* 45
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

Example 1:
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int jump(vector<int> &nums) {
        int ans = 0;
        int start = 0;
        int end = 1;
        while (end < nums.size()) {
            int maxPos = 0;
            for (int i = start; i < end; i++) {
                // 能跳到最远的距离
                maxPos = max(maxPos, i + nums[i]);
            }
            start = end;      // 下一次起跳点范围开始的格子
            end = maxPos + 1; // 下一次起跳点范围结束的格子
            ans++;            // 跳跃次数
        }
        return ans;
    }
};

// 判断是否能跳到，55
class Solution {
public:
    bool canJump(vector<int>& nums) {
        for (int i = 0, j = 0; i < nums.size(); i ++ ) {
            if (j < i) return false;
            j = max(j, i + nums[i]);    // j是在位置i下能跳到的最远的坐标
        }
        return true;
    }
};