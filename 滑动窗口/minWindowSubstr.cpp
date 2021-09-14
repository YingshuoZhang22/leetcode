/* 76
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        int cnt = 0;
        for (auto c : t) {
            if (!need[c]) cnt ++ ;
            need[c] ++ ;
        }

        string res = "";
        // i是当前字符，j是窗口起点，c是有效字符数目
        for (int i = 0, j = 0, c = 0; i < s.size(); i ++ ){
            need[s[i]] -- ;
            if (need[s[i]] == 0) c ++ ; // need[s[i]]存的不是当前字符数目，而是需要的字符数目
            
            //检查 s[j] 是否多余，如果是，则移除 s[j]；（缩小窗口）
            while (c == cnt && need[s[j]] < 0)
                 need[s[j]]++, j++ ;
                 
            // 检查当前窗口是否已经满足 TT 中所有字符，如果是，则更新答案；
            if (c == cnt) {
                if (res.empty() || res.size() > i - j + 1) res = s.substr(j, i - j + 1);
            }
        }
        return res;
    }
};