#include<bits/stdc++.h>
using namespace std;

int n;
double x;

int main() {
	while(cin >> n && n) {
		int a[n], sum = 0;
		for(int i=0; i<n; i++) {
			cin >> x;
			a[i] = (int)round(x*100);
			sum += a[i];
		}
		sort(a, a+n);
		int avg = sum / n;
		int remain = sum % n;
		// 璶程てユ传肂êㄇセㄓ碞程 r 程や 1 窥
		double ans = 0.0;
		for (int i=n-1; i>=n-remain; i--){
            ans += abs(a[i] - avg - 1);
        }
        for (int i=n-remain-1; i>=0; i--){
            ans += abs(a[i] - avg);
        }
        cout << "$" << fixed << setprecision(2) << ans / 200 << '\n';
	}
}
