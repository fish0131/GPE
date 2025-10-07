#include <bits/stdc++.h>
using namespace std;

int l, n;
int cut[55];
int dp[55][55];   // dp[x][y] ��� �q a[x] �� a[y] �o�q��Ҫ��̤p��O

///////////////////////////////////
////////        TLE        ////////
///////////////////////////////////
//int solve(int x, int y){
//    if (~dp[x][y]) return dp[x][y];  // �p�G�w�g��L�A�N�����^�� (�O�Ф�)
//    if (x+1==y) return dp[x][y] = 0;   // �p�G�϶����S�������I�A��O�� 0
//    int cost = INT_MAX;
//    for (int i=x+1 ; i<y ;i++){
//        cost = min(cost, solve(x, i) + solve(i, y));  // ���b�q���̤p��O + �k�b�q���̤p��O
//    }
//    return cost + cut[y] - cut[x];  // cut[y] - cut[x]: �o�@�q��Ҫ����� 
//}


int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    while (cin >> l && l) {
        cin >> n;
        cut[0] = 0;
        for (int i = 1; i <= n; i++) cin >> cut[i];
        cut[n+1] = l;

        // ��l�� dp
        memset(dp, 0, sizeof(dp));

        // �϶� DP: ���ױq�p��j
        for (int len = 2; len <= n+1; len++) {  // �϶�����
            for (int i = 0; i + len <= n+1; i++) {
                int j = i + len;
                dp[i][j] = INT_MAX;
                for (int k = i+1; k<j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + cut[j] - cut[i]);
                }
            }
        }

        cout << "The minimum cutting is " << dp[0][n+1] << "." << '\n';
    }
    return 0;
}
