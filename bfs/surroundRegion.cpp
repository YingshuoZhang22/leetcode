/*  130. Surrounded Regions
Given an m x n matrix board containing 'X' and 'O', 
capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.
*/

#include <bits/stdc++.h>
using namespace std;

// BFS
class Solution {
public:
    typedef pair<int, int> PII;
    void solve(vector<vector<char>>& board) {
        queue<PII> q;
        int row = board.size(), col = board[0].size();
        if (!row || !col)   return;
        for (int i = 0; i < col; i++) {
            if (board[0][i] == 'O')  board[0][i] = 'A', q.push({0, i});
            if (board[row-1][i] == 'O')  board[row - 1][i] = 'A',  q.push({row-1, i});
        }
        for (int i = 0; i < row; i++) {
            if (board[i][0] == 'O') board[i][0] =  'A', q.push({i, 0});
            if (board[i][col - 1] == 'O')   board[i][col - 1] = 'A', q.push({i, col - 1});
        }

    // BFS 三色标记
        while (q.size()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++) {
                int xx = x + dx[i], yy = y + dy[i];
                if (xx >= 0 && xx < row && yy >= 0 && yy < col && board[xx][yy] == 'O') {
                    board[xx][yy] = 'A';
                    q.push({xx, yy});
                }
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'A') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
            cout << endl;
        }
        
    }
};

// DFS
class Solution {
public:
    int n, m;
    vector<vector<char>> board;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    void solve(vector<vector<char>>& _board) {
        board = _board;
        n = board.size();
        if (!n) return;
        m = board[0].size();

        for (int i = 0; i < n; i ++ ) {
            if (board[i][0] == 'O') dfs(i, 0);
            if (board[i][m - 1] == 'O') dfs(i, m - 1);
        }

        for (int i = 0; i < m; i ++ ) {
            if (board[0][i] == 'O') dfs(0, i);
            if (board[n - 1][i] == 'O') dfs(n - 1, i);
        }

        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                if (board[i][j] == '#') board[i][j] = 'O';
                else board[i][j] = 'X';

        _board = board;
    }

    void dfs(int x, int y) {
        board[x][y] = '#';
        for (int i = 0; i < 4; i ++ ) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m && board[a][b] == 'O')
                dfs(a, b);
        }
    }
};
