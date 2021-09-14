/* 33
Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 找分解位置，（指向第一段的最后一个）
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (nums[mid] >= nums[0]) l = mid;
            else r = mid - 1;
        }

        // 确定待搜索的单调区间
        if (target >= nums[0]) l = 0;
        else l = r + 1, r = nums.size() - 1;

        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;   // 找 >= target 的第一个数字
            else l = mid + 1;
        }

        if (nums[r] == target) return r;
        return -1;
    }
};


/* 81
with duplicates
Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // 去除尾端的重复元素
        int R = nums.size() - 1;
        while (R >= 0 && nums[R] == nums[0]) R -- ;
        if (R < 0) return nums[0] == target;

        // 找旋转点（第一段的最左边）
        int l = 0, r = R;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (nums[mid] >= nums[0]) l = mid;  // 找 >= target的最后一个
            else r = mid - 1;
        }

        // 确定搜索范围
        if (target >= nums[0]) r = l, l = 0;
        else l ++, r = R;

        // 搜索
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target) r = mid;   // 找 >= target 的第一个数字
            else l = mid + 1;
        }
        return nums[r] == target;
    }
};

/* 153. Find Minimum in Rotated Sorted Array
数组元素唯一
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        if (nums[0] <= nums[r])  return nums[0];
        while (l < r) {
            int mid = (l + r + 1) / 2;
            // 找 >= nums[0] 的最后一个数（数组中最大的数）
            if (nums[mid] >= nums[0])   l = mid;
            else r = mid - 1;
        }

        return nums[l + 1];
    }
};

/* 154. Find Minimum in Rotated Sorted Array II
数组元素不唯一
*/

class Solution {
public:
    // 除去尾部重复元素
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r && nums[r] == nums[0]) r -- ;
        if (nums[l] <= nums[r]) return nums[0];
        while (l < r) {
            int mid = l + r >> 1;
            // 找 < nums[0] 的第一个数（数组中最小的数）
            if (nums[mid] < nums[0]) r = mid;
            else l = mid + 1;
        }
        return nums[r];
    }
};