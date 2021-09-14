/* 241. Different Ways to Add Parentheses
Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.

Input: expression = "2-1-1"
Output: [0,2]
Explanation:
((2-1)-1) = 0 
(2-(1-1)) = 2

Input: expression = "2*3-4*5"
Output: [-34,-14,-10,-10,10]
Explanation:
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> expr;
// 有点像多少种二叉树那道题，因为每个表达式都可以对应一个表达式树
    vector<int> diffWaysToCompute(string s) {
        // 先处理表达式
        for (int i = 0; i < s.size(); i ++ ) {
            if (isdigit(s[i])) {
                int j = i, x = 0;
                while (j < s.size() && isdigit(s[j])) x = x * 10 + (s[j ++ ] - '0');
                i = j - 1;
                expr.push_back(to_string(x));
            } else expr.push_back(s.substr(i, 1));
        }
        return dfs(0, expr.size() - 1);
    }

    vector<int> dfs(int l, int r) {
        if (l == r) return {stoi(expr[l])};
        vector<int> res;
        for (int i = l + 1; i < r; i += 2) {
            auto left = dfs(l, i - 1), right = dfs(i + 1, r);
            for (auto x: left)
                for (auto y: right) {
                    int z;
                    if (expr[i] == "+") z = x + y;
                    else if (expr[i] == "-") z = x - y;
                    else z = x * y;
                    res.push_back(z);
                }
        }
        return res;
    }
};
