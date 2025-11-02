#include <bits/stdc++.h>
using namespace std;

int H, W;
char grid[105][105];
bool visited[105][105];

int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};


void dfs(int x, int y) {
    if (x < 0 || x >= H || y < 0 || y >= W) return;
    if (visited[x][y] || grid[x][y] != '@') return;
    visited[x][y] = true;
    for (int i = 0; i < 8; i++) {
        dfs(x + dx[i], y + dy[i]);
    }
}

int main() {
	while(cin >> H >> W) {
		if(H == 0 && W == 0) break;
				
		for(int i=0; i<H; i++) {
			for(int j=0; j<W; j++) {
				cin >> grid[i][j];
			}
		}
		
		memset(visited, false, sizeof(visited));
	    int count = 0;
	    
	    for(int i=0; i<H; i++) {
	    	for(int j=0; j<W; j++) {
	    		if (!visited[i][j] && grid[i][j] == '@') {
				    dfs(i, j);
				    count++;
				}
			}
		}
		cout << count << '\n';	
	}
}
