#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    while (cin >> N >> M) {
        vector<int> moves(M);
        for (int i = 0; i < M; i++) {
            cin >> moves[i];
        }

        vector<int> dp(N + 1, 0); // 0: losing, 1: winning
        for (int i = 1; i <= N; i++) {
            for (int s : moves) {
                if (i >= s && dp[i - s] == 0) {  // �i�H�� s ���]i >= s�^�B��������O���ѡ]dp[i-s] == 0�^,�Y���ӧ� 
                    dp[i] = 1; // Winning move found
                    break;
                }
            }
        }

        cout << (dp[N] ? "Stan wins" : "Ollie wins") << endl;
    }

    return 0;
}
