/* 265. Paint House II
There are a row of n houses, each house can be painted with one of the k colors. 
The cost of painting each house with a certain color is different. 
You have to paint all the houses such that no two adjacent houses have the same color.
*/

// 和 1289. Minimum Falling Path Sum II 一样

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
/* 
这题的关键是要认识到，要得到房间i上j色的最低价格，那么如果房间i-1不是上j色，则直接min + cost[i][j]即可，如果房间i-1是'j'色，则房间i上j色的最低价格是secondMin + cost[i][j]
*/
    int minCostII(vector<vector<int>>& costs) {

    }
};
