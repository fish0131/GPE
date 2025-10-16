#include<bits/stdc++.h>
using namespace std;

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int n, m;

int main() {
	int Case = 1;
	while(cin >> n >> m && n && m) {
		vector<string> grid(n);
		for(int i=0; i<n; i++) cin >> grid[i];
		vector<vector<int>> ans(n, vector<int>(m));
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(grid[i][j] == '.') {
					int cnt = 0;
					for(int k=0; k<8; k++) {
						int ni = i + dx[k];
						int nj = j + dy[k];
						if(ni >= 0 && nj >= 0 && ni < n && nj < m && grid[ni][nj] == '*') cnt++;
					} 
					ans[i][j] = cnt;
				}
			}
		}
		cout << "Field #" << Case++ << ": " << '\n';
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(grid[i][j] == '*') cout << "*";
				else cout << ans[i][j];
			}
			cout << '\n';
		}
		cout << '\n';
	}
}
