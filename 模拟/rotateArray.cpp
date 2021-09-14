/* 189. Rotate Array
Given an array, rotate the array to the right by k steps, where k is non-negative.
*/

#include <bits/stdc++.h>
using namespace std;

// 原地算法
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

// 公式法
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        vector<int> tmp(nums.size());
        for (int i = 0; i < nums.size(); i++)
            tmp[(i + k) % nums.size()] = nums[i];
        nums = tmp;
    }
};