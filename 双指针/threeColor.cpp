/* 75
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Inplace, one scan
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 循环不变量：[0, j-1]都是0，[j, i-1]都是1， [k+1, end)都是2，[i, k]是没处理的
        for (int i = 0, j = 0, k = nums.size() - 1; i <= k;) {
            // 给[0, j-1]扩成[0,j], [j, i-1]扩成[j+1, i]
            if (nums[i] == 0) swap(nums[i ++ ], nums[j ++ ]);

            // 缩一个k，把k的换给i到下一轮去处理
            else if (nums[i] == 2) swap(nums[i], nums[k -- ]);

            // 扩[j, i-1]
            else if (nums[i] == 1) i ++ ;
        }
        
    }
};