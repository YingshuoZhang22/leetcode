/* 128. Longest Consecutive Sequence

Given an unsorted array of integers nums, return the length of 
the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. 
Therefore its length is 4.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> hash;
        for (int i : nums)  hash.insert(i);
        // 每一段只枚举第一个数
        for (int i : hash) {
            if (hash.count(i - 1))    continue;
            else {
                int st = i, temp = 1;
                while (hash.count(st + 1)) {
                    st++, temp++;
                }
                res = max(res, temp);
            }
        }
        return res;
    }
};
