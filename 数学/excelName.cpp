/* 168. Excel Sheet Column Title
Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
/*
一般性的进制转换题目无须进行额外操作，是因为我们是在「每一位数值范围在 [0,x)[0,x)」的前提下进行「逢 xx 进一」。

但本题需要我们将从 11 开始，因此在执行「进制转换」操作前，我们需要先对 columnNumbercolumnNumber 执行减一操作，从而实现整体偏移。

比如：0-1，100-101，1000-1001
*/
    string convertToTitle(int columnNumber) {
        string res;
        while (columnNumber > 0) {
            columnNumber -= 1;
            res += columnNumber % 26 + 'A';
            columnNumber /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


/* 171. Excel Sheet Column Number
上一题的逆运算
*/
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        long long v = 1;
        reverse(columnTitle.begin(), columnTitle.end());
        for (auto c: columnTitle) {
            res += (c - 'A' + 1) * v;
            v *= 26;
        }
        return res;
    }
};
