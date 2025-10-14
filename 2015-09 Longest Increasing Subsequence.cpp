#include<bits/stdc++.h>
using namespace std;

int n;

int main() {
	cin >> n;
	vector<int> nums(n);
	for(int i=0; i<n; i++) cin >> nums[i];
	
	if(nums.empty()) return 0;
	
	int longest = 1;
	int ns = nums.size();
	vector<int> dp(ns, 1);
	for(int i=1; i<n; i++) {
		for(int j=0; j<i; j++) {
			if(nums[i] > nums[j]) dp[i] = max(dp[i], dp[j]+1);
		}
		longest = max(longest, dp[i]);
	}
	cout << longest << '\n';
}
