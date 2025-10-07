#include <bits/stdc++.h>
using namespace std;

// �p�� �p(n)
long long phi(long long n) {
    long long ans = n;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i; // �h���]�� i
            ans = ans / i * (i - 1);
        }
    }
    if (n > 1) ans = ans / n * (n - 1); // �p�G�̫�Ѥ@�ӽ�]��
    return ans;
}

int main() {
    long long n;
    while (cin >> n && n) {
        cout << phi(n) << "\n";
    }
    return 0;
}
