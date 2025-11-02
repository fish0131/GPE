#include <bits/stdc++.h>
using namespace std;

int H, W;
char grid[105][105];
bool visited[105][105];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool cmp(pair<char, int> a, pair<char, int> b) {
	if(a.second != b.second) return a.second > b.second;
	else return a.first < b.first;
}

void dfs(int x, int y, char lang) {
	if(x<0 || x>H || y<0 || y>W) return;
	if(visited[x][y] || grid[x][y] != lang) return;
	visited[x][y] = true;
	for(int i=0; i<4; i++) {
		dfs(x + dx[i], y + dy[i], lang);
	}
}

int main() {
	int t;
	cin >> t;
	for(int i=1; i<=t; i++) {
		cin >> H >> W;
		for(int i=0; i<H; i++) {
			for(int j=0; j<W; j++) {
				cin >> grid[i][j];
			}
		}
		
		cout << "World #" << i << '\n';
		
		memset(visited, false, sizeof(visited));
        map<char, int> count;
        
        for(int i=0; i<H; i++) {
        	for(int j=0; j<W; j++) {
        		if(!visited[i][j]) {
        			char lang = grid[i][j];
        			dfs(i ,j, lang);
        			count[lang]++;
				}
			}
		}
		
		vector<pair<char, int>> res(count.begin(), count.end());
		sort(res.begin(), res.end(), cmp);
		for(auto p: res) {
			cout << p.first << ": " << p.second << '\n';
		}
	}
}
