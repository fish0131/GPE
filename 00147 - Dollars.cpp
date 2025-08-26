#include<bits/stdc++.h>
using namespace std;

const int coins[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
const int MAXC = 30005;
long long dp[MAXC] = {0};

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
    
    dp[0] = 1;

    // 預處理所有金額
    for (int c : coins) {
        for (int i = c; i < MAXC; i++)
            dp[i] += dp[i - c];
    }

    string s;
    while (getline(cin, s)) {
    	if(s == "0.00") break;
        double amount;
        stringstream ss(s);
        ss >> amount;
        int cents = (int)round(amount * 100);
        cout << setw(6) << fixed << setprecision(2) << amount
             << setw(17) << dp[cents] << '\n';
    }
}

