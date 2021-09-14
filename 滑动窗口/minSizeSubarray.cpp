/*209. Minimum Size Subarray Sum
Given an array of positive integers nums and a positive integer target, 
return the minimal length of a contiguous subarray 
[numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 双指针滑动窗口
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = nums.size(), res = 1e9, sum = 0, j = 0;
        for (int i = 0; i < len; i++) {
            while (j < len && sum < target) sum += nums[j], j++;
            if (sum >= target)  res = min(res, j - i);
            sum -= nums[i];
        }
        return res == 1e9 ? 0 : res;
    }
};

// 另一种窗口方式
class Solution {
public:
    // 双指针滑动窗口
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = nums.size(), res = 1e9, sum = 0, j = 0;
        for (int i = 0; i < len; i++) {
            sum += nums[i];
            while (j < nums.size() && sum - nums[j] >= target)  
                sum -= nums[j++];
            if (sum >= target)  res = min(res, i - j + 1);
        }
        return res == 1e9 ? 0 : res;
    }
};