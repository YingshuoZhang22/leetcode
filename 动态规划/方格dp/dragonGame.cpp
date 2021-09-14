/* 174. Dungeon Game
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& w) {
        int n = w.size(), m = w[0].size();
        vector<vector<int>> f(n, vector<int>(m, 1e8));
    // f[i][j]存的是从i，j出发到终点的最少生命值，倒着dp
        for (int i = n - 1; i >= 0; i -- )
            for (int j = m - 1; j >= 0; j -- )
            // max(1)因为生命值最小是1
                if (i == n - 1 && j == m - 1) f[i][j] = max(1, 1 - w[i][j]);
                else {
                    if (i + 1 < n) f[i][j] = f[i + 1][j] - w[i][j];
                    if (j + 1 < m) f[i][j] = min(f[i][j], f[i][j + 1] - w[i][j]);
                    f[i][j] = max(1, f[i][j]);
                }

        return f[0][0];
    }
};