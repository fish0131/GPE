#include <bits/stdc++.h>
using namespace std;

int l, n;
int cut[55];
int dp[55][55];   // dp[x][y] 表示 從 a[x] 到 a[y] 這段木棍的最小花費

///////////////////////////////////
////////        TLE        ////////
///////////////////////////////////
//int solve(int x, int y){
//    if (~dp[x][y]) return dp[x][y];  // 如果已經算過，就直接回傳 (記憶化)
//    if (x+1==y) return dp[x][y] = 0;   // 如果區間內沒有切割點，花費為 0
//    int cost = INT_MAX;
//    for (int i=x+1 ; i<y ;i++){
//        cost = min(cost, solve(x, i) + solve(i, y));  // 左半段的最小花費 + 右半段的最小花費
//    }
//    return cost + cut[y] - cut[x];  // cut[y] - cut[x]: 這一段木棍的長度 
//}


int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    while (cin >> l && l) {
        cin >> n;
        cut[0] = 0;
        for (int i = 1; i <= n; i++) cin >> cut[i];
        cut[n+1] = l;

        // 初始化 dp
        memset(dp, 0, sizeof(dp));

        // 區間 DP: 長度從小到大
        for (int len = 2; len <= n+1; len++) {  // 區間長度
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
