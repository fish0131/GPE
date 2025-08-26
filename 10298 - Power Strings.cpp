#include<bits/stdc++.h>
using namespace std;

string s;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
    while(cin >> s && s != ".") {
    	int ans = 1;
    	int n = s.length();
    	for(int i=n; i>=1; i--) {
    		bool flag = true;
    		if(n % i == 0) {
    			string target = s.substr(0, i);
    			for(int j=i; j<n; j+=i) {
    				if(target != s.substr(j, i)) {
    					flag = false;
    					break;
					}
				}
				if(flag) ans = i;
			}
		}
		cout << n / ans << '\n';
	}
}

