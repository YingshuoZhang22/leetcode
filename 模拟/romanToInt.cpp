#include <bits/stdc++.h>
using namespace std;

/*
首先建立一个HashMap来映射符号和值，然后对字符串从左到右来，
如果当前字符代表的值不小于其右边，就加上该值；否则就减去该值。
以此类推到最左边的数，最终得到的结果即是答案
*/

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> hash;
        hash['I'] = 1, hash['V'] = 5, hash['X'] = 10, hash['L'] = 50, 
            hash['C'] = 100, hash['D'] = 500, hash['M'] = 1000;
        int res = 0;
        for (int i = 0; i < s.size(); i ++ ) {
            if (i + 1 < s.size() && hash[s[i]] < hash[s[i + 1]])
                res -= hash[s[i]];
            else
                res += hash[s[i]];
        }
        return res;
    }
};
