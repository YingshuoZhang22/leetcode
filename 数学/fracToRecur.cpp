/*166. Fraction to Recurring Decimal
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

If multiple answers are possible, return any of them.

It is guaranteed that the length of the answer string is less than 104 for all the given inputs.

Input: numerator = 1, denominator = 2
Output: "0.5"

Input: numerator = 2, denominator = 1
Output: "2"

Input: numerator = 2, denominator = 3
Output: "0.(6)"

Input: numerator = 4, denominator = 333
Output: "0.(012)"

Input: numerator = 1, denominator = 5
Output: "0.2"
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        typedef long long LL;
        LL x = numerator, y = denominator;
        if (x % y == 0) return to_string(x / y);
        string res;
        if ((x < 0) ^ (y < 0)) res += '-';
        x = abs(x), y = abs(y);
        res += to_string(x / y) + '.', x %= y;
/*计算小数部分的难点在于如何判断是否是循环小数，以及找出循环节的位置。
回忆手工计算除法的过程，每次将余数乘10再除以除数，当同一个余数出现两次时，我们就找到了循环节。
所以我们可以用一个哈希表 unordered_map<int,int> 记录所有余数所对应的商在小数点后第几位，当计算到相同的余数时，上一次余数的位置和当前位置之间的数，就是该小数的循环节。
*/
        unordered_map<LL, int> hash;
        while (x) {
            hash[x] = res.size();
            x *= 10;
            res += to_string(x / y);
            x %= y;
            // cout << res << endl;
            if (hash.count(x)) {
                res = res.substr(0, hash[x]) + '(' + res.substr(hash[x]) + ')';
                break;
            }
        }
        
        return res;
    }
};

