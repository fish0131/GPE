#include <bits/stdc++.h>
using namespace std;

const int N = 10;
char maze[N][N];
bool visited[N][N];
int sx, sy, gx, gy;

// �|�Ӥ�V�G���B�k�B�W�B�U
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool dfs(int x, int y) {
    if (x == gx && y == gy) return true; // ��F���I

    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue; // �V��
        if (maze[nx][ny] == '#' || visited[nx][ny]) continue; // ��ê�Ψ��L

        visited[nx][ny] = true;
        // ���n�л\ S �M G
        if (!(nx == gx && ny == gy)) maze[nx][ny] = '+';

        if (dfs(nx, ny)) return true; // ���\�����|

        // �^���]�������A��_�쪬�^
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
    cout << "\n"; // �Ŧ�
    return 0;
}
