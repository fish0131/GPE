#include<bits/stdc++.h>
using namespace std;

int n, a[20], cnt = 1;
long long ans, mul;

int main() {
	while(cin >> n) {
		for(int i=0; i<n; i++) cin >> a[i];
		ans = 0;
		for(int i=0; i<n; i++) {
			mul = 1;
			for(int j=i; j<n; j++) {
				mul *= a[j];
				if(mul > ans) ans = mul;
			}
		}
		cout << "Case #" << cnt++ << ": The maximum product is " << ans << "." << '\n' << '\n';
	}
}
