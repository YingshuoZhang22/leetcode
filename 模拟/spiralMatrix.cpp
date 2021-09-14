/* 54
Given an m x n matrix, return all elements of the matrix in spiral order.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int n = matrix.size();
        if (!n) return res;
        int m = matrix[0].size();

        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0}; // 顺序很重要，正好是移动顺序
        vector<vector<bool>> st(n, vector<bool>(m));

        for (int i = 0, x = 0, y = 0, d = 0; i < n * m; i ++ ) {
            res.push_back(matrix[x][y]);
            st[x][y] = true;

            int a = x + dx[d], b = y + dy[d];
            if (a < 0 || a >= n || b < 0 || b >= m || st[a][b]) {   // 这个坐标走过了
                d = (d + 1) % 4;
                a = x + dx[d], b = y + dy[d];
            }

            x = a, y = b;
        }

        return res;
    }
};

/* 59
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int>(n));
        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        vector<vector<bool>> st(n, vector<bool>(n));
        for (int i = 1, d = 0, x = 0, y = 0; i <= n * n; i++) {
            st[x][y] = true, v[x][y] = i;
            int a = x + dx[d], b = y + dy[d];
            if (a < 0 || a >= n || b < 0 || b >= n || st[a][b]) {
                d = (d + 1) % 4;
                a = x + dx[d], b = y + dy[d];
            }  
            x = a, y = b;
        }
        return v;
    }
};
