/* 47
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
Input: nums = [1,1,2]
Output:
[[1,1,2], [1,2,1], [2,1,1]]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;
    vector<bool> used;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (!nums.size())   return res;
        sort(nums.begin(), nums.end()); // 是否sort不影响全排列的结果
        used = vector<bool>(nums.size(), false);
        dfs(nums);
        return res;
    }
    void dfs(vector<int>& nums) {
        if (temp.size() == nums.size()) {
            res.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                if (i && nums[i - 1] == nums[i] && !used[i - 1])    continue;   // 多个重复的数字只用第一个
                used[i] = true;
                temp.push_back(nums[i]);
                dfs(nums);
                used[i] = false;
                temp.pop_back();
            }
        }
    }
};