/* 53
Given an integer array nums, find the contiguous subarray 
(containing at least one number) which has the largest sum 
and return its sum.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur += nums[i];
            if (cur < 0) {
                sum = max(sum, cur);    //必须的，需要处理全是负数的情况
                cur = 0;
            } else {
                sum = max(sum, cur);
            }
        }
        return sum;
    }
};


/* 152. Maximum Product Subarray
Given an integer array nums, find a contiguous non-empty subarray
 within the array that has the largest product, and return the product.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int max_v = 1, min_v = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) swap(max_v, min_v);
            max_v = max(max_v * nums[i], nums[i]);
            min_v = min(min_v * nums[i], nums[i]);
            ans = max(max_v, ans);
        }
        return ans;
    }
};
