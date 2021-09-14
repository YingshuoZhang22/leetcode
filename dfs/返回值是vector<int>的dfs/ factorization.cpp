/* 254. Factor Combinations
Numbers can be regarded as the product of their factors.

For example, 8 = 2 x 2 x 2 = 2 x 4.
Given an integer n, return all possible combinations of its factors. You may return the answer in any order.

Note that the factors should be in the range [2, n - 1].

Input: n = 1
Output: []

Input: n = 12
Output: [[2,6],[3,4],[2,2,3]]

Input: n = 37
Output: []

Input: n = 32
Output: [[2,16],[4,8],[2,2,8],[2,4,4],[2,2,2,4],[2,2,2,2,2]]
 
Constraints:n1 <= n <= 107
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dfs(int n, int L) {
        vector<vector<int>> res;
        int i = L;
        while (i * i <= n) {
            if (n % i == 0) {
                res.push_back({i, n/i});        //i=2, n=100,  n/i=50
                for (vector<int> v: dfs(n/i, i)) {   //dfs(50, 2)
                    v.push_back(i);             //n/i * i = n
                    res.push_back(v);
                }
            }
            i ++;
        }
        return res;
    }

    vector<vector<int>> getFactors(int n)  {
        return dfs(n, 2);
    }
};
