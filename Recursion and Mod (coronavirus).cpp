#include <bits/stdc++.h>
using namespace std;

// ��W�� f(n) = 3f(n-1)+4 --> f(n) = 3^n - 2 

const long long MOD = 1e9 + 9;

long long n;

// �j n �� a^n mod m �ޥ� --> �ֳt���� (Binary Exponentiation) �D�Ҩ��
long long modpow(long long a, long long b, long long mod) {
    long long res = 1;
    a %= mod; // ���N���ƹ�Ҽƨ��l�A�קK a �ܤj�y������
    while (b > 0) {
    	// �ˬd b ���̧C��O�_�� 1
        if (b & 1) res = (res * a) % mod;
        b >>= 1;  // �N b �k�� 1 �� --> �۷�󰣥H 2
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
