#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

vector<int> adj[MAXN]; // adjacency list
int dp[MAXN];          // dp[i]: �̪����|���� (�q i �X�o)
int N;                 // �`�I��
int start_node;        // �_�I

// �ϥ� DFS + �O�Ф� ���j�D�̪����|����
int dfs(int u) {
    if (dp[u] != -1) return dp[u]; // �Y�p��L�h�����^��
    int best = 0;                  // �̪����|��l�� 0
    
    for (int v : adj[u]) {              // ���C�@�Ӭ۾F�`�I v�G �ڭ̻��j�I�s dfs(v)�A�p��u�q v �X�o���̪����|�v
        best = max(best, 1 + dfs(v));   // �A�[�W 1�]�]�� u �� v �o����]�n��i���|���ס^�A���o�ӵ��G�h�M�ثe�� best ����A���̤j�ȡC 
    }
    dp[u] = best;
    return dp[u];
}

int main() {

    int cnt = 1;
    while (cin >> N && N) {
        cin >> start_node;

        // �M�Ź�
        for (int i = 1; i <= N; i++) {
            adj[i].clear();
            dp[i] = -1;
        }

        // Ū�J�䪽�� 0 0
        while (true) {
            int a, b;
            cin >> a >> b;
            if (a == 0 && b == 0) break;
            adj[a].push_back(b);
        }

        // DFS �D�X�q start_node �X�o���̪����|
        dfs(start_node);

        int longest = 0;
        int end_node = start_node;

        // ��X�̪����|�����I�`�I
        for (int i = 1; i <= N; i++) {
            if (i == start_node) continue;
            if (dp[start_node] == 1 + dp[i]) continue; // �ˬd���p
        }

        for (int i = 1; i <= N; i++) {
            if (i == start_node) continue;
            int length = 0;
            // BFS/DFS ��q start_node �� i ���̪����|����
            vector<int> dist(N + 1, -1);  // -1 ��ܩ|���X��
            queue<int> q;
            dist[start_node] = 0;         // �O���u�q�_�I start_node ��`�I x ���̪��Z���v
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
