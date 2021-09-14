/* 220. Contains Duplicate III
Given an integer array nums and two integers k and t, 
return true if there are two distinct indices i and j 
in the array such that abs(nums[i] - nums[j]) <= t and 
abs(i - j) <= k.
*/

#include <bits/stdc++.h>
using namespace std;

// multiset滑动窗口+二分

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        typedef long long LL;
        multiset<LL> S;
        S.insert(1e18), S.insert(-1e18);
        for (int i = 0, j = 0; i < nums.size(); i ++ ) {
            if (i - j > k) S.erase(S.find(nums[j ++ ]));    // 如果不写find的话会一直删掉所有nums[j]
            int x = nums[i];
            auto it = S.lower_bound(x); //返回 >= x的第一个数字
            if (*it - x <= t) return true;
            -- it;
            if (x - *it <= t) return true;
            S.insert(x);
        }
        return false;
    }
};