#include <bits/stdc++.h>
using namespace std;

// �ؼСG�̤p�ơu�A�I�X�h���w���ƶq + ���a��s���w���ƶq�v
// ����ӰʺA�W���G dp_you �����I�]�Bdp_shop �L���I�] 
// �A�������ƶq���w��
// ���a�w���L������

const int MAXV = 1000; // �̦h�Ҽ{ 1000 �� 5c ��� (=$50�A��ڥ��<=$5�A���ΤF)
const int INF = 1e9;

// 5c �����
// 5c ->  1
// 10c -> 2
// 20c -> 4
// 50c -> 10
// $1 ->  20
// $2 ->  40

int coinValue[6] = {1, 2, 4, 10, 20, 40}; 
int shopDP[MAXV+1]; 

// �w�B�z�G���a�L���w�����ֵ̤w����
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

        int target = round(amount * 20); // �����H 5c �����

        // �A��ꪺ���B DP
        vector<int> dp(MAXV+1, INF);
        dp[0] = 0;

        // �����I�]�]�h���I�]�^
        for (int c = 0; c < 6; c++) {
            for (int k = 0; (1<<k) <= num[c]; k++) { // �G�i����
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
