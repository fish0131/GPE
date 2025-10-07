#include <bits/stdc++.h>
using namespace std;

const int N = 10;
char maze[N][N];
bool visited[N][N];
int sx, sy, gx, gy;

// 四個方向：左、右、上、下
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool dfs(int x, int y) {
    if (x == gx && y == gy) return true; // 到達終點

    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue; // 越界
        if (maze[nx][ny] == '#' || visited[nx][ny]) continue; // 障礙或走過

        visited[nx][ny] = true;
        // 不要覆蓋 S 和 G
        if (!(nx == gx && ny == gy)) maze[nx][ny] = '+';

        if (dfs(nx, ny)) return true; // 成功找到路徑

        // 回溯（走錯路，恢復原狀）
        if (!(nx == gx && ny == gy)) maze[nx][ny] = '.';
    }
    return false;
}

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 'S') { sx = i; sy = j; }
            if (maze[i][j] == 'G') { gx = i; gy = j; }
        }
    }

    memset(visited, 0, sizeof(visited));
    visited[sx][sy] = true;

    if (dfs(sx, sy)) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << maze[i][j];
            }
            cout << "\n";
        }
    } 
	else {
        cout << "No solution\n";
    }
    cout << "\n"; // 空行
    return 0;
}
