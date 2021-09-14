#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;
    vector<bool> row, col, diag, anti_diag;

// 搜索时需要记录4个状态：x,y,s,n 分别表示横纵坐标、已摆放的皇后个数、棋盘大小。
    void dfs(int x, int y, int s, int n) {
        if (y == n) x ++ , y = 0;
        if (x == n) {
            if (s == n) ans.push_back(path);
            return ;
        }

        dfs(x, y + 1, s, n);
        if (!row[x] && !col[y] && !diag[x + y] && !anti_diag[n - 1 - x + y]) {
            row[x] = col[y] = diag[x + y] = anti_diag[n - 1 - x + y] = true;
            path[x][y] = 'Q';
            dfs(x, y + 1, s + 1, n);
            path[x][y] = '.';
            row[x] = col[y] = diag[x + y] = anti_diag[n - 1 - x + y] = false;
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        row = col = vector<bool>(n, false);
        diag = anti_diag = vector<bool>(2 * n, false);
        path = vector<string>(n, string(n, '.'));
        dfs(0, 0, 0, n);
        return ans;
    }
};