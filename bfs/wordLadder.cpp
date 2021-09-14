/* 127. Word Ladder （有点像最短路）
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_set<string> S;    // all words in satrt dictionary
    unordered_map<string, int> dist;    // current word - length of step
    queue<string> q;
    vector<vector<string>> ans;
    vector<string> path;
    string beginWord;

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for (auto word : wordList)    S.insert(word);
        dist[beginWord] = 0;
        q.push(beginWord);
        while (q.size()) {  // 普普通通的BFS求最短路
            string target = q.front();
            q.pop();
            string tmp = target;
            for (int i = 0; i < target.size(); i++) {
                target = tmp;
                for (char c = 'a'; c <= 'z'; c ++) {
                    target[i] = c;
                    if (S.count(target) && dist.count(target) == 0) {   // 字典里有这个词而且还没有被遍利过
                        dist[target] = dist[tmp] + 1;
                        if (target == endWord)  return dist[target] + 1;
                        q.push(target);
                    }
                }
            }
        }
        return 0;
    }
};

/* 126. 126. 单词接龙 II
按字典 wordList 完成从单词 beginWord 到单词 endWord 转化，一个表示此过程的 转换序列 是形式上像 beginWord -> s1 -> s2 -> ... -> sk 这样的单词序列，并满足：

每对相邻的单词之间仅有单个字母不同。
转换过程中的每个单词 si（1 <= i <= k）必须是字典 wordList 中的单词。注意，beginWord 不必是字典 wordList 中的单词。
sk == endWord
给你两个单词 beginWord 和 endWord ，以及一个字典 wordList 。请你找出并返回所有从 beginWord 到 endWord 的 最短转换序列 ，如果不存在这样的转换序列，返回一个空列表。每个序列都应该以单词列表 [beginWord, s1, s2, ..., sk] 的形式返回。

输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
输出：[["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
解释：存在 2 种最短的转换序列：
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"
示例 2：

输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
输出：[]
解释：endWord "cog" 不在字典 wordList 中，所以不存在符合要求的转换序列。
*/


class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;
    unordered_set<string> S;
    unordered_map<string, int> dist;

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        for (auto& word: wordList) S.insert(word);
        queue<string> q;
        q.push(beginWord);
        dist[beginWord] = 0;
        while (q.size()) {
            auto t = q.front();
            q.pop();
            string r = t;
            for (int i = 0; i < t.size(); i ++ ) {
                t = r;
                for (char j = 'a'; j <= 'z'; j ++ )
                    if (j != r[i]) {
                        t[i] = j;
                        if (S.count(t) && dist.count(t) == 0) {
                            dist[t] = dist[r] + 1;
                            if (t == endWord) break;
                            q.push(t);
                        }
                    }
            }
        }

        if (dist.count(endWord)) {
            path.push_back(beginWord);
            dfs(beginWord, endWord);
        }

        return ans;
    }

    void dfs(string st, string ed) {
        if (st == ed) {
            ans.push_back(path);
            return;
        }

        string r = st;
        for (int i = 0; i < st.size(); i ++ ) {
            st = r;
            for (char j = 'a'; j <= 'z'; j ++ )
                if (j != r[i]) {
                    st[i] = j;
                    if (S.count(st) && dist[r] + 1 == dist[st]) {
                        path.push_back(st);
                        dfs(st, ed);
                        path.pop_back();
                    }
                }
        }
    }
};