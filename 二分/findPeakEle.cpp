/* 162. Find Peak Element
A peak element is an element that is strictly greater than its neighbors.

Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞.

You must write an algorithm that runs in O(log n) time.

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
// 一定有解
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            // 因为数组的元素都不同，找第一个mid， 满足nums[mid] > nums[mid + 1]，
            // 这个mid就是答案，因为mid左边的数组都是单调递增的
            if (nums[mid] > nums[mid + 1]) r = mid; 
            // 一定不会越界，因为我们是下取整，如果mid = nums.size() - 1,一定是l = r
            else l = mid + 1;
        }
        return r;
    }
};
