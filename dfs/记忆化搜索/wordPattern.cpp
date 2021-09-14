/* 291. 单词规律 II
给你一种规律 pattern 和一个字符串 str，请你判断 str 是否遵循其相同的规律。

这里我们指的是 完全遵循，例如 pattern 里的每个字母和字符串 str 中每个 非空 单词之间，存在着 双射 的对应规律。双射 意味着映射双方一一对应，不会存在两个字符映射到同一个字符串，也不会存在一个字符分别映射到两个不同的字符串。

示例 1：

输入：pattern = "abab", s = "redblueredblue"
输出：true
解释：一种可能的映射如下：
'a' -> "red"
'b' -> "blue"
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<char, string> hash1;
    unordered_map<string, char> hash2;
    bool flag = false;
    bool wordPatternMatch(string pattern, string s) {
        if (pattern.size() == 1)    return true;
        dfs(pattern, 0, s, 0);
        return flag;
    }

    void dfs(string pattern, int idx1, string s, int idx2) {
        if (flag)   return;
        if (idx2 >= s.size() && idx1 < pattern.size())  return; 
        if (idx1 == pattern.size() && idx2 == s.size()) {
            flag = true;
            return;
        }
        if (hash1.count(pattern[idx1])) {
            cout << pattern[idx1];
            string str = hash1[pattern[idx1]];
            char ch = hash2[str];
            if (s.substr(idx2, str.size()) != str || pattern[idx1] != ch)  return;
            dfs(pattern, idx1 + 1, s, idx2 + str.size());
        } else {
            for (int i = idx2; i < s.size(); i++) {
                string str = s.substr(idx2, i - idx2 + 1);
                if (hash1.count(pattern[idx1]) && !hash2.count(str))    continue;   // very
                if (!hash1.count(pattern[idx1]) && hash2.count(str))    continue;   // important
                hash1[pattern[idx1]] = str, hash2[str] = pattern[idx1];
                dfs(pattern, idx1 + 1, s, i + 1);
                hash1.erase(pattern[idx1]), hash2.erase(str);
            }
        }
    }
};