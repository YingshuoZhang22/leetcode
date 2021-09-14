/* 31
Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // [1,7,3,6,5,4,2] -> [1,7,4,2,3,5,6]
    // 找第一个非降序的位置（6)，如果不存在直接反转整个数组;
    // 找6之后第一个比 [6之前的第一个数（3）] 大的数（4），交换4和3，得到[1,7,4,6,5,3,2]
    // reverse 6后面的所有数[6,5,3,2]
    void nextPermutation(vector<int>& nums) {
        int k = nums.size() - 1;
        while (k > 0 && nums[k - 1] >= nums[k]) k -- ;
        // cout << nums[k] << endl;
        if (k <= 0) {
            reverse(nums.begin(), nums.end());
        } else {
            int t = k;
            while (t < nums.size() && nums[t] > nums[k - 1]) t ++ ;
            swap(nums[t - 1], nums[k - 1]);
            reverse(nums.begin() + k, nums.end());
        }
    }
};
