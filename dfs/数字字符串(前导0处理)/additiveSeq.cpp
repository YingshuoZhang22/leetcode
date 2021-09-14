/* 306. Additive Number
Additive number is a string whose digits can form additive sequence.

A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.

Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

Example 1:

Input: "112358"
Output: true
Explanation: The digits can form an additive sequence: 1, 1, 2, 3, 5, 8. 
             1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        vector<long double>tmp;
        return dfs(num,tmp);
    }
    bool dfs(string num,vector<long double> tmp){
        int n = tmp.size();
        if (n >= 3 && tmp[n-1] != tmp[n-2] + tmp[n-3]) return false;
        if (num.size() == 0 && n >= 3) return true;
        for (int i = 0; i<num.size(); ++i) {
            string cur = num.substr(0, i+1);
            if (cur[0]=='0' && cur.size()!=1) continue;  // not start with 0
            tmp.push_back(stold(cur));
            if (dfs(num.substr(i+1),tmp)) return true;
            tmp.pop_back();
        }
        return false;
    }
};
