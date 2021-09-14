/*238. Product of Array Except Self
Given an integer array nums, return an array answer such that
 answer[i] is equal to the product of all the elements of nums except nums[i].

requirement: O(n) time, O(1) extra space (excluding output array), no division
*/

// 思路：分别保存前缀积和后缀积，前缀积用output数组，后缀积用int
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(n, 1);
        for (int i = 1; i < n; i ++ ) p[i] = p[i - 1] * nums[i - 1];
        for (int i = n - 1, s = 1; i >= 0; i -- ) { // 只算前缀积，后缀积用一个数字动态的去存
            p[i] *= s;
            s *= nums[i];
        }
        return p;
    }
};
