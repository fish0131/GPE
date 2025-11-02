#include<bits/stdc++.h>
using namespace std;

int m, n, val;
string word, lines;

int main() {
	cin >> m >> n;
	unordered_map<string, int> dict;
	
    for(int i=0; i<m; i++) {
    	cin >> word >> val;
    	dict[word] = val;
	}
	
	getline(cin, lines);
	
	for(int i=0; i<n; i++) {
		long long total = 0;
		while(getline(cin, lines)) {
			if(lines == ".") break;
			stringstream ss(lines);
			while(ss >> word) {
				if(dict.count(word)) total += dict[word];
			}
		}
		cout << total << '\n';
	}
}
