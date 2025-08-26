#include<bits/stdc++.h>
using namespace std;

long long f[55];

int main() {
	//ios::sync_with_stdio(0), cin.tie(0);
	f[0] = 1;
	f[1] = 2;
	for(int i=2; i<55; i++) {
		f[i] = f[i-1] + f[i-2];
	}
	
	int n;
	while(cin >> n && n) {
		cout << f[n-1] << '\n';
	}
	
}
