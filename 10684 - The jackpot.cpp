#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while(cin >> n && n) {
		int a[n];
		for(int i=0; i<n; i++) cin >> a[i];
		
		int mx = 0;
		int current = 0;
		
		for(int i=0; i<n; i++) {
			current = max(a[i], current + a[i]);
			mx = max(mx, current);
		}
		
		if(mx > 0) cout << "The maximum winning streak is " << mx << "." << '\n';
		else cout << "Losing streak." << '\n';
	}
}
