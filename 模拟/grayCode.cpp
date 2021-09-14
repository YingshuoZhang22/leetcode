/* 89
An n-bit gray code sequence is a sequence of 2n integers where:

Every integer is in the inclusive range [0, 2n - 1],
The first integer is 0,
An integer appears no more than once in the sequence,
The binary representation of every pair of adjacent integers differs by exactly one bit, and
The binary representation of the first and last integers differs by exactly one bit.
Given an integer n, return any valid n-bit gray code sequence.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
/*
我们可以先打表找规律，随便找出一种格雷码的构造方法即可。
我们可以递归构造：

先构造 n=1，即只有一位的格雷码序列：[0, 1]；
假设我们已经构造好了 n=kn=k时的格雷码序列 Sk，我们可以利用它来构造 Sk+1：
(1) Sk+1的前一半：将 Sk 中的每个数开头补上1；
(2) Sk+1的后一半，将 Sk 变成逆序，然后在每个数开头补上0；
*/
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        int t = 1;
        while (n -- )
        {
            vector<int> newRes;
            for (int i = 0; i < res.size(); i ++ )
                newRes.push_back(res[i]);
            for (int i = res.size() - 1; i >= 0; i -- )
                newRes.push_back(t + res[i]);
            res = newRes;
            t *= 2;
        }
        return res;
    }
};