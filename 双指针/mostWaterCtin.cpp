/* 11
Given n non-negative integers a1, a2, ..., an , where each 
represents a point at coordinate (i, ai). n vertical lines 
are drawn such that the two endpoints of the line i is at 
(i, ai) and (i, 0). Find two lines, which, together with the 
x-axis forms a container, such that the container contains 
the most water.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 双指针
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1, res = 0;
        while (i < j) {
            if (height[i] < height[j]) {
                res = max(res, (j - i) * height[i]);
                i++;
            } else {
                res = max(res, (j - i) * height[j]);
                j--;
            }
        }
        return res;
    }
};
