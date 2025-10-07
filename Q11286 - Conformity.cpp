#include <bits/stdc++.h>
using namespace std;

int n;
int a[5];

int main() {
    while(cin >> n && n) {
    	map<long long, int> mp;
    	for(int i=0; i<n; i++) {
    		for(int j=0; j<5; j++) cin >> a[j];
    		sort(a, a+5);
    		long long course = 0LL;
    		for(int j=0; j<5; j++) {
    			course *= 1000;
    			course += a[j];
			}
			mp[course]++;
		}
		int mx = 0;
		for(auto i: mp) {
			if(i.second > mx) mx = i.second;
		}
		int ans = 0;
		for(auto i: mp) {
			if(i.second == mx) ans += i.second;
		}
		cout << ans << '\n';
	}
}
