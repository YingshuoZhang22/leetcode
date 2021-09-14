/* 79
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, 
where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<bool>> used;
    vector<vector<char>> boar;
    bool flag;
    string target;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    void dfs(int x, int y, int idx) {
        if (idx == target.size() - 1) {
            if (boar[x][y] == target[idx]) {
                flag = true;
                return;
            }
        }
        if (boar[x][y] == target[idx]) {
            used[x][y] = true;
            for (int i = 0; i < 4; i++) {
                int x_coord = x + dx[i], y_coord = y + dy[i];
                if (x_coord >= 0 && y_coord >= 0 && x_coord < boar.size() && y_coord < boar[0].size() && !used[x_coord][y_coord]) {
                    dfs(x_coord, y_coord, idx + 1);
                }
            }
            used[x][y] = false;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        target = word;
        boar = board;
        used = vector<vector<bool>> (board.size(), vector<bool>(board[0].size(), 0));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    dfs(i, j, 0);
                }
            }
        }
        return flag;
    }
};

/* 212. Word Search II
Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]
*/

class Solution {
public:
    struct Node {
        int id;
        Node *son[26];
        Node() {
            id = -1;
            for (int i = 0; i < 26; i ++ ) son[i] = NULL;
        }
    }*root;
    unordered_set<int> ids;
    vector<vector<char>> g;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    void insert(string& word, int id) {
        auto p = root;
        for (auto c: word) {
            int u = c - 'a';
            if (!p->son[u]) p->son[u] = new Node();
            p = p->son[u];
        }
        p->id = id;
    }
    
    // 根据字典建trie，在board dfs过程中剪枝
    // 你要是根据board建造trie，那你就等着吧...
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        g = board;
        root = new Node();
        for (int i = 0; i < words.size(); i ++ ) insert(words[i], i);

        for (int i = 0; i < g.size(); i ++ )
            for (int j = 0; j < g[i].size(); j ++ ) {
                int u = g[i][j] - 'a';
                if (root->son[u])
                    dfs(i, j, root->son[u]);
            }

        vector<string> res;
        for (auto id: ids) res.push_back(words[id]);
        return res;
    }

    void dfs(int x, int y, Node* p) {
        if (p->id != -1) ids.insert(p->id);
        char t = g[x][y];
        g[x][y] = '.';
        for (int i = 0; i < 4; i ++ ) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < g.size() && b >= 0 && b < g[0].size() && g[a][b] != '.') {
                int u = g[a][b] - 'a';
                if (p->son[u]) dfs(a, b, p->son[u]);
            }
        }
        g[x][y] = t;
    }
};
