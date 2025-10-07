#include <bits/stdc++.h>
using namespace std;

// 目標：最小化「你付出去的硬幣數量 + 店家找零的硬幣數量」
// 分兩個動態規劃： dp_you 有限背包、dp_shop 無限背包 
// 你有有限數量的硬幣
// 店家硬幣無限供應

const int MAXV = 1000; // 最多考慮 1000 個 5c 單位 (=$50，實際交易<=$5，夠用了)
const int INF = 1e9;

// 5c 為單位
// 5c ->  1
// 10c -> 2
// 20c -> 4
// 50c -> 10
// $1 ->  20
// $2 ->  40

int coinValue[6] = {1, 2, 4, 10, 20, 40}; 
int shopDP[MAXV+1]; 

// 預處理：店家無限硬幣的最少硬幣數
void buildShopDP() {
    fill(shopDP, shopDP+MAXV+1, INF);
    shopDP[0] = 0;
    for (int c = 0; c < 6; c++) {
        for (int i = coinValue[c]; i <= MAXV; i++) {
            shopDP[i] = min(shopDP[i], shopDP[i-coinValue[c]] + 1);
        }
    }
}

int main() {
    buildShopDP();

    int num[6];
    double amount;
    while (true) {
        for (int i = 0; i < 6; i++) cin >> num[i];
        if (*max_element(num, num+6) == 0) break;
        cin >> amount;

        int target = round(amount * 20); // 換成以 5c 為單位

        // 你能湊的金額 DP
        vector<int> dp(MAXV+1, INF);
        dp[0] = 0;

        // 有限背包（多重背包）
        for (int c = 0; c < 6; c++) {
            for (int k = 0; (1<<k) <= num[c]; k++) { // 二進位拆分
                int use = min(num[c] - ((1<<k)-1), 1<<k);
                int val = use * coinValue[c];
                for (int i = MAXV; i >= val; i--) {
                    dp[i] = min(dp[i], dp[i-val] + use);
                }
            }
        }

        int ans = INF;
        for (int p = target; p <= MAXV; p++) {
            if (dp[p] < INF && shopDP[p-target] < INF) {
                ans = min(ans, dp[p] + shopDP[p-target]);
            }
        }

        cout << setw(3) << ans << "\n";
    }
    return 0;
}
