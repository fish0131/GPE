#include <bits/stdc++.h>
using namespace std;

int n, k;
double dp[105][15];

int main() {
    while(cin >> k >> n) {
    	memset(dp, 0, sizeof(dp));
    	for(int j = 0; j <= k; j++) dp[1][j] = 1.0 / (k + 1);
    	// DP：逐步計算機率
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                if (j > 0) dp[i][j] += dp[i-1][j-1] / (k + 1); // 從 j-1 轉移
                dp[i][j] += dp[i-1][j] / (k + 1);              // 從 j   轉移
                if (j < k) dp[i][j] += dp[i-1][j+1] / (k + 1); // 從 j+1 轉移
            }
        }
		double sum = 0;
		for(int j = 0; j <= k; j++) {
			sum += dp[n][j];
		}
		cout << fixed << setprecision(5) << sum * 100 << '\n'; 
	}
}
