#include <bits/stdc++.h>
using namespace std;

// т砏 f(n) = 3f(n-1)+4 --> f(n) = 3^n - 2 

const long long MOD = 1e9 + 9;

long long n;

//  n  a^n mod m мォ --> е硉计 (Binary Exponentiation) ―家ㄧ计
long long modpow(long long a, long long b, long long mod) {
    long long res = 1;
    a %= mod; // 盢┏计癸家计緇磷 a 硑Θ犯
    while (b > 0) {
    	// 浪琩 b 程琌 1
        if (b & 1) res = (res * a) % mod;
        b >>= 1;  // 盢 b 簿 1  --> 讽埃 2
        a = (a * a) % mod;
    }
    return res;
} 

int main() {
	while(cin >> n) {
		long long f = (modpow(3, n, MOD) - 2 + MOD) % MOD;
        cout << f << '\n';
	}
}
