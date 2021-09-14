/* 78
Given an integer array nums of unique elements, 
return all possible subsets (the power set).

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path, num;
    int len;
    void dfs(int cur, int end) {
        if (path.size() == end) {
            res.push_back(path);
            return;
        }
        for (int i = cur; i < len; i++) {
            path.push_back(num[i]);
            dfs(i + 1, end);   
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        len = nums.size();
        num = nums;
        for (int i = 0; i <= len; i++) {
            dfs(0, i);   // 枚举不同size的subset
        }
        return res;
    }
};

/* 90
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
*/

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(0, nums);
        return ans;
    }

    /*
为了方便处理，我们先将数组排序，这样相同元素就会排在一起。
然后暴力搜索所有方案，搜索顺序是这样的：
我们先枚举每个不同的数，枚举到数 x 时，我们再求出 x 的个数 k，然后我们枚举在集合中放入 0,1,2,…k个 x，共 k+1 种情况。
当枚举完最后一个数时，表示我们已经选定了一个集合，将该集合加入答案中即可。
    */

    void dfs(int u, vector<int>&nums) {
        if (u == nums.size()) {
            ans.push_back(path);
            return;
        }
        int k = u;
        while (k < nums.size() && nums[k] == nums[u]) k ++ ;
        dfs(k, nums);
        for (int i = u; i < k; i ++ ) {
            path.push_back(nums[i]);
            dfs(k, nums);
        }
        path.erase(path.end() - (k - u), path.end());
    }
};
