/* 172. Factorial Trailing Zeroes
Given an integer n, return the number of trailing zeroes in n!.
*/

class Solution {
public:
/*
由于n!的后缀0是由起质因子2和质因子5相乘而来的，而2的个数总是比5多的，因此我们只需要计算n!中质因子5的个数即可。

要求n!中质因子5的个数即可，可以通过求∑n / 5^i而得。

例如，求245！末尾0的个数时，
245/5=49 代表着有49个数(可被55整除)贡献了1个5，
245/25=9 代表着有9个数(可被5×55×5整除)在上一行的基础上多贡献了1个5，
245/125=1 代表着有1个数(可被5×5×55×5×5整除)在上一行的基础上多贡献了1个5，
*/
    int trailingZeroes(int n) {
        int count = 0;
        while(n >= 5) {
            count += n / 5;
            n /= 5;
        }
        return count;
    }
};