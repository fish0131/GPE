#include<bits/stdc++.h>
using namespace std;

int a0;

int main() {
	while(cin >> a0 && a0) {
		set<int> seen;
		while(!seen.count(a0)) {
			seen.insert(a0);
			long long next = 1LL * a0 * a0; // 防止溢出
			a0 = (next / 100) % 10000;        // 取中間4位
		}
		cout << seen.size() << '\n';
	}
}
