#include <iostream>
#include <vector>
using namespace std;

// 模版：

class UnionFind {
public:
    UnionFind(int N) {
        for (int i = 0; i < N; ++i) {
            parent.push_back(i);
        }
        count = 0;
    }

    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }

    int getCount() {
        return count;
    }

    void addCount() {
        count++;
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) {
            return;
        }
        
        parent[rootX] = rootY;
        count--;
    }

    int getCount() const {
        return count;
    }

private:
    vector<int> parent;
    int count;
};

/* 305. 岛屿数量 II
假设你设计一个游戏，用一个 m 行 n 列的 2D 网格来存储你的游戏地图。
起始的时候，每个格子的地形都被默认标记为「水」。我们可以通过使用 addLand 进行操作，将位置 (row, col) 的「水」变成「陆地」。
你将会被给定一个列表，来记录所有需要被操作的位置，然后你需要返回计算出来 每次 addLand 操作后岛屿的数量。

注意：一个岛的定义是被「水」包围的「陆地」，通过水平方向或者垂直方向上相邻的陆地连接而成。你可以假设地图网格的四边均被无边无际的「水」所包围。

请仔细阅读下方示例与解析，更加深入了解岛屿的判定。

示例:

输入: m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]]
输出: [1,1,2,3]
解析:

起初，二维网格 grid 被全部注入「水」。（0 代表「水」，1 代表「陆地」）
0 0 0
0 0 0
0 0 0

操作 #1：addLand(0, 0) 将 grid[0][0] 的水变为陆地。

1 0 0
0 0 0   Number of islands = 1
0 0 0

操作 #2：addLand(0, 1) 将 grid[0][1] 的水变为陆地。

1 1 0
0 0 0   岛屿的数量为 1
0 0 0

操作 #3：addLand(1, 2) 将 grid[1][2] 的水变为陆地。

1 1 0
0 0 1   岛屿的数量为 2
0 0 0

操作 #4：addLand(2, 1) 将 grid[2][1] 的水变为陆地。

1 1 0
0 0 1   岛屿的数量为 3
0 1 0
*/

class Solution {
private:
    bool inArea(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

public:
    vector<int> numIslands2(int m, int n, vector<vector<int>> &positions) {
        UnionFind unionFind(m * n);
        vector<bool> visited;
        for (size_t i = 0; i < m * n; i++) {
            visited.push_back(false);
        }

        int DIRECTIONS[4][2] = {{0,  1},
                                {1,  0},
                                {0,  -1},
                                {-1, 0}};
        vector<int> res;
        for (auto &position : positions) {
            int currX = position[0];
            int currY = position[1];

            int index = currX * n + currY;
            if (!visited[index]) {
                // 把水变成陆地，连通分量个数加 1
                unionFind.addCount();
                visited[index] = true;
                for (auto &direction : DIRECTIONS) {
                    int newX = currX + direction[0];
                    int newY = currY + direction[1];
                    int newIndex = newX * n + newY;
                    // 下面这三个条件很重要
                    if (inArea(newX, newY, m, n)
                        && visited[newIndex]
                        && !unionFind.isConnected(index, newIndex)) {
                        unionFind.unionSet(index, newIndex);
                    }
                }
            }
            res.push_back(unionFind.getCount());
        }
        return res;
    }
};
