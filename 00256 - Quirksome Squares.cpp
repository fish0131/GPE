#include<bits/stdc++.h>
#include <iomanip>
using namespace std;

int n;

int main() {
	//ios::sync_with_stdio(0), cin.tie(0);
	int table[9] = {0, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
	
	while(cin >> n) {
		for(int i=0; i<table[n]; i++) {
			int r = i / table[n / 2] + i % table[n / 2];
			if(r * r == i) cout << setw(n) << setfill('0') << i << '\n';
		}
	}
}
