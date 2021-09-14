/* 96
Given an integer n, return the number of structurally unique BST's 
(binary search trees) which has exactly n nodes of unique values 
from 1 to n.
*/

class Solution {
public:
// 第 n 个 卡特兰数
    int numTrees(int n) {
        if (n <= 0) return 0;
        long long res = 1;
        for (int i = 1; i <= n; ++i){
            res = res * (i + n) / i ;
        }
        return res / (n + 1);
    }
};
