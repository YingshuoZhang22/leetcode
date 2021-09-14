/* 39

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Input: candidates = [2], target = 1
Output: []

Input: candidates = [1], target = 1
Output: [[1]]

Input: candidates = [1], target = 2
Output: [[1,1]]
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, 0, target);
        return res;
    }

    void dfs(vector<int>& candidates, int u, int target) {
        if (target == 0) {
            res.push_back(path);
            return;
        } 

        if (u == candidates.size())  
            return; // 数组中所有元素都用完了还不够target

        for (int i = 0; candidates[u] * i <= target; i++) { // 枚举数组中每个元素最大出现次数
            dfs(candidates, u + 1, target - candidates[u] * i); // 每开始一次dfs，数组中都放入了不同数目的i
            path.push_back(candidates[u]);
        }

        for (int i = 0; candidates[u] * i <= target; i++) {
            path.pop_back();    // 清理现场，把前面放进去的一次性删除完
        }
    }
};

/* 40
Each number in candidates may only be used once in the combination.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[[1,1,6],[1,2,5],[1,7],[2,6]]

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[[1,2,2],[5]]
*/ 

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    unordered_map<int, int> hash;

    // 和上一题相同，只是每个数字最多使用[数字在数组中出现的次数]次
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        for (int i = 0; i < candidates.size(); i++) {
            hash[candidates[i]] ++;
        }
        dfs(candidates, 0, target);
        return res;
    }

    void dfs(vector<int>& candidates, int u, int target) {
        if (target == 0) {
            res.push_back(path);
            return;
        } 

        if (u == candidates.size())  
            return; // 数组中所有元素都用完了还不够target
        
        int times = hash[candidates[u]];    //  加一个限制条件
        //cout << candidates[u] << " " << times << endl;
        for (int i = 0; candidates[u] * i <= target && i <= times; i++) { // 枚举数组中每个元素最大出现次数
        // 上一道题数组中数字不重复，这道题就必须先排序，再把所有重复数字跳过去
            dfs(candidates, u + times, target - candidates[u] * i); // 每开始一次dfs，数组中都放入了不同数目的i
            path.push_back(candidates[u]);
        }

        for (int i = 0; candidates[u] * i <= target && i <= times; i++) 
            path.pop_back();    // 清理现场，把前面放进去的一次性删除完
    }
};

/*
216. Combination Sum III
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.


Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
*/

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    int n, k;
    vector<vector<int>> combinationSum3(int _k, int _n) {
        n = _n, k = _k;
        dfs(1, 0);
        return res;
    }

    void dfs(int x, int sum) {
        if (path.size() == k && sum == n) {
            res.push_back(path);
            return;
        }
        if (sum >= n)   return;
        for (int i = x; i <= 9; i++) {
            path.push_back(i);
            dfs(i + 1, sum + i);
            path.pop_back();
        }
    }
};