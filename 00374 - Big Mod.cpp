#include<bits/stdc++.h>
using namespace std;

long long bigmod(int b, int p, int m) {
	if(p == 0) return 1;
	else if(p == 1) return b % m;
	else {
		long long result = bigmod(b, p/2, m);
		if(p % 2 == 0) return result * result % m;
		else return result * result * b % m;
	}
}

int main() {
	long long b, p, m;
	while(cin >> b >> p >> m) {
		cout << bigmod(b, p, m) << endl;
	}
	return 0;
} 
