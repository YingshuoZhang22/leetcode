/* 22
Given n pairs of parentheses, generate all combinations of well-formed parentheses.

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> res;
    string s;
    int N;

    void dfs(int left, int right) {
        if (left == N && right == N) {
            res.push_back(s);
            return;
        }
        if (left < N) { // 可以加左括号
            s += "(";
            dfs(left + 1, right);
            s.pop_back();
        }
        if (right < N && left > right) {    // 可以加右括号
            s += ")";
            dfs(left, right + 1);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        N = n;
        dfs(0,0);
        return res;
    }
};

/* 301. Remove Invalid Parentheses
Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

Return all the possible results. You may return the answer in any order.

Input: s = "()())()"
Output: ["(())()","()()()"]

Input: s = "(a)())()"
Output: ["(a())()","(a)()()"] 
*/

class Solution {
public:
// 一个合法的括号序列当且仅当：左括号数目=右括号数目；对任意一个prefix，左括号数量 > 右括号数量
// 
    vector<string> ans;

    vector<string> removeInvalidParentheses(string s) {
        int l = 0, r = 0;
        for (auto x: s)
            if (x == '(') l ++ ;
            else if (x == ')') {
                if (l == 0) r ++ ;
                else l -- ;
            }

        dfs(s, 0, "", 0, l, r);
        return ans;
    }

    void dfs(string& s, int u, string path, int cnt, int l, int r) {
        if (u == s.size()) {
            if (!cnt) ans.push_back(path);
            return;
        }

        if (s[u] != '(' && s[u] != ')') dfs(s, u + 1, path + s[u], cnt, l, r);
        else if (s[u] == '(') {
            int k = u;
            while (k < s.size() && s[k] == '(') k ++ ;
            l -= k - u;
            for (int i = k - u; i >= 0; i -- ) {
                if (l >= 0) dfs(s, k, path, cnt, l, r);
                path += '(';
                cnt ++, l ++ ;
            }
        } else if (s[u] == ')') {
            int k = u;
            while (k < s.size() && s[k] == ')') k ++ ;
            r -= k - u;
            for (int i = k - u; i >= 0; i -- ) {
                if (cnt >= 0 && r >= 0) dfs(s, k, path, cnt, l, r);
                path += ')';
                cnt --, r ++ ;
            }
        }
    }
};
