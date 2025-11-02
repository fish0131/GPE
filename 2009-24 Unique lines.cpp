#include<bits/stdc++.h>
using namespace std;

long long GCD(long long a, long long b) {
	return b == 0 ? a : GCD(b, a % b);
}

int main() {
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		vector<pair<long long, long long>> pts(n);
		for(int i=0; i<n; i++) cin >> pts[i].first >> pts[i].second;
		
		set<tuple<long long, long long, long long>> lines; // set 自動幫忙做「重複判斷」
		
		for(int i=0; i<n; i++) {
			for(int j=i+1; j<n; j++) {
				long long x1 = pts[i].first, y1 = pts[i].second;
				long long x2 = pts[j].first, y2 = pts[j].second;
				
				long long A = y2 - y1;
				long long B = x1 - x2;
				long long C = -(A * x1 + B * y1);
				
				long long g = GCD(A, GCD(B, C));
				if(g != 0) {
					A /= g;
					B /= g;
					C /= g;
				}
				if(A < 0 || (A == 0 && B < 0)) {
					A = -A;
					B = -B;
					C = -C;
				}
				
				// 用 make_tuple 明確建構
				// tuple<long long,long long,long long> 沒有接受 {long long,long long,long long} 的 constructor
				lines.insert(make_tuple(A, B, C));
			}
		}
		cout << lines.size() << '\n';
	}
}
