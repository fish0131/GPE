#include<bits/stdc++.h>
using namespace std;

int main() {
	int t, x;
	string line;
	cin >> t;
	getline(cin, line);
	while(t--) {
		getline(cin, line);
		
		if(line.empty()) continue;
		
		int total = 0;
		vector<int> package;
		
		stringstream ss(line);
		while(ss >> x) {
			package.push_back(x);
			total += x;
		}
		
		if(total % 2 != 0) {
			cout << "NO" << '\n';
			continue;
		}
		
		int target = total / 2;
		vector<bool> dp(target+1, false);
		dp[0] = true;
		
		for(int w: package) {
			for(int i=target; i>=w; i--) {
				if(dp[i-w]) dp[i] = true;
			} 
		}
		
		cout << (dp[target] ? "YES" : "NO") << '\n';
	}
}
