/* 73
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.

You must do it in place. (O(1) space)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

/*
用两个变量记录第一行和第一列是否有0。
遍历整个矩阵，用矩阵的第一行和第一列记录对应的行和列是否有0。
把含有0的行和列都置成0。
*/

    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;
        int n = matrix.size(), m = matrix[0].size();
        int col0 = 1, row0 = 1;
        for (int i = 0; i < n; i ++ )
            if (!matrix[i][0]) col0 = 0;
        for (int i = 0; i < m; i ++ )
            if (!matrix[0][i]) row0 = 0;
        for (int i = 1; i < n; i ++ )
            for (int j = 1; j < m; j ++ )
                if (!matrix[i][j]) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
                
        for (int i = 1; i < n; i ++ )
            if (!matrix[i][0])
                for (int j = 1; j < m; j ++ )
                    matrix[i][j] = 0;

        for (int i = 1; i < m; i ++ )
            if (!matrix[0][i])
                for (int j = 1; j < n; j ++ )
                    matrix[j][i] = 0;

        if (!col0)
            for (int i = 0; i < n; i ++ )
                matrix[i][0] = 0;

        if (!row0)
            for (int i = 0; i < m; i ++ )
                matrix[0][i] = 0;
    }
};
