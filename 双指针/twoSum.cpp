#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for (int i = 0, j = nums.size() - 1; i < j; i++) {
            while (j > 0 && nums[i] + nums[j] > target)  j--;
            if (nums[i] + nums[j] == target) {
                res.push_back(i), res.push_back(j);
                break;
            }
        }
        return res;
    }
};
