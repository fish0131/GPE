#include <bits/stdc++.h>
using namespace std;

// 貪心 + 二分搜尋

int n, m;
int c[1001];

int container(int size, int value) {
	int sum = 0, cnt = 1;
	for(int i=0; i<n; i++) {
		if(c[i] > value) return size;
		else if(sum + c[i] > value) {
			sum = c[i];
			cnt++;
		}
		else sum += c[i];
	}
	return cnt;
}

int main() {
    while(cin >> n >> m) {
    	int sum = 0, maxn = 0;
    	for(int i=0; i<n; i++) cin >> c[i];
    	for(int i=0; i<n; i++) {
    		sum += c[i];
    		if(c[i] > maxn) maxn = c[i];
		}
		
		int l = maxn, r = sum, mid = 0;
		while(l < r) {
			mid = (l + r) / 2;
			if(container(n, mid) <= m) r = mid; // 當 container_size(...) <= m 時，代表容量 mid 足夠，可往左壓小範圍。
			else l = mid + 1;                   // 否則，容量不足 → 往右邊找。
		}
		cout << l << '\n';
	}
}
