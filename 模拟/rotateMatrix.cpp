/* 48
You are given an n x n 2D matrix representing an image,
 rotate the image by 90 degrees (clockwise).
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 先沿对角线反转
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < i; j++) 
                swap(matrix[i][j], matrix[j][i]);
        // 再每行镜像反转
        for (int i = 0; i < n; i++) 
            for (int j = 0, k = n - 1; j < k; j++, k--)
                swap(matrix[i][j], matrix[i][k]);
    }
};