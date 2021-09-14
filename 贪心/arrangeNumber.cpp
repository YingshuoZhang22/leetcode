/* 179. Largest Number
Given a list of non-negative integers nums, arrange them such that they form the largest number.

Note: The result may be very large, so you need to return a string instead of an integer.

Input: nums = [10,2]
Output: "210"

Input: nums = [3,30,34,5,9]
Output: "9534330"
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
    // 如果拼接结果 ab 要比 ba 好，那么我们会认为 a 应该放在 b 前面。
        sort(nums.begin(), nums.end(), [](int x, int y) {   // 重写比较函数
            string a = to_string(x), b = to_string(y);
            return a + b > b + a;
        });
        string res;
        for (auto s : nums) res += to_string(s);
        if (res[0] == '0')  return "0";
        return res;
    }
};