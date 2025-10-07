#include <bits/stdc++.h>
using namespace std;

int n, k;
double dp[105][15];

int main() {
    while(cin >> k >> n) {
    	memset(dp, 0, sizeof(dp));
    	for(int j = 0; j <= k; j++) dp[1][j] = 1.0 / (k + 1);
    	// DP�G�v�B�p����v
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                if (j > 0) dp[i][j] += dp[i-1][j-1] / (k + 1); // �q j-1 �ಾ
                dp[i][j] += dp[i-1][j] / (k + 1);              // �q j   �ಾ
                if (j < k) dp[i][j] += dp[i-1][j+1] / (k + 1); // �q j+1 �ಾ
            }
        }
		double sum = 0;
		for(int j = 0; j <= k; j++) {
			sum += dp[n][j];
		}
		cout << fixed << setprecision(5) << sum * 100 << '\n'; 
	}
}
