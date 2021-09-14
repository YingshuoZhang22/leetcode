
/* 26
Given an integer array nums sorted in non-decreasing order, remove the 
duplicates in-place such that each unique element appears only once. 
The relative order of the elements should be kept the same.

Return k after placing the final result in the first k slots of nums.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // if (nums.size() <= 1)   return nums.size();
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] != nums[i - 1])
                nums[j++] = nums[i];
        }
        return j;
    }
};


/* 80
使每个数字最多出现2次：
Input: nums = [0,0,1,1,1,1,2,3,3]
Output: 7, nums = [0,0,1,1,2,3,3,_,_]
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for (auto num : nums) {
            if (k < 2 || nums[k - 1] != num || nums[k - 2] != num) 
                nums[k ++] = num;
        }
        return k;
    }
};
