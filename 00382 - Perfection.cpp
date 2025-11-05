#include<bits/stdc++.h>
using namespace std;

string s[3] = {"PERFECT", "DEFICIENT", "ABUNDANT"};

int prime(int n) {
	vector<int> v;
	int sum = 0;
	for(int i=1; i<n; i++) {
		if(n % i == 0) v.push_back(i);
	}
	for(int i=0; i<v.size(); i++) {
		sum += v[i];
	}
	if(sum == n) return 0;
	else if(sum < n) return 1;
	else return 2;
}

int main() {
	int n;
	cout << "PERFECTION OUTPUT" << '\n';
	while(cin >> n) {
		if(n == 0) break;
		if(n == 1) cout << setw(5) << right << n << "  " << s[1] << '\n';
		else cout << setw(5) << right << n << "  " << s[prime(n)] << '\n';
	}
	cout << "END OF OUTPUT";
}
