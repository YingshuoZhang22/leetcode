/* 46
Given an array nums of distinct integers, return all the possible permutations.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<bool> used;
    vector<vector<int>> permute(vector<int>& nums) {
        if (!nums.size())   return res;
        used = vector<bool>(nums.size(), false);
        vector<int> v;
        dfs(nums, v);
        return res;
    }
    void dfs(vector<int>& nums, vector<int> tmp) {
        if (tmp.size() == nums.size())
            res.push_back(tmp);
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                used[i] = true;
                tmp.push_back(nums[i]);
                dfs(nums, tmp);
                tmp.pop_back();
                used[i] = false;
            }
        }
    }
};