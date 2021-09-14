/*214. Shortest Palindrome
You are given a string s. You can convert s to a palindrome by adding characters in front of it.

Return the shortest palindrome you can find by performing this transformation.

Input: s = "aacecaaa"
Output: "aaacecaaa"
Example 2:

Input: s = "abcd"
Output: "dcbabcd"
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
// 等价于找s的longest palindrome prefex， 方法：
// 假设s为 abbacd，拼接一个s没出现过的字符$和s的reverse：
// abbacd¥dcbaab，等价于找这个新串的KMP数组的next数组的最后一位
    string shortestPalindrome(string s) {
        string t(s.rbegin(), s.rend());
        int n = s.size();
        s = ' ' + s + '#' + t;
        vector<int> ne(n * 2 + 2);
        for (int i = 2, j = 0; i <= n * 2 + 1; i ++ ) {
            while (j && s[i] != s[j + 1]) j = ne[j];
            if (s[i] == s[j + 1]) j ++ ;
            ne[i] = j;
        }
        int len = ne[n * 2 + 1];
        string left = s.substr(1, len), right = s.substr(1 + len, n - len);
        return string(right.rbegin(), right.rend()) + left + right;
    }
};