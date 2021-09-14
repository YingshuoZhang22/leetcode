/*
给定一个 n×m 的二维整数数组，用来表示一个迷宫，数组中只包含 0 或 1，其中 0 表示可以走的路，1 表示不可通过的墙壁。
最初，有一个人位于左上角 (1,1) 处，已知该人每次可以向上、下、左、右任意一个方向移动一个位置。
请问，该人从左上角移动至右下角 (n,m) 处，至少需要移动多少次。
数据保证 (1,1) 处和 (n,m) 处的数字为 0，且一定至少存在一条通路。
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 110;
int graph[N][N], dist[N][N];    //存放地图和每一个点到起点的距离
int n, m;

int bfs() { 
    queue<PII> q;
    q.push({0, 0});
    memset(dist, -1, sizeof(dist)); // 距离初始化为-1，没走过
    dist[0][0] = 0;     // 起点走过了
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}; //x 方向的向量和 y 方向的向量组成的上、右、下、左
    
    while (q.size()) {  //队列不为空
        PII t = q.front();  //取队头元素
        q.pop();    //出队
        for (int i = 0; i < 4; i ++) {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && graph[x][y] == 0 && dist[x][y] == -1) {   // == -1保证选了的都是没走过的，也就是correctness
                dist[x][y] = dist[t.first][t.second] + 1;//当前点到起点的距离
                q.push({x, y});    //将新坐标入队
            }
        }
    }
    return dist[n - 1][m - 1];
}

int main()  {
    cin >> n >> m;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++)
            cin >> graph[i][j];
    cout << bfs() << endl;
    return 0;
}