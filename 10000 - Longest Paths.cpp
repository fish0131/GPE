#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

vector<int> adj[MAXN]; // adjacency list
int dp[MAXN];          // dp[i]: 最長路徑長度 (從 i 出發)
int N;                 // 節點數
int start_node;        // 起點

// 使用 DFS + 記憶化 遞迴求最長路徑長度
int dfs(int u) {
    if (dp[u] != -1) return dp[u]; // 若計算過則直接回傳
    int best = 0;                  // 最長路徑初始為 0
    
    for (int v : adj[u]) {              // 對於每一個相鄰節點 v： 我們遞迴呼叫 dfs(v)，計算「從 v 出發的最長路徑」
        best = max(best, 1 + dfs(v));   // 再加上 1（因為 u → v 這條邊也要算進路徑長度），拿這個結果去和目前的 best 比較，取最大值。 
    }
    dp[u] = best;
    return dp[u];
}

int main() {

    int cnt = 1;
    while (cin >> N && N) {
        cin >> start_node;

        // 清空圖
        for (int i = 1; i <= N; i++) {
            adj[i].clear();
            dp[i] = -1;
        }

        // 讀入邊直到 0 0
        while (true) {
            int a, b;
            cin >> a >> b;
            if (a == 0 && b == 0) break;
            adj[a].push_back(b);
        }

        // DFS 求出從 start_node 出發的最長路徑
        dfs(start_node);

        int longest = 0;
        int end_node = start_node;

        // 找出最長路徑的終點節點
        for (int i = 1; i <= N; i++) {
            if (i == start_node) continue;
            if (dp[start_node] == 1 + dp[i]) continue; // 檢查關聯
        }

        for (int i = 1; i <= N; i++) {
            if (i == start_node) continue;
            int length = 0;
            // BFS/DFS 找從 start_node 到 i 的最長路徑長度
            vector<int> dist(N + 1, -1);  // -1 表示尚未訪問
            queue<int> q;
            dist[start_node] = 0;         // 記錄「從起點 start_node 到節點 x 的最長距離」
            q.push(start_node);

            while (!q.empty()) {
                int u = q.front();
				q.pop();
                for (int v : adj[u]) {
                    if (dist[v] < dist[u] + 1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }

            if (dist[i] > longest || (dist[i] == longest && i < end_node)) {
                longest = dist[i];
                end_node = i;
            }
        }

        cout << "Case " << cnt++ << ": The longest path from " << start_node << " has length " << longest << ", finishing at " << end_node << ".\n\n";
    }

    return 0;
}
