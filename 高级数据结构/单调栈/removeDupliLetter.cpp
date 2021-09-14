/* 316. Remove Duplicate Letters
Given a string s, remove duplicate letters so that every letter 
appears once and only once. You must make sure your result is the 
smallest in lexicographical order among all possible results.

Input: s = "bcabc"
Output: "abc"

Input: s = "cbacdcbc"
Output: "acdb"
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

// 使用栈来贪心的构造最终的字符串，栈的更新规则如下。
// 前提是当前字符没有在栈中出现。如果当前字符比栈顶字符的值小，且栈顶字符不是最后一次出现，则栈顶出栈。
// 重复 2 直到栈空或栈顶不满足出栈条件。此时，将当前字符压入栈中，且标记当前字符出现过。
// 最后将栈中元素从栈底到栈顶的顺序输出。
    string removeDuplicateLetters(string s) {
        string res;
        unordered_map<char, int> last_app;
        unordered_map<char, bool> visited;
        for (int i = 0; i < s.size(); i++)  last_app[s[i]] = i;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (visited[ch])    continue;
            while (res.size() && res.back() > ch && last_app[res.back()] > i) {
                visited[res.back()] = false;
                res.pop_back();
            }
            res += ch;
            visited[ch] = true;
        }
        return res;
    }
};
