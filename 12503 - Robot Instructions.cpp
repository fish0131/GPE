#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		string s;
		cin >> n;
		getline(cin, s); //clear buffer
		
		int a[n];
		for(int i=0; i<n; i++) {
			getline(cin, s);
			if(s == "LEFT") a[i] = -1;
			else if(s == "RIGHT") a[i] = 1;
			else {
				int idx = 0;
				for(int j=8; j<s.length(); j++) {
					idx *= 10;
					idx += s[j] - '0';
				}
				a[i] = a[idx-1];
			}
		}
		int pos = 0;
		for (auto p: a) pos += p;
		cout << pos << endl;
	}
	return 0;
}
