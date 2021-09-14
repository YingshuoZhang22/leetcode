/* 30
You are given a string s and an array of strings words of the same length. Return all starting indices of substring(s) in s that is a concatenation of each word in words exactly once, in any order, and without any intervening characters.

Example 1:
Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","good"]

Output: [0,9]

Trace:
    word 1 1 
good 1 word 1 2 
good 2 word 1 3 
good 3 word 1 3 
best 1 good 3 word 0 3 
best 1 good 2 word 1 4 
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty()) return res;
        int n = s.size(), m = words.size(), w = words[0].size();
        unordered_map<string, int> tot; // 存words中每个word出现的次数
        for (string word : words) tot[word] ++ ;

        for (int i = 0; i < w; i ++ ) { // 枚举起始位置：0-w-2w-....; 1->w+1->2w+1->3w+1...
            unordered_map<string, int> window;
            int cnt = 0;    // cnt存的是每个window中的有效单词数（出现次数不多不少）
            for (int j = i; j + w <= n; j += w) {   // 终点是j + w - 1
                if (j >= i + m * w) {   // 滑动窗口 >= m * w， 可以开始缩小窗口
                    string word = s.substr(j - m * w, w);
                    window[word] -- ;
                    if (window[word] < tot[word]) cnt -- ;
                }
                string word = s.substr(j, w);   // 滑窗口扩容
                window[word] ++ ;
                if (window[word] <= tot[word]) cnt ++ ; // 不能是小于，因为就算是相同的单词出现2次，也会被treat成2个不同的单词
                if (cnt == m) res.push_back(j - (m - 1) * w);
/*
                if (i == 0)
                    for (auto p: window) 
                        cout << p.first << " " << p.second << " ";
                    cout << cnt << " " << endl;
*/
            }
        }
        return res;
    }
};