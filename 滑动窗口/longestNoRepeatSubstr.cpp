#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 滑动窗口
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int res = 0;
        for (int i = 0, j = 0; j < s.size(); j ++ ) {
            hash[s[j]] ++ ; // 建立窗口
            while (hash[s[j]] > 1) hash[s[i ++ ]] -- ;  // 窗口不满足，重新恢复新的窗口
            res = max(res, j - i + 1);
        }
        return res;
    }
};


/*
159. Longest Substring with At Most Two Distinct Characters
Given a string s, return the length of the longest substring 
that contains at most two distinct characters.

Input: s = "eceba"
Output: 3
Explanation: The substring is "ece" which its length is 3.
*/

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.size() <= 2)  return s.size();
        int res = 2, cnt = 0;
        unordered_map<char, int> hash;
        for (int i = 0, j = 0; i < s.size(); i++) {
            hash[s[i]]++;
            while (hash.size() == 3) {
                hash[s[j]]--;
                if (hash[s[j]] == 0) {
                    hash.erase(s[j]), j++;
                    break;
                }
                j++;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};

