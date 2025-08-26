#include<bits/stdc++.h>
using namespace std;

// 判斷是否能夠找到一個合法的L，使得S1和S2都可以用Love做成。亦即
// S1 是 L 的倍數。
// S2 是 L 的倍數。
// L 是 S1 和 S2 的公因數。

// 利用輾轉相除法計算S1 和 S2 的最大公因數，如果大於 1 (只有一個位元的字串不合法)，表示有解。

int GCD(int a, int b){
    return b == 0 ? a : GCD(b, a % b);
}

int main() {
	int n, cnt = 1;
	cin >> n;
	while(n--) {
		string s1, s2;
		int n1 = 0, n2 = 0;
		cin >> s1 >> s2;
		for(int i=0; i<s1.length(); i++) {
			n1 *= 2;
			n1 += s1[i] - '0';
		}
		for(int i=0; i<s2.length(); i++) {
			n2 *= 2;
			n2 += s2[i] - '0';
		}
		if(GCD(n1, n2) != 1) cout << "Pair #" << cnt << ": All you need is love!" << endl;
		else cout << "Pair #" << cnt << ": Love is not all you need!" << endl;
		cnt ++;
	}
}
