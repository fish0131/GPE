#include <bits/stdc++.h>
using namespace std;

unsigned int N , L ,U;

int main() {
	//ios::sync_with_stdio(0), cin.tie(0);
    while(cin >> N >> L >> U) {
    	unsigned int ans = 0;
    	// 從最高位 (bit 31) 到最低位 (bit 0) 一個一個決定 ans 的每個 bit
    	// 要讓結果 N OR ans 最大 → 高位能設 1 就盡量設 1。
    	for(int i=31; i>=0; i--) {
    		if ((ans | (1<<i)) > U ) continue;
	        if ((ans | (1<<i)) <= L || !(N & (1 << i))){
	            ans |= (1 << i);
	        }
		}
		cout << ans << '\n';
	}
}
